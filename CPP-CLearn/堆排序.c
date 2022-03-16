//Сортировка с помощью двоичного дерева
//用二叉树排序--堆排序
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
//现为从小到大排, 反过来需要>变<
void heapSort_core(int* arr, int fre, int length) {//fre--函数执行次数, length--数组长度
	for (int count = (length-fre+1)/2; count > 0; count--) {//count--最小为1, 堆中的第几个元素		//需要建立数组下标cod和count之间的映射关系
		int cod_1 = exchange(count, fre);
		int cod_2 = exchange(count * 2, fre);
		int cod_3 = exchange(count * 2 + 1, fre);
		if (arr[cod_1] > arr[cod_2]) {//比较左孩子结点
			swap(&arr[cod_1], &arr[cod_2]);
		}
		if (cod_3 <= length - 1 && arr[cod_1] > arr[cod_3]) {
			swap(&arr[cod_1], &arr[cod_3]);
		}
	}
}
//单纯美化格式化排序函数, 统一为输入数组和长度的输入格式
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
//数组下标cod和堆元素序号count之间的映射关系:
int exchange(int count, int fre) {
	return count + fre - 2;
}
