#pragma once
void mergesort(const void *ptr, int count, int size, double(*cmp)(const void* a,const void* b));
double cmp_int(const void* a, const void* b);
double cmp_char(const void* a, const void* b);
double cmp_double(const void* a, const void* b);
