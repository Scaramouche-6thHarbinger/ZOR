#ifndef __YSF_SEM_H__
#define __YSF_SEM_H__

#include <pthread.h>

typedef struct {
    int val;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} ysf_semaphore_t;

static inline void ysf_sem_init(ysf_semaphore_t *s, int n)
{
    pthread_mutex_init(&(s->mutex), NULL);
    pthread_cond_init(&(s->cond), NULL);
    s->val = n;
}

static inline void ysf_sem_post(ysf_semaphore_t *s)
{
    pthread_mutex_lock(&(s->mutex));
    s->val++;
    pthread_cond_signal(&(s->cond));
    pthread_mutex_unlock(&(s->mutex));
}

static inline int ysf_sem_wait(ysf_semaphore_t *s)
{
    int rc = 0;
    pthread_mutex_lock(&(s->mutex));
    while (s->val == 0)
        rc = pthread_cond_wait(&(s->cond), &(s->mutex));
    s->val--;
    pthread_mutex_unlock(&(s->mutex));
    return rc;
}

static inline void ysf_sem_destroy(ysf_semaphore_t *s)
{
    pthread_mutex_destroy(&(s->mutex));
    pthread_cond_destroy(&(s->cond));
    s->val = 0;
}

#endif /* ysf_sem_h */