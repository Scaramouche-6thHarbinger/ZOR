#ifndef __YSF_LIST_H__
#define __YSF_LIST_H__

#include <stddef.h>

#define member_of(ptr, type, member) ({ \
  const typeof(((type *)0)->member) *__mptr = (ptr); \
  (type *)((char *)__mptr - offsetof(type,member));})

struct ysf_list {
  struct ysf_list *next, *prev;
};

static inline void ysf_list_init(struct ysf_list *ptr) {
  ptr->next = ptr;
  ptr->prev = ptr;
}

static inline void ysf_list_add_tail_node(struct ysf_list *item, struct ysf_list *head) {
  struct ysf_list *prev = head->prev;

  head->prev = item;
  item->next = head;
  item->prev = prev;
  prev->next = item;
}

static inline void ysf_list_insert_before_node(struct ysf_list *item, struct ysf_list *node) {
  item->next = node;
  item->prev = node->prev;
  item->prev->next = item;
  node->prev = item;
}

static inline void ysf_list_del_node(struct ysf_list *ptr) {
  struct ysf_list *prev = ptr->prev;
  struct ysf_list *next = ptr->next;

  next->prev = ptr->prev;
  prev->next = ptr->next;
  ptr->next = ptr;
  ptr->prev = ptr;
}

#endif // __YSF_LIST_H__