#include<stdio.h>
#include<stdlib.h>

void allSubSet(int* arr, int size) {
	int length = 1 << size;
	for (int i = 0; i < length; i++) {
		printf("{ ");
		int j = i;
		int k = 0;
		while (j) {
			if (j & 1) {//j是奇数符合if,是偶数不符合if
				printf("%d ", arr[k]);
			}
			k++;
			j >>= 1;//j = j/2;
		}
		printf("}\n");
	}
}

int main() {
	int size;
	printf("Enter size of set:\n");
	scanf("%d", &size);
	int* arr = (int*)malloc(sizeof(int) * size);
	//输入总集
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	allSubSet(arr, size);
	return 0;
}