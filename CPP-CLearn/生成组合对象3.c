//�ֵ������㷨
//����һ���㷨�����Ի�, ����������������㷨
#include<stdio.h>

//�ֵ�����
//1. ���������ҵ�һ�������С���ұ�������,������λ��p
//2. ���������ҵ�һ������arr[p]����,������λ��q
//3. ����������
//4. ��pλ�ú����Ԫ�ذ���С����˳������

void swap(int* a, int* b) {//����Ԫ��
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int arr[], int start, int end) {//ͼ��,д��ð�ݾ���,start��end�������±�
	for (int i = 0; i <= end - start; i++) {
		for (int j = start; j <= end - i - 1; j++) {
			if (arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void permutation(int arr[], int n) {//��������arr,���鹲��n��Ԫ��
	int count = 1, p,q;
	for (int i = 1; i <= n; i++) {
		count *= i;
	}
	sort(arr, 0, n - 1);
	for (int i = count; i > 0; i--) {//����count��ѭ��
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
