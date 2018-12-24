#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funcs.h"
#include <stdlib.h>
#include <string.h>
#include "UI.h"

void UI(void) {
	list_t* a = create_list();
	int menu = 1, decision1 = 0, decision2 = 0;
	char forshit[100], name[20];
	while (menu == 1) {
		puts("\n\n\t\tDoubly list\n");
		puts("\t1.Add node\n");
		puts("\t2.Delete node\n");
		puts("\t3.Show list\n");
		puts("\t4.Exit\n\n\n");
		while (decision1 != 1 && decision1 != 2 && decision1 != 3 && decision1 != 4) {
			fgets(forshit, 100, stdin);
			sscanf(forshit, "%d", &decision1);
			if (decision1 != 1 && decision1 != 2 && decision1 != 3 && decision1 != 4) {
				puts("\tTRY AGAIN, INCORRECT ANSWER\n\n");
			}
		}
		if (decision1 == 1) {
			int addtype = 0;
			int key1 = 0, type1 = 0, amount1 = 0;
			char *text = NULL;
			int* arr = NULL;
			puts("\tEnter key\n");
			fgets(forshit, 100, stdin);
			sscanf(forshit, "%d", &key1);
			puts("\tEnter  type of data(read doc)\n");
			fgets(forshit, 100, stdin);
			sscanf(forshit, "%d", &type1);
			puts("\tEnter  amount\n");
			fgets(forshit, 100, stdin);
			sscanf(forshit, "%d", &amount1);
			puts("\t Enter data \n");
			if (type1 == 1) {
				text = (char*)malloc(sizeof(char)*(++amount1));
				fgets(text, amount1, stdin);
			}
			else {
				arr = (int*)malloc(sizeof(int)*(amount1));
				for (int i = 0; i < amount1; i++) {
					scanf("%d", &arr[i]);
				}
			}
			puts("\tChoose add type\n");
			puts("\t1.To head\n");
			puts("\t2.To tail\n");
			puts("\t3.By key\n");
			puts("\t4.Back\n");
			fgets(forshit, 100, stdin);
			if (forshit[0] == '\n' || (forshit[0] < 48 || forshit[0] > 57)) {
				fgets(forshit, 100, stdin);
			}
			sscanf(forshit, "%d", &addtype);
			if (addtype == 1) {
				if (type1 == 1) {
					insert_h_node(a, key1, type1, amount1 + 1, text);
					free(text);
				}
				else {
					insert_h_node(a, key1, 4, amount1, arr);
					free(arr);
				}
			}
			else if (addtype == 2) {
				if (type1 == 1) {
					insert_t_node(a, key1, type1, amount1, text);
					free(text);
				}
				else {
					insert_t_node(a, key1, 4, amount1, arr);
					free(arr);
				}
			}
			else if (addtype == 3) {
				if (type1 == 1) {
					insert_after_node(a, key1, type1, amount1, text);
					free(text);
				}
				else {
					insert_after_node(a, key1, 4, amount1, arr);
					free(arr);
				}
			}
			else {

			}
		}
		else if (decision1 == 2) {
			int deletetype = 0;
			puts("\tChoose delete type\n");
			puts("\t1.From head\n");
			puts("\t2.From tail\n");
			puts("\t3.By key\n");
			puts("\t4.Back\n");
			fgets(forshit, 100, stdin);
			sscanf(forshit, "%d", &deletetype);
			if (deletetype == 1) {
				delete_h_node(a);
				if (delete_h_node == 1) puts("Empty!");
			}
			else if (deletetype == 2) {
				delete_t_node(a);
			}
			else if (deletetype == 3) {
				int key = 0;
				puts("\tEnter key\n");
				fgets(forshit, 100, stdin);
				sscanf(forshit, "%d", &key);
				delete_node(a, key);
			}
			else {

			}
		}
		else if (decision1 == 3) {
			iterator_list(a, print_node);
		}
		else {
			delete_list(a);
			exit(-1);
		}
		decision1 = 0;

	}
	delete_list(a);
}
void print_node(node_t* node) {
	printf("\t\t\t\tKEY = %d\n", node->key);
	if (node->type == 1) {
		printf("\t\t\tDATA: %s\n", (char*)node->data);
	}
	else {
		printf("\t\t\tDATA: ");
		for (int i = 0; i < node->amount; i++) {
			printf("%d ", *((int*)node->data + i));
		}
		printf("\n");
	}
}