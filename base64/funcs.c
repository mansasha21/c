#define _CRT_SECURE_NO_WARNINGS
#include "Header.h";
char base64[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghigklmnopqrstuvwxyz0123456789+/" };

int FindNumber(char symbol) {
	int i = 0;
	for (i; i < 64; i++) {
		if (symbol == base64[i]) break;
	}
	return i;
}
void Encode(FILE *f1,FILE*f2)
{
	char c;                               //check EOF
	assert((f1 || f2) != NULL);
	
	
	do {
		char* three= (char*)calloc(4, sizeof(char));
		char* four = (char*)calloc(5, sizeof(char));

		fgets(three, 4, f1);
		c = three[0];
		if (c == '\n'||c=='\0') break;	
		ThreeToFour(three, four);
		fputs(four, f2);
		free(four);
		free(three);
		
	} while (1);
}

void Decode(FILE *f1, FILE *f2) {
	assert((f1 || f2) != NULL);
	char c;
	
	do {
		char* three = (char*)calloc(4, sizeof(char));
		char* four = (char*)calloc(5, sizeof(char));
		fgets(four, 5, f1);
		c = four[0];
		if (c == '\n' || c == '\0') break;
		FourToThree(three, four);
		fputs(three, f2);
		free(four);
		free(three);
	} while (1);
}
void ThreeToFour(char* three, char*four) {
	unsigned char a, b;
	four[0] = base64[(int)three[0] >> 2];
	a = three[0] << 6;
	b = three[1] >> 4;
	b = b << 2;
	a = a ^ b;
	four[1] = base64[(int)a / 4];

	a = three[1] << 4;
	a = a >> 2;
	b = three[2] >> 6;
	a = a ^ b;
	four[2] = base64[(int)a];
	a = three[2] << 2;
	four[3] = base64[(int)a / 4];
}
void FourToThree(char* three, char* four) {
	unsigned char a, b;
	a = FindNumber(four[0]);
	a = a << 2;
	b = FindNumber(four[1]);
	b = b >> 4;
	three[0] = a ^ b;
	a = FindNumber(four[1]) << 4;
	b = FindNumber(four[2]) <<2;
	b = b >> 4;
	three[1] = a ^ b;
	a = FindNumber(four[2]) << 6;
	b = FindNumber(four[3]);
	three[2] = a ^ b;

}