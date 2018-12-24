#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

int main(int Argc,char**Argv) {
	FILE *f1, *f2;
	char name1[20], name2[20];
	int type;
	if (Argc != 4) {
		printf("Enter files names and code(1) or decode(2)\n");
		fgets(name1, 20, stdin);
		fgets(name2, 20, stdin);
		scanf("%d", &type);
		f1 = fopen(name1, "r+t");
		f2 = fopen(name2, "r+t");
	}
	else {
		
		sscanf(Argv[3], "%d", &type);
		if (type != 1 && type != 2) {
			scanf("%d", &type);
		}
	}
	assert(type == 1 || type == 2);
	if (type == 1) {
		f1 = fopen("katyamraz.txt", "r+t");
		f2 = fopen("katyamrazB.txt", "w+t");
		Encode(f1, f2);
	}
	else {
		f1 = fopen("katyamraz.txt", "w+t");
		f2 = fopen("katyamrazB.txt", "r+t");
		Decode(f2, f1);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}