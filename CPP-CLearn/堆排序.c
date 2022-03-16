//������ڧ��ӧܧ� �� ���ާ���� �էӧ�ڧ�ߧ�ԧ� �է֧�֧ӧ�
//�ö���������--������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b);
int exchange(int count, int fre);
void heapSort_core(int* arr, int fre, int length);
void heapSort(int* arr, int length);

int main() {
	int arr[50];
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		arr[i] = rand()%100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	heapSort(arr, 50);
	for (int i = 0; i < 50; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
//��Ϊ��С������, ��������Ҫ>��<
void heapSort_core(int* arr, int fre, int length) {//fre--����ִ�д���, length--���鳤��
	for (int count = (length-fre+1)/2; count > 0; count--) {//count--��СΪ1, ���еĵڼ���Ԫ��		//��Ҫ���������±�cod��count֮���ӳ���ϵ
		int cod_1 = exchange(count, fre);
		int cod_2 = exchange(count * 2, fre);
		int cod_3 = exchange(count * 2 + 1, fre);
		if (arr[cod_1] > arr[cod_2]) {//�Ƚ����ӽ��
			swap(&arr[cod_1], &arr[cod_2]);
		}
		if (cod_3 <= length - 1 && arr[cod_1] > arr[cod_3]) {
			swap(&arr[cod_1], &arr[cod_3]);
		}
	}
}
//����������ʽ��������, ͳһΪ��������ͳ��ȵ������ʽ
void heapSort(int* arr, int length) {
	for (int i = 1; i <= length; i++) {
		heapSort_core(arr, i, length);
	}
}

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
//�����±�cod�Ͷ�Ԫ�����count֮���ӳ���ϵ:
int exchange(int count, int fre) {
	return count + fre - 2;
}
