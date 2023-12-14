#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <time.h>
//
//int prime_checking(int n) {
//
//	for (int k = 2; k < n; k++)
//	{
//		if (n > 2 && (n % k == 0)) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main() {
//
//	int num;
//	int count = 0;
//
//	printf("���� :");
//	scanf("%d", &num);
//
//	clock_t start = clock();
//	printf("1~%d������ �Ҽ� : ", num);
//	for (int i = 2; i < num; i++)
//	{
//		if (prime_checking(i)) {
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n�Ҽ� ���� : %d��\n", count);
//
//	clock_t end = clock();
//
//	double timer = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("time : %.3lf��", timer);
//	return 0;
//}//end of main


#include <stdio.h>
#include <time.h>
#define SIZE 10000

int prime_checking(int n) {

	for (int k = 2; k < n; k++)
	{
		if (n > 2 && (n % k == 0)) {
			return 0;
		}
	}
	return 1;
}

int main() {

	int count = 0;
	/*int num;

	printf("���� :");
	scanf("%d", &num);*/

	printf("1~%d������ �Ҽ� : ", SIZE);
	clock_t start = clock();
	for (int i = 2; i < SIZE; i++)
	{
		if (prime_checking(i)) {
			printf("%d ", i);
			count++;
		}
	}
	printf("\n�Ҽ� ���� : %d��\n", count);

	clock_t end = clock();

	double timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time : %.3lf��", timer);
	return 0;
}//end of main