//§®§Ö§ä§à§Õ §á§â§ñ§Þ§à§Ô§à §Ó§Ü§Ý§ð§é§Ö§ß§Ú§ñ
//Ö±½Ó²åÈëÅÅÐò
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void exchange(int* a, int* b);
void insertSort(int* arr, int length);

int main() {
	int arr[50];
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	insertSort(arr, 50);
	printf("Insert sort:\n");
	for (int i = 0; i < 50; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

void insertSort(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		int j = i;
		while (arr[j]<arr[j-1] && j > 0) {
			exchange(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}

void exchange(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
