#include<stdio.h>
//��ʵɢ����ʦ����д��, �ҵ�GitHub�ݹ鲿���ϻ���
int Ack(int a, int b) {
	if (a == 0) {
		return b + 1;
	}
	if (b == 0) {
		return Ack(a - 1, b);
	}
	return Ack(a - 1, Ack(a, b - 1));
}
//������������ά����汾�Ͳ�д��, ���������·, �������ֶ��, ûɶ����
//�������,�����������, ˵���Ҫ����, ��дд, ����������.����ص㿴���ײ���ԭ��.

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("����������ֵ = %d\n", Ack(a, b));
	return 0;
}