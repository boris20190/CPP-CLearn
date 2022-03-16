#include<stdio.h>

int Fact(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * Fact(n - 1);
}

int Fib(int n) {
	if (n <= 2) {
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}

int main() {
	int num;
	scanf("%d", &num);
	printf("½×³ËÖµ = %d\tì³²¨ÄÇÆõÖµ = %d\n",Fact(num),Fib(num));
	return 0;
}