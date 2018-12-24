#include "funcs.h"
#include <stdio.h>

int ins_test_i(int*arr, int size, node_t *node) {
	for (int i = 0; i < size; i++) {
		if (node == NULL) {
			return 1;
		}
		else if (*((int*)node->data + i) != arr[i]) {
			return 1;
		}
	}
	return 0;
}
int ins_test_c(char*arr, int size, node_t *node) {
	for (int i = 0; i < size; i++) {
		if (node == NULL) {
			return 1;
		}
		else if (*((char*)node->data + i) != arr[i]) {
			return 1;
		}
	}
	return 0;
}
int del_test(list_t* list, int size) {
	int i = 0;
	node_t* node = list->head;
	while (node != NULL) {
		i++;
		node = node->next;
	}
	if (i == size) {
		return 0;
	}
	else {
		return 1;
	}
}
int copy_test(list_t* a, list_t* b) {
	node_t* n1 = a->head, *n2 = b->head;
	while (n1 != NULL || n2 != NULL) {
		if (n1 == NULL || n2 == NULL) {
			return 1;
		}
		else if (ins_test_c((char*)n1->data, n1->amount, n2) != 0) {
			return 1;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	return 0;
}

void test() {
	list_t * a = create_list();
	list_t * b = create_list();
	int arr[3] = { 1,2,3 };
	char arr1[3] = { '1','2','3' };
	insert_after_node(a, 1, 4, 3, arr1);
	if (ins_test_i(arr1, 3, a->head) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	delete_h_node(a);
	if (del_test(a, 0) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	insert_h_node(a, 1, 4, 3, arr1);
	if (ins_test_i(arr1, 3, a->head) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	delete_t_node(a);
	if (del_test(a, 0) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	insert_t_node(a, 1, 4, 3, arr1);
	if (ins_test_i(arr1, 3, a->head) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	delete_node(a, 1);
	if (del_test(a, 0) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	insert_h_node(a, 1, 1, 3, arr);
	if (ins_test_c(arr, 3, a->head) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	b = copy_list(a);
	if (copy_test(a,b) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	delete_h_node(a);
	if (del_test(a, 0) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	delete_t_node(a);
	if (del_test(a, 0) == 0) {
		puts("Test completed\n");
	}
	else {
		puts("Test failed");
	}
	delete_list(a);
	delete_list(b);
}