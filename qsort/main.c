#include "Header.h"
int get_rand_range_int(const int min, const int max) {
	return rand() % (max - min + 1) + min;
}

main() {
	
	int *c = (int*)malloc(50000000 * sizeof(int));
	for (int i=0; i < 50000000; i++) {
		c[i] = get_rand_range_int(0, 100);
	}

	int_qsort(c, 50000000);
	free(c);
	return 0;

	
}
	
