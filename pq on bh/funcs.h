#pragma once
typedef struct {
	int  key;
	char name[20];
} node_t;

typedef struct {
	node_t *data;
	int size;
	int data_size;
} bheap_t;

bheap_t* bheap_new(int initial_data_size);
void bheap_delete(bheap_t *h);
void bheap_checkup(bheap_t *h, int c);
void bheap_checkdown(bheap_t *h, int p);
void bheap_add(bheap_t *h, node_t v);
int bheap_extract_max(bheap_t *h, node_t *v);
void UI(void);