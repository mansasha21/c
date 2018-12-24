//#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
int FindNumber(char a);
void Encode(FILE* f1,FILE*f2);
void Decode(FILE *f1, FILE *f2);
void ThreeToFour(char* three, char*four);
void FourToThree(char* three, char* four);

