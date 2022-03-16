#include<stdio.h>
#include<stdlib.h>
//二维数组作为函数参数不能俩空啥都不写, 至少要在第二个空上写有多大,让函数知道一行有多少个元素,分清楚到啥时候算第二行, 啥时候算第三行
void show(int arr[][5]);
void spawn_tr(int arr[][5]);

int main() {
	int arr[5][5];
	spawn_tr(arr);
	show(arr);
}

void spawn_tr(int arr[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i+1; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void show(int arr[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i+1; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}