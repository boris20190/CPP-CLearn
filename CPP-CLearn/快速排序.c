//Быстрая сортировка
//快速排序
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quickSortR(int* arr, int start, int end);
void quickSort(int* arr, int length);

int main() {
	int arr[50];
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	quickSort(arr, 50);
	for (int i = 0; i < 50; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void quickSortR(int* arr, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = arr[start];
	//为什么要用left, right接收start和end:
	//后面递归还要用start和end作为边缘值, 这俩数不能在下面挪位置的时候变化了.
	int left = start, right = end;
	while (left < right) {
		//因为定义的pivot是左端值, 所以从右端开始移动比较
		//如果右端值小于pivot,则把右端值交给左端
		//如果右端值大于pivot, 则继续向左移动右端
		while (arr[right] >= pivot && left < right) {
			right--;
		}
		//为什么中间也要每次判断left ? right:
		//因为是循环嵌套结构, 即使一开始大循环满足left < right, 但内循环仍可能一直循环到left >= right, 这时候就需要每次判断大小关系,否则会出错.
		if (left < right) {
			arr[left] = arr[right];
		}
		//左端移动方式和右端移动方式相同, 二者交替移动
		while (arr[left] <= pivot && left < right) {
			left++;
		}
		if (left < right) {
			arr[right] = arr[left];
		}
		//当left和right碰头的时候,也就是pivot的值应该在的位置, 这时把pivot值填入该位置. 
		if (left == right) {
			arr[left] = pivot;
		}
	}
	//执行递归操作, 以left和right碰头的位置为分界, 左一半, 右一半二分
	quickSortR(arr, start, left - 1);
	quickSortR(arr, left + 1, end);
}
//这个单纯是因为感觉直接用快排函数太丑, 要填数组,左右端,所以用下面这个美观一下, 只需要填入数组和数组长度即可, 感觉好看一些.
void quickSort(int* arr, int length) {
	quickSortR(arr, 0, length - 1);
}
