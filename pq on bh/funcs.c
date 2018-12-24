#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include "funcs.h"
#include <string.h>
#include <assert.h>

bheap_t* bheap_new(int initial_data_size) {
	bheap_t *h = (bheap_t*)malloc(sizeof(bheap_t));
	assert(h != NULL);
	h->data = (node_t*)malloc(sizeof(node_t) * (1 + initial_data_size));
	assert(h->data != NULL);
	h->data_size = 1 + initial_data_size;
	h->size = 0;
	return h;
}
void bheap_delete(bheap_t *h) {
	if (h) {
		if (h->data) {
			free(h->data);
		}
		free(h);
	}
}
void bheap_checkup(bheap_t *h, int c) {
	int p;
	for (p = c / 2; p > 0; c = p, p = c / 2) {
		if (h->data[p].key < h->data[c].key) {
			node_t tmp = h->data[p]; h->data[p] = h->data[c]; h->data[c] = tmp;
		}
		else {
			break;
		}
	}
}
void bheap_checkdown(bheap_t *h, int p) {
	int c;
	for (c = 2 * p; c <= h->size; p = c, c = 2 * p) {
		if (c + 1 <= h->size && h->data[c + 1].key > h->data[c].key) c++;
		if (h->data[c].key > h->data[p].key) {
			node_t  tmp;
			tmp = h->data[c]; h->data[c] = h->data[p]; h->data[p] = tmp;
		}
		else {
			break;
		}
	}
}
void bheap_add(bheap_t *h, node_t v) {
	if (h->size + 1 >= h->data_size) {
		h->data_size *= 2;
		h->data = (node_t*)realloc(h->data, h->data_size * sizeof(node_t));
	}
	h->data[++(h->size)] = v;
	bheap_checkup(h, h->size);
}
int bheap_extract_max(bheap_t *h, node_t *v) {
	if (h->size == 0) return 0;
	*v = h->data[1];
	h->data[1] = h->data[(h->size)--];
	bheap_checkdown(h, 1);
	return 1;
}

void UI(void) {
	bheap_t* bheap = bheap_new(1);
	node_t node;
	int menu=1, decision1=0, decision2=0;
	char forshit[100],name[20];
	node.key = 0;
	strcpy(node.name, "");
	while (menu == 1) {
		puts("\n\n\t\tTODO LIST\n");
		puts("\t1.Add task\n");
		puts("\t2.What should I do?\n");
		puts("\t3.Exit\n\n\n");
		while (decision1 != 1 && decision1 != 2 && decision1 != 3) {
			fgets(forshit, 100, stdin);
			sscanf(forshit, "%d", &decision1);
			if (decision1 != 1 && decision1 != 2 && decision1 != 3) {
				puts("\tTRY AGAIN, INCORRECT ANSWER\n\n");
			}
		}
		if (decision1 == 1) {
			puts("\tPut priority and name\n\n");
			fgets(forshit, 100, stdin);
			sscanf(forshit, "%d", &(node.key));
			fgets(node.name, 20, stdin);
			bheap_add(bheap, node);
			
		}
		else if (decision1 == 2) {
			if (bheap_extract_max(bheap, &node)) {
				printf("\n\n\n\t\tYOUR TASK:");
				puts(node.name);
			}
			else puts("\n\n\t\tTODO LIST IS EMPTY\n\n");
		}
		else {
			bheap_delete(bheap);
			exit(-1);
		}
		decision1 = 0;
		
	}
	bheap_delete(bheap);
}