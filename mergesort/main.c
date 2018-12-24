#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int test(void* a, void* ar,int count,int size) {
	for (int i = 0; i < count; i++) {
		switch (size)
		{
		case 4:
			if (*(int*)((char*)a + i * size) != *(int*)((char*)ar + i * size))
				return -1;
			break;
		case 1:
			if (*((char*)a + i * size) != *((char*)ar + i * size))
			return -1;
			break;
		case 8:
			if (*((double*)a + i * size) - *((double*)ar + i * size)>0.001&&*((double*)a + i * size) - *((double*)ar + i * size) <-0.001) return -1;
			break;
		default:
			break;
		}
	}
	return 0;
}
void print(const void *a, int count,int size) {
	switch (size)
	{
		case 4:
			for (int i = 0; i < count; i++) {
				printf("%d ", *((char*)a +i*size));
			}
			printf("\n");
			break;
		case 1:
			for (int i = 0; i < count; i++) {
				printf("%c ", *((char*)a + i * size));
			}
			printf("\n");
			break;
		case 8:
			for (int i = 0; i < count; i++) {
				printf("%1.2lf ", *((double*)((char*)a + i * size)));
			}
			printf("\n");
			break;


	default:
		break;
	}
}
main() {
	double arr[] = { 55,111,120,93,84 };
	double arr1[] = { 55,84,93,111,120 };
	char brr[] = { 55,111,120,93,94,84 };
	char brr1[] = { 55,84,93,94,111,120 };
	int crr[] = { 55,111,123,120,93,94,84 };
	int crr1[] = { 55,84,93,94,111,120,123 };
	print(brr, 6, 1);
	mergesort(arr, 5, sizeof(double), cmp_double);
	mergesort(brr, 6, sizeof(char), cmp_char);
	mergesort(crr, 7, sizeof(int), cmp_int);
	print(brr,6,1);
	assert(test(arr, arr1, 5, sizeof(double))==0);
	//assert(test(brr, brr1, 6, sizeof(char)) == 0);
	assert(test(crr, crr1, 7, sizeof(int)) == 0);


	

	
	getch();
}