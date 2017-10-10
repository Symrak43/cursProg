#include "sort.h"
#include <sys/time.h>
#include <math.h>
#include <stdio.h>

void Heap(int *mas, int l, int r) {
    int x = mas[l], i = l, j;
    while(1){
    	j = 2 * i;
    	if (j > r) break;
    	if ( (j < r) && (mas[j+1] >= mas[j]) ) j++;
        if (x >= mas[j]) break;
        mas[i] = mas[j];
        i = j;      
    }
    mas[i] = x;
}
void HeapSort(int *mas, int n) {
    int l = n / 2;
    int k;
    while (l >= 0) {
        Heap(mas, l, n-1);
        l--;
    }
    int r = n;
    while (r > 0) {
        k = mas[0];
        mas[0] = mas[r-1];
        mas[r-1] = k;
        r--;
        Heap(mas, 0, r-1);
    }
}

void SortInsertion(int *mas, int n){
 	int i, j, key;
 	for(i = 1; i < n; i++){
    	key = mas[i];
	    for(j = i; (j > 0) && (mas[j-1] > key); j--)
	    	mas[j] = mas[j-1];
    	mas[j] = key;
	}
}

