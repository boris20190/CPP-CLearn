//���ڧ�� <<�է֧ݧ֧ߧڧ֧� �����ݧѧ�>> �� ������է��֧ߧߧ�� �ާѧ��ڧӧ�
//�����������ж��ֲ���__ֻ����������Ԫ��֮��
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
	//����ΪʲôҪ��if-else,����ֱ������if����:
	//����if�����������ж����, �ڵݹ���Ҫ�����ж�ִ��, ����һ������return������ֹͣ, ��Ҫ�ع�֮���������ִ��, ֻ�аѵݹ��е����ȫִ����Ż�ͣ
	//if-elseǶ��������һ�����, �����κ�һ������return����������ִ�����, ֮�������������, ��ݹ�ֹͣ.

	//Ϊʲô����������if���Ž����һֱΪyes?
	if (target == A[mid]) {
		return 1;
	} else if (target > A[mid]) {
		is_equal(A, target, mid + 1, imax);
	} else {
		is_equal(A, target, imin, mid - 1);
	}
}