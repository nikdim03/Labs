#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// deque
typedef struct DQ {
  int data;
  struct DQ *prev, *next;
} DQ;
DQ *dq_head = NULL, *dq_tail = NULL;

// sequence
typedef struct SQ {
  DQ* data;
  struct SQ* next;
} SQ;
SQ* sq_head = NULL;

// sentance
typedef struct ST {
  SQ* data;
  struct ST* next;
} ST;
ST* st_head = NULL;

//-------------------------------------------DEQUE-------------------------------------------------
void dq_menu();
DQ* create_dq(int data);
void dq_init();
void dq_deinit();
void dq_push_front(int data);
void dq_push_back(int data);
void dq_pop_front();
void dq_pop_back();
void dq_display();
//-------------------------------------------SEQUENCE----------------------------------------------
void sq_menu();
void free_sq(SQ* head);
SQ* sq_remove_after(SQ* one, SQ* two);
SQ* create_sq();
void print_sq(SQ* head, SQ* cur);
void sq_start(bool* sl);
void sq_clear(SQ** head, SQ** cur);
bool sq_is_empty(SQ* head);
void sq_set_to_start(SQ* head, SQ** cur);
bool sq_is_end(SQ* cur);
void sq_shift_forward(SQ** cur);
void sq_print_after(SQ* cur);
void sq_remove_elem(SQ** cur);
void sq_return_after(SQ** cur);
void sq_modify_after(SQ* head, SQ** cur);
void sq_add_after(SQ** head, SQ** cur);
void sq_stop(SQ** head, SQ** cur, bool* sl);
//-------------------------------------------SENTENCE----------------------------------------------
void st_menu();
void free_st(ST* head);
ST* st_remove_after(ST* one, ST* two);
ST* create_st();
void print_st(ST* head, ST* cur);
void st_start(bool* s_st);
void st_clear(ST** head, ST** cur);
bool st_is_empty(ST* head);
void st_set_to_start(ST* head, ST** cur);
bool st_is_end(ST* cur);
void st_shift_right(ST** cur);
void st_print_after(ST* cur);
void st_remove_elem(ST** cur);
void st_return_after(ST** cur);
void st_modify_after(ST* head, ST** cur);
void st_add_after(ST** head, ST** cur);
void st_stop(ST** head, ST** cur, bool* sl);

void exit_program(bool sl);