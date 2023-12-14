#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>	//�Ҽ� ���ϱ�
//
//int prime_checking(int num) {	
//
//	int prime = 1;
//
//	for (int i = 2; i < num; i++)
//	{
//		if (num % i == 0) {
//			prime = 0;
//			//printf("\n%d�� ��� : %d\n", num, i);
//			break;
//		}
//	}
//
//	return prime;
//}
//
//void main() {
//	int counter = 0;
//	for (int i = 1; i <= 10; i++) {
//		if (prime_checking(i)) {
//			printf("%d�� �Ҽ��Դϴ�\n", i);
//			counter += 1;
//		}
//	}
//	printf("1���� 10������ �Ҽ��� ������ %d�� �Դϴ�!", counter);
//}//end of main

/////////////////////////

#include <stdio.h>	//�Ҽ����ϱ�_�����佺�׳׽�1
#include <stdlib.h>
#include <time.h>

void main() {
	FILE* fp = fopen("d:\prime.txt", "w");	//���� �Է�
	if (fp == NULL)	printf("���� ���� ����\n");
	else printf("���� ���� ����\n");


	int SIZE;
	printf("<<�Ҽ� ���ϱ� ���α׷�>>\n");
	printf("���ڸ� �Է��ϼ��� :");
	scanf("%d", &SIZE);
	int* a = (int*)malloc(sizeof(int) * SIZE);	//�ʿ��� ũ�⸸ŭ ���� �޸� �Ҵ�

	clock_t start = clock();	//���� �ð�
	for (int i = 0; i < SIZE; i++)	//�迭 �ʱ�ȭ
	{
		a[i] = 0;
	}

	for (int i = 2; i < SIZE; i++)	//�Ҽ� �˰���(�����佺�׳׽��� ü)
	{
		if (a[i] == 0) {
			for (int j = 2; j < SIZE; j++)
			{
				if (i * j < SIZE) {
					a[i * j] = 1;
				}
			}
		}
	}

	int count = 0;	//�Ҽ� ���� �ľ�					
	printf("%d�� �Ҽ� : ", SIZE);	//�Ҽ� ����ϱ�
	fprintf(fp, "%d�� �Ҽ� :\n", SIZE);	//���� �Է�

	for (int i = 2; i < SIZE; i++)
	{
		if (a[i] == 0) {
			printf("%d ", i);
			fprintf(fp, "%d ", i);	//���� �Է�
			count++;	//�Ҽ� ���� �߰�
		}
	}

	printf("\n�Ҽ� ���� : %d��\n", count);	//�Ҽ� ���� �ľ�
	fprintf(fp, "\n�Ҽ� ���� : %d��\n", count);	//���� �Է�


	free(a);
	fclose(fp);
	clock_t end = clock();	//�� �ð�
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("����ð� : %.3lf��\n", time);	//����ð� ǥ��
	fprintf(fp, "\n����ð� : %.2lf\n", time);	//���� �Է�
}//end of main

//////////////////////

//#include <stdio.h>	//�Ҽ����ϱ�_�����佺�׳׽�
//#include <stdlib.h>
//#include <time.h>
//
//void main() {
//	FILE* fp = fopen("d:\prime.txt", "w");	//���� �Է�
//	if (fp == NULL)	printf("���� ���� ����\n");
//	else printf("���� ���� ����\n");
//
//
//	int SIZE;
//	printf("���ڸ� �Է��ϼ��� :");
//	scanf("%d", &SIZE);
//	int* a = (int*)malloc(sizeof(int) * SIZE);	//�ʿ��� ũ�⸸ŭ ���� �޸� �Ҵ�
//
//	clock_t start = clock();	//���� �ð�
//	for (int i = 0; i < SIZE; i++)	//�迭 �ʱ�ȭ
//	{
//		a[i] = 0;
//	}
//
//	for (int i = 2; i < SIZE; i++)	//�Ҽ� �˰���(�����佺�׳׽��� ü)
//	{
//		if (a[i] == 0) {
//			for (int j = 2; j < SIZE; j++)
//			{
//				if (i * j < SIZE) {
//					a[i * j] = 1;
//				}
//			}
//		}
//	}
//
//	int count = 0;	//�Ҽ� ���� �ľ�					
//	printf("%d�� �Ҽ� : ", SIZE);	//�Ҽ� ����ϱ�
//	fprintf(fp, "%d�� �Ҽ� :\n", SIZE);	//���� �Է�
//
//	for (int i = 2; i < SIZE; i++)
//	{
//		if (a[i] == 0) {
//			printf("%d ", i);
//			fprintf(fp, "%d ", i);	//���� �Է�
//			count++;	//�Ҽ� ���� �߰�
//		}
//	}
//
//	printf("\n�Ҽ� ���� : %d��\n", count);	//�Ҽ� ���� �ľ�
//	fprintf(fp, "\n�Ҽ� ���� : %d��\n", count);	//���� �Է�
//
//
//	free(a);
//	fclose(fp);
//	clock_t end = clock();	//�� �ð�
//	double time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("����ð� : %.3lf��\n", time);	//����ð� ǥ��
//	fprintf(fp, "\n����ð� : %.2lf\n", time);	//���� �Է�
//}//end of main

////////////////

//#include <stdio.h>
//
//int is_prime(int n) {	//�Ҽ� ���ϱ� by ChatGPT
//	if (n <= 1) {
//		return 0;
//	}
//	for (int i = 2; i * i <= n; i++) {
//		if (n % i == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main() {
//	int num = 16;
//	if (is_prime(num)) {
//		printf("%d is a prime number\n", num);
//	}
//	else {
//		printf("%d is not a prime number\n", num);
//	}
//	return 0;
//}

//////////

//#include <stdio.h>	//�Ҽ� �Ǻ���
//
//int main() {
//	int n;
//	printf("<<�Ҽ� �Ǻ���>>\n");
//	printf("���ڸ� �Է��ϼ��� :");
//	scanf("%d", &n);
//
//	for (int i = 2; i <= n; i++)
//	{
//		if (n>2 && n % i == 0) {
//			printf("%d�� �Ҽ��� �ƴմϴ�.\n", n);
//			break;
//		}
//		else {
//			printf("%d�� �Ҽ��Դϴ�.\n", n);
//			break;
//		}
//	}
//
//	return 0;
//}//end of main

/////////////////

//#include <stdio.h>	//�ð� �ڵ� �׽�Ʈ
//#include <time.h>
//
//int main(void) {
//	clock_t now, end;
//
//	now = clock();
//	//time_t now = time(NULL);
//
//	for (int i = 0; i < 202300; i++)
//	{
//		printf("%d ", i);
//	}
//
//	//time_t end = time(NULL);
//	end = clock();
//	double dif = (double)(end - now)/CLOCKS_PER_SEC;
//	//double time = (double)(end - now);
//
//	printf("\ntime : %lf\n", dif);
//}