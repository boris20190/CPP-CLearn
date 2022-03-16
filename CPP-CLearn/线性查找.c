//§­§Ú§ß§Ö§Û§ß§í§Û §á§à§Ú§ã§Ü
//ÏßÐÔ²éÕÒ
#include<stdio.h>

int main() {
	int A[10];
	for (int i = 0; i < 10; i++) {
		A[i] = i;
	}
	int target;
	scanf("%d", &target);
	for (int i = 0; i < 10; i++) {
		if (target==A[i]) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}