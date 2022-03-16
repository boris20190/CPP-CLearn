//§®§Ö§ä§à§Õ§í §á§â§ñ§Þ§à§Ô§à §Ó§í§Ò§à§â§Ñ
//Ö±½ÓÑ¡ÔñÅÅÐò
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int get_min(int* arr, int start, int length);
void exchange(int* a, int* b);
void selectSort(int* arr, int length);

int main() {
	int arr[50];
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	selectSort(arr, 50);
	for (int i = 0; i < 50; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void selectSort(int* arr, int length) {
	int imin;
	for (int i = 0; i < length; i++) {
		imin = get_min(arr, i, length);
		exchange(&arr[imin], &arr[i]);
	}
}

int get_min(int* arr, int start, int length) {
	int imin = start;
	for (int i = start; i < length; i++) {
		imin = arr[imin] < arr[i] ? imin : i;
	}
	return imin;
}

void exchange(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}