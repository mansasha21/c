#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double cmp_double(const void* a, const void* b)
{
	return *(double*)b - *(double*)a;
}
double cmp_char(const void* a, const void* b)
{
	return *(char*)b - *(char*)a;
}
double cmp_int(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}

void mergesort(const void *ptr, int count, int size, double(*cmp)(const void* a, const void* b)) {
	if (count<=1) {
		return;
	}
	int mid = count / 2;
	int right_size = count - mid;
	mergesort(ptr, mid, size, cmp);
	mergesort((char*)ptr+mid*size, right_size, size, cmp);
	void * arr = (void*)malloc(size*count);
	int  left = 0, right = mid;
	for (int i = 0; i < count; i++) {
		if (cmp((char*)ptr+left*size, (char*)ptr+size*right) <0) {

			memcpy((char*)arr + i * size, (char*)ptr + right * size, size);
			right++;
		}
		else {
			
			memcpy((char*)arr + i * size, (char*)ptr + left * size, size);
			left++;
		}
		if (left >= (mid)) {
			for (i=i+1; i < count; i++, right++) {
				
				memcpy((char*)arr + i * size, (char*)ptr + right * size, size);
			}
		}
		if (right >= (count)&&(i+1)<count) {
			for (i = i + 1; i < count; i++, left++) {
			//i = i + 1;
				memcpy((char*)arr + i * size, (char*)ptr + left * size, size);
			}
		}
	}
	
	memcpy((char*)ptr, (char*)arr,count*size);
	free(arr);
}
