#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int* arr, int length);

int main() {
	int arr[50];
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubbleSort(arr, 50);
	for (int i = 0; i < 50; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void bubbleSort(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (arr[i] > arr[j]) {
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
	}
}