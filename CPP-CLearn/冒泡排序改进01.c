//���flag��ֹ����ı���
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
//ΪʲôҪfor(j--)�Ӻ���ǰ��, ���ܺ�֮ǰһ����ǰ������?
//˼����һ���û�����Ϊɶ. ֮��������
void bubbleSort(int* arr, int length) {
	int flag = 1;
	for (int i = 0;flag && i < length; i++) {
		flag = 0;
		for (int j = length - 1; j >= i; j--) {
			if (arr[j] < arr[j - 1]) {
				flag = 1;
				arr[j] ^= arr[j - 1];
				arr[j - 1] ^= arr[j];
				arr[j] ^= arr[j - 1];
			}
		}
	}
}