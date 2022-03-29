#ifndef __YSF_QUEUE3_H__
#define __YSF_QUEUE3_H__

#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include <Logger.h>
#include <ysf_list.h>

typedef bool (*match_fn_data)(void *data, void *user_data, void *match_data);
typedef void (*release_data_fn)(void* data, void *user_data);
typedef bool (*match_fn)(void *data, void *user_data);

class ysf_queue3 {
public:
    ysf_queue3();
    ysf_queue3(release_data_fn data_rel_fn, void *user_data);
    virtual ~ysf_queue3();
    bool enqueue(void *data);
    bool enqueueWithPriority(void *data);
    void flush();
    void flushNodes(match_fn match);
    void flushNodes(match_fn_data match, void *spec_data);
    void* dequeue(bool bFromHead = true);
    bool isEmpty();
private:
    typedef struct {
        struct ysf_list list;
        void* data;
    } ysf_node;

    ysf_node m_head; // dummy head
    int m_size;
    pthread_mutex_t m_lock;
    release_data_fn m_dataFn;
    void * m_userData;
};

#endif