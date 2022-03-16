#include<stdio.h>
//其实散步老师让咱写过, 我的GitHub递归部分上还有
int Ack(int a, int b) {
	if (a == 0) {
		return b + 1;
	}
	if (b == 0) {
		return Ack(a - 1, b);
	}
	return Ack(a - 1, Ack(a, b - 1));
}
//阿克曼函数二维数组版本就不写了, 还是这个套路, 就是数字多点, 没啥新意
//看最后了,如果考纲下来, 说这个要考察, 就写写, 不考就算了.这遍重点看明白操作原理.

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("阿克曼函数值 = %d\n", Ack(a, b));
	return 0;
}