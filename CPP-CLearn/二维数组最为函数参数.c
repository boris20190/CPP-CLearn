#include<stdio.h>
#include<stdlib.h>
//��ά������Ϊ����������������ɶ����д, ����Ҫ�ڵڶ�������д�ж��,�ú���֪��һ���ж��ٸ�Ԫ��,�������ɶʱ����ڶ���, ɶʱ���������
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