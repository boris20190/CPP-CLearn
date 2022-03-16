#include<stdio.h>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int GCD(int a, int b) {
	//����a<b
	if (a > b) {
		swap(&a, &b);
	}
	if (b % a == 0) {
		return a;
	}
	GCD(a, b - a);
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("���Լ�� = %d\n", GCD(a, b));
	return 0;
}