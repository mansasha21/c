#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funcs.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int check(list_t* list) {
	if ((list->head != NULL)&& (list->head == list->tail)&&(list->head->next!=NULL||list->tail->prev!=NULL)) return 1;
	if (list->head == NULL&&list->tail!=NULL|| list->head != NULL && list->tail == NULL) return 1;
	return 0;
}
list_t * create_list(void) {
	list_t * list = (list_t*)malloc(sizeof(list_t));
	if (list == NULL) return NULL;
	if (list == NULL) {
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;
	return list;
}
int insert_after_node(list_t *list,int key, int type, int amount, void * data) {                                                    //if node not founded insert in tail
	assert(check(list) == 0);
	if (list->head==NULL) {																											//key become key++
		node_t *newhead = (node_t *)malloc(sizeof(node_t));
		if (newhead == NULL) return 1;
		newhead->data = (char*)malloc(sizeof(char)*type*amount);
		memcpy(newhead->data, data, type*amount);
		newhead->key = key;
		newhead->next = NULL;
		newhead->prev = NULL;
		newhead->type = type;
		newhead->amount = amount;
		list->head = newhead;
		list->tail = newhead;
	}
	else {
		node_t* node = search_place(list, key), *insnode = (node_t *)malloc(sizeof(node_t));
		insnode->data= (char*)malloc(sizeof(char)*type*amount);
		if (insnode == NULL) return 1;
		memcpy(insnode->data, data, type*amount);
		insnode->key = ++key;
		insnode->prev = node;
		insnode->next = node->next;
		insnode->amount = amount;
		insnode->type = type;
		node->next = insnode;
		if (insnode->next == NULL) {
			list->tail = insnode;
		}
		else insnode->next->prev = insnode;
	}
	return 0;

}
node_t* search_place(list_t * list, int key) {                        //search place for insert after(search node with key)
	assert(check(list) == 0);
	node_t * node = list->head;
	while (node->key != key) {
		if (node->next == NULL) {
			return node;
		}
		node = node->next;
	}
	return node;
	
}
int delete_node(list_t *list, int key) {								//delete node with key
	node_t *cmp = list->head;
	assert(check(list) == 0);
	while (cmp != NULL) {
		if (cmp->key == key) {
			if (cmp->prev) {
				cmp->prev->next = cmp->next;
				if (!cmp->next) {
					list->tail = cmp->prev;
				}
				else {
					cmp->next->prev = cmp->prev;
				}
			}
			else {
				if (cmp->next) {
					list->head = cmp->next;
					cmp->next->prev = NULL;
				}
				else {
					list->head = NULL;
					list->tail = NULL;
				}
			}
			free(cmp->data);
			free(cmp);
			return 0;
		}
		else cmp = cmp->next;
	}
	return 1;
}
int delete_list(list_t *list) {
	assert(check(list) == 0);
	if (list->head==NULL) {
		free(list);
		return 0;
	}
	else {
		node_t* dlnode;
		while (list->head != NULL) {
			dlnode = list->head;
			list->head = list->head->next;
			free(dlnode->data);
			free(dlnode);
		}
		free(list);
		return 0;
	}
}
void iterator_list(list_t *list, void(*func)(node_t* node)) {
	node_t* node = list->head;
	int i = 0;
	while (node != NULL) {
		i++;
		func(node);
		node = node->next;
	}
}

list_t* copy_list(list_t* list) {
	assert(check(list) == 0);
	list_t * newlist = create_list();
	node_t* node = list->head;
	while (node != NULL) {
		insert_after_node(newlist, node->key,node->type,node->amount,node->data);
		node = node->next;
	}
	return newlist;
}
int insert_h_node(list_t *list,int key, int type, int amount, void * data) {
	assert(check(list) == 0);
	node_t* new_head = (node_t*)malloc(sizeof(node_t));
	if (new_head == NULL) return 1;
	new_head->next = list->head;
	if (list->head) {
		list->head->prev = new_head;
	}
	else {
		list->tail = new_head;
	}
	new_head->prev = NULL;
	new_head->data = (char*)malloc(sizeof(char)*type*amount);
	if (new_head->data == NULL) return 1;
	memcpy(new_head->data, data, type*amount);
	new_head->key = key;
	new_head->amount = amount;
	new_head->type = type;
	list->head = new_head;
	return 0;
}
int insert_t_node(list_t *list, int key, int type, int amount, void * data) {
	assert(check(list) == 0);
	node_t* new_tail = (node_t*)malloc(sizeof(node_t));
	if (new_tail == NULL) return 1;
	new_tail->next = NULL;
	new_tail->prev = list->tail;
	new_tail->key = key;
	new_tail->amount = amount;
	new_tail->type = type;
	new_tail->data = (char*)malloc(sizeof(char)*type*amount);
	if (new_tail->data == NULL) return 1;
	memcpy(new_tail->data, data, type*amount);
	if (list->tail) {
		list->tail->next = new_tail;
	}
	else {
		list->head = new_tail;
	}
	list->tail = new_tail;
	return 0;
}
int delete_t_node(list_t*list) {
	assert(check(list) == 0);
	if (list->tail == NULL) {
		return 1;
	}
	else if (list->head == list->tail) {
		free(list->head->data);
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		list->tail = list->tail->prev;
		free(list->tail->next->data);
		free(list->tail->next);
		list->tail->next = NULL;
	}
	return 0;
}
int delete_h_node(list_t*list) {
	assert(check(list) == 0);
	if (list->head == NULL) {
		return 1;
	}
	else if (list->head == list->tail) {
		free(list->head->data);
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		list->head = list->head->next;
		free(list->head->prev);
		list->head->prev = NULL;
	}
	return 0;
}

