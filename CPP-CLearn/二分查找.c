//поиск <<делением пополам>> в упорядоченном массиве
//在有序数组中二分查找__只能用在有序元素之中
#include<stdio.h>
#define N 100

int is_equal(int* A, int target, int imin, int imax);

int main() {
	int A[N];
	for (int i = 0; i < N; i++) {
		A[i] = i;
	}
	int target;
	scanf("%d", &target);

	is_equal(A, target, 0, 99) ? printf("YES\n") : printf("NO\n");
	return 0;
}

int is_equal(int* A, int target, int imin, int imax) {
	if (imin > imax) {
		return 0;
	}
	int mid = imin + (imax - imin) / 2;
	//这里为什么要用if-else,不能直接三个if并排:
	//三个if并排是三个判断语句, 在递归中要依次判断执行, 其中一个出现return并不能停止, 还要回归之后继续向下执行, 只有把递归中的语句全执行完才会停
	//if-else嵌套是算作一个语句, 其中任何一个出现return都是这个语句执行完毕, 之后若无其他语句, 则递归停止.

	//为什么这里用三个if并排结果会一直为yes?
	if (target == A[mid]) {
		return 1;
	} else if (target > A[mid]) {
		is_equal(A, target, mid + 1, imax);
	} else {
		is_equal(A, target, imin, mid - 1);
	}
}