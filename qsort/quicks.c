#include <stdio.h>
int compare(int a, int b) {
	if (a > b)return 1;
	else if (a == b) return 0;
	else return -1;
}
void swap(int* a,int*b) {
	int c = *a;
	*a = *b;
	*b = c;
}
int test(int* a, int*b,int size) {
	
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i]) return 1;
	}
	return 0;
}
void int_qsort(int *arr, int count) {
	if (count > 1) {                                  // check empty
		int left = 0, right = count-1, pivot = arr[0];
		do {
			while (arr[left]<=pivot && left<count) left++;
			while (arr[right] >= pivot && right>0) right--; 
			if (right>left) {
				swap(&arr[right], &arr[left]);
			}

		} while (left<right);
		swap(&arr[right], &arr[0]);
		if (right > 0) int_qsort(arr, right + 1);
		if (count - left > 0) int_qsort(arr+left, count - left);
	}
}
