#include<stdio.h>
#include<stdlib.h>

void spawn_tr(int arr[][5]);
void show(int arr[][5]);
int sum(int arr[][5], int a, int b);

int main() {
	int arr[5][5];
	spawn_tr(arr);
	show(arr);
	printf("����ܺ� = %d\n", sum(arr, 0, 0));
	return 0;
}

//���������һ��5x5��������
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

//дһ������, ���شӶ����׵������߷��о������ֵĺ͵����ֵ(���ܸ���,����ͬ�д�,ֻ�����»���������)
int sum(int arr[][5], int a, int b) {
	if (a >= 5) {//���������Χ, ��Ĭ��+0, ���Ǹ��ݹ�����ı�־
		return 0;
	}
	//����һ�����ӵ������õݹ����ʽ��ʾ����
	int left = sum(arr, a + 1, b);
	int right = sum(arr, a + 1, b + 1);
	if (left < right) {//��Զ���Ǹ�����
		return arr[a][b] + right;
	} else {
		return arr[a][b] + left;
	}
}
