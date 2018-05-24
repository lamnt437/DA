#include <stdio.h>

typedef int Element;

void swap(Element *a, Element *b);

int partition(Element arr[], int l, int r, int pivot_index);

void quickSort(Element arr[], int l, int r);