//�������ѧ� �����ڧ��ӧܧ�
//��������
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
	//ΪʲôҪ��left, right����start��end:
	//����ݹ黹Ҫ��start��end��Ϊ��Եֵ, ����������������Ųλ�õ�ʱ��仯��.
	int left = start, right = end;
	while (left < right) {
		//��Ϊ�����pivot�����ֵ, ���Դ��Ҷ˿�ʼ�ƶ��Ƚ�
		//����Ҷ�ֵС��pivot,����Ҷ�ֵ�������
		//����Ҷ�ֵ����pivot, ����������ƶ��Ҷ�
		while (arr[right] >= pivot && left < right) {
			right--;
		}
		//Ϊʲô�м�ҲҪÿ���ж�left ? right:
		//��Ϊ��ѭ��Ƕ�׽ṹ, ��ʹһ��ʼ��ѭ������left < right, ����ѭ���Կ���һֱѭ����left >= right, ��ʱ�����Ҫÿ���жϴ�С��ϵ,��������.
		if (left < right) {
			arr[left] = arr[right];
		}
		//����ƶ���ʽ���Ҷ��ƶ���ʽ��ͬ, ���߽����ƶ�
		while (arr[left] <= pivot && left < right) {
			left++;
		}
		if (left < right) {
			arr[right] = arr[left];
		}
		//��left��right��ͷ��ʱ��,Ҳ����pivot��ֵӦ���ڵ�λ��, ��ʱ��pivotֵ�����λ��. 
		if (left == right) {
			arr[left] = pivot;
		}
	}
	//ִ�еݹ����, ��left��right��ͷ��λ��Ϊ�ֽ�, ��һ��, ��һ�����
	quickSortR(arr, start, left - 1);
	quickSortR(arr, left + 1, end);
}
//�����������Ϊ�о�ֱ���ÿ��ź���̫��, Ҫ������,���Ҷ�,�����������������һ��, ֻ��Ҫ������������鳤�ȼ���, �о��ÿ�һЩ.
void quickSort(int* arr, int length) {
	quickSortR(arr, 0, length - 1);
}
