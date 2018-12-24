#pragma once
typedef struct node {
	struct node* prev;
	struct node* next;
	void * data;
	int key;
	int type;																//1-char 4-int
	int amount;																
}node_t;
typedef struct list {
	node_t * head, *tail;
}list_t;

list_t * create_list(void);
int insert_after_node(list_t *list,int key,int type,int amount,void * data);
node_t* search_place(list_t * list, int key);
int delete_node(list_t *list, int key);
int delete_list(list_t *list);
void iterator_list(list_t *list, void(*func)(node_t* node));
list_t * copy_list(list_t * list);
int insert_h_node(list_t *list, int key, int type, int amount, void * data);
int insert_t_node(list_t *list, int key, int type, int amount, void * data);
int delete_h_node(list_t*list);
int delete_t_node(list_t*list);

