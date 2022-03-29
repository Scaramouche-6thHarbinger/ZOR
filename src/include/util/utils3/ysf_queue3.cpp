#include <ysf_queue3.h>

ysf_queue3::ysf_queue3() {
    pthread_mutex_init(&m_lock, NULL);
    ysf_list_init(&m_head.list);
    m_size = 0;
    m_dataFn = NULL;
    m_userData = NULL;
}

ysf_queue3::ysf_queue3(release_data_fn data_rel_fn, void *user_data) {
    pthread_mutex_init(&m_lock, NULL);
    ysf_list_init(&m_head.list);
    m_size = 0;
    m_dataFn = data_rel_fn;
    m_userData = user_data;
}

ysf_queue3::~ysf_queue3() {
    flush();
    pthread_mutex_destroy(&m_lock);
}

bool ysf_queue3::isEmpty() {
    bool flag = true;
    pthread_mutex_lock(&m_lock);
    if (m_size > 0) {
        flag = false;
    }
    pthread_mutex_unlock(&m_lock);
    return flag;
}

bool ysf_queue3::enqueue(void *data) {
    ysf_node *node =
        (ysf_node *)malloc(sizeof(ysf_node));
    if (NULL == node) {
        LOGE("%s: No memory for ysf_node", __func__);
        return false;
    }

    memset(node, 0, sizeof(ysf_node));
    node->data = data;

    pthread_mutex_lock(&m_lock);
    ysf_list_add_tail_node(&node->list, &m_head.list);
    m_size++;
    pthread_mutex_unlock(&m_lock);
    return true;
}

bool ysf_queue3::enqueueWithPriority(void *data) {
    ysf_node *node =
        (ysf_node *)malloc(sizeof(ysf_node));
    if (NULL == node) {
        LOGE("%s: No memory for ysf_node", __func__);
        return false;
    }

    memset(node, 0, sizeof(ysf_node));
    node->data = data;

    pthread_mutex_lock(&m_lock);
    struct ysf_list *p_next = m_head.list.next;

    m_head.list.next = &node->list;
    p_next->prev = &node->list;
    node->list.next = p_next;
    node->list.prev = &m_head.list;

    m_size++;
    pthread_mutex_unlock(&m_lock);
    return true;
}

void* ysf_queue3::dequeue(bool bFromHead) {
    ysf_node* node = NULL;
    void* data = NULL;
    struct ysf_list *head = NULL;
    struct ysf_list *pos = NULL;

    pthread_mutex_lock(&m_lock);
    head = &m_head.list;
    if (bFromHead) {
        pos = head->next;
    } else {
        pos = head->prev;
    }
    if (pos != head) {
        node = member_of(pos, ysf_node, list);
        ysf_list_del_node(&node->list);
        m_size--;
    }
    pthread_mutex_unlock(&m_lock);

    if (NULL != node) {
        data = node->data;
        free(node);
    }

    return data;
}

void ysf_queue3::flush(){
    ysf_node* node = NULL;
    struct ysf_list *head = NULL;
    struct ysf_list *pos = NULL;

    pthread_mutex_lock(&m_lock);
    head = &m_head.list;
    pos = head->next;

    while(pos != head) {
        node = member_of(pos, ysf_node, list);
        pos = pos->next;
        ysf_list_del_node(&node->list);
        m_size--;

        if (NULL != node->data) {
            if (m_dataFn) {
                m_dataFn(node->data, m_userData);
            }
            free(node->data);
        }
        free(node);

    }
    m_size = 0;
    pthread_mutex_unlock(&m_lock);
}

void ysf_queue3::flushNodes(match_fn match) {
    ysf_node* node = NULL;
    struct ysf_list *head = NULL;
    struct ysf_list *pos = NULL;

    if ( NULL == match ) {
        return;
    }

    pthread_mutex_lock(&m_lock);
    head = &m_head.list;
    pos = head->next;

    while(pos != head) {
        node = member_of(pos, ysf_node, list);
        pos = pos->next;
        if (match(node->data, m_userData)) {
            ysf_list_del_node(&node->list);
            m_size--;

            if (NULL != node->data) {
                if (m_dataFn) {
                    m_dataFn(node->data, m_userData);
                }
                free(node->data);
            }
            free(node);
        }
    }
    pthread_mutex_unlock(&m_lock);
}

void ysf_queue3::flushNodes(match_fn_data match, void *match_data) {
    ysf_node* node = NULL;
    struct ysf_list *head = NULL;
    struct ysf_list *pos = NULL;

    if ( NULL == match ) {
        return;
    }

    pthread_mutex_lock(&m_lock);
    head = &m_head.list;
    pos = head->next;

    while(pos != head) {
        node = member_of(pos, ysf_node, list);
        pos = pos->next;
        if ( match(node->data, m_userData, match_data) ) {
            ysf_list_del_node(&node->list);
            m_size--;

            if (NULL != node->data) {
                if (m_dataFn) {
                    m_dataFn(node->data, m_userData);
                }
                free(node->data);
            }
            free(node);
        }
    }
    pthread_mutex_unlock(&m_lock);
}