//字典排序算法
//比上一个算法更人性化, 人类更好理解的生成算法
#include<stdio.h>

//字典排序
//1. 从右往左找第一个左边数小于右边数的数,记下来位置p
//2. 从右往左找第一个大于arr[p]的数,记下来位置q
//3. 交换这俩数
//4. 将p位置后面的元素按从小到大顺序排列

void swap(int* a, int* b) {//交换元素
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int arr[], int start, int end) {//图简单,写个冒泡就行,start和end是数组下标
	for (int i = 0; i <= end - start; i++) {
		for (int j = start; j <= end - i - 1; j++) {
			if (arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void permutation(int arr[], int n) {//传入数组arr,数组共有n个元素
	int count = 1, p,q;
	for (int i = 1; i <= n; i++) {
		count *= i;
	}
	sort(arr, 0, n - 1);
	for (int i = count; i > 0; i--) {//进行count次循环
		for (int i = 0; i < n; i++) {
			printf("%d", arr[i]);
		}
		printf("\n");
		for (int j = n-1; j > 0; j--) {
			if (arr[j-1]<arr[j]) {
				p = j - 1;
				break;
			}
		}
		for (int k = n-1; k >= 0; k--) {
			if (arr[k] > arr[p]) {
				q = k;
				break;
			}
		}
		swap(&arr[p], &arr[q]);
		sort(arr, p + 1, n - 1);
	}
}

int main() {
	int arr[] = { 1,2,4,3};
	permutation(arr, 4);
	return 0;
}
