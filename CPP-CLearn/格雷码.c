#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void exchange(char *ch) {
	if (*ch == '0') {
		*ch = '1';
	} else {
		*ch = '0';
	}
}

int main() {
	int num;
	printf("Enter the number to trans:\n");
	scanf("%d", &num);
	//������Ҫ���ַ���λ��
	int size = log2(num) + 1;
	char* arr = (char*)malloc(size+1);
	for (int i = 0; i < size; i++) {
		arr[i] = '0';
	}
	arr[size] = '\0';
	for (int i = 0; i <= num; i++) {
		if (i % 2) {//���i������,�����ĩβ����
			exchange(&arr[size - 1]);
		} else {
			for (int j = size-1; j > 0; j--) {
				if (arr[j] == '1') {//���i��ż��, ����Ĵ�������һ��1����߰��ŵ�����
					exchange(&arr[j - 1]);
					break;
				}
			}
		}
	}
	printf("result = %s\n", arr);
	return 0;
}