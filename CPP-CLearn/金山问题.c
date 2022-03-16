#include<stdio.h>
#include<stdlib.h>

void spawn_tr(int arr[][5]);
void show(int arr[][5]);
int sum(int arr[][5], int a, int b);

int main() {
	int arr[5][5];
	spawn_tr(arr);
	show(arr);
	printf("最大总和 = %d\n", sum(arr, 0, 0));
	return 0;
}

//先随机生成一个5x5的三角形
void spawn_tr(int arr[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i + 1; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void show(int arr[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i + 1; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//写一个函数, 返回从顶到底的所有走法中经过数字的和的最大值(不能隔行,不能同行串,只能向下或向右下走)
int sum(int arr[][5], int a, int b) {
	if (a >= 5) {//如果超过范围, 就默认+0, 算是个递归结束的标志
		return 0;
	}
	//让下一个被加的数字用递归的形式表示出来
	int left = sum(arr, a + 1, b);
	int right = sum(arr, a + 1, b + 1);
	if (left < right) {//永远加那个最大的
		return arr[a][b] + right;
	} else {
		return arr[a][b] + left;
	}
}
