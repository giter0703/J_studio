#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>	//소수 구하기
//
//int prime_checking(int num) {	
//
//	int prime = 1;
//
//	for (int i = 2; i < num; i++)
//	{
//		if (num % i == 0) {
//			prime = 0;
//			//printf("\n%d의 약수 : %d\n", num, i);
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
//			printf("%d는 소수입니다\n", i);
//			counter += 1;
//		}
//	}
//	printf("1부터 10까지의 소수의 갯수는 %d개 입니다!", counter);
//}//end of main

/////////////////////////

#include <stdio.h>	//소수구하기_에라토스테네스1
#include <stdlib.h>
#include <time.h>

void main() {
	FILE* fp = fopen("d:\prime.txt", "w");	//파일 입력
	if (fp == NULL)	printf("파일 열기 실패\n");
	else printf("파일 열기 성공\n");


	int SIZE;
	printf("<<소수 구하기 프로그램>>\n");
	printf("숫자를 입력하세요 :");
	scanf("%d", &SIZE);
	int* a = (int*)malloc(sizeof(int) * SIZE);	//필요한 크기만큼 동적 메모리 할당

	clock_t start = clock();	//시작 시각
	for (int i = 0; i < SIZE; i++)	//배열 초기화
	{
		a[i] = 0;
	}

	for (int i = 2; i < SIZE; i++)	//소수 알고리즘(에라토스테네스의 체)
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

	int count = 0;	//소수 갯수 파악					
	printf("%d의 소수 : ", SIZE);	//소수 출력하기
	fprintf(fp, "%d의 소수 :\n", SIZE);	//파일 입력

	for (int i = 2; i < SIZE; i++)
	{
		if (a[i] == 0) {
			printf("%d ", i);
			fprintf(fp, "%d ", i);	//파일 입력
			count++;	//소수 갯수 추가
		}
	}

	printf("\n소수 갯수 : %d개\n", count);	//소수 갯수 파악
	fprintf(fp, "\n소수 갯수 : %d개\n", count);	//파일 입력


	free(a);
	fclose(fp);
	clock_t end = clock();	//끝 시각
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("경과시간 : %.3lf초\n", time);	//경과시간 표시
	fprintf(fp, "\n경과시간 : %.2lf\n", time);	//파일 입력
}//end of main

//////////////////////

//#include <stdio.h>	//소수구하기_에라토스테네스
//#include <stdlib.h>
//#include <time.h>
//
//void main() {
//	FILE* fp = fopen("d:\prime.txt", "w");	//파일 입력
//	if (fp == NULL)	printf("파일 열기 실패\n");
//	else printf("파일 열기 성공\n");
//
//
//	int SIZE;
//	printf("숫자를 입력하세요 :");
//	scanf("%d", &SIZE);
//	int* a = (int*)malloc(sizeof(int) * SIZE);	//필요한 크기만큼 동적 메모리 할당
//
//	clock_t start = clock();	//시작 시각
//	for (int i = 0; i < SIZE; i++)	//배열 초기화
//	{
//		a[i] = 0;
//	}
//
//	for (int i = 2; i < SIZE; i++)	//소수 알고리즘(에라토스테네스의 체)
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
//	int count = 0;	//소수 갯수 파악					
//	printf("%d의 소수 : ", SIZE);	//소수 출력하기
//	fprintf(fp, "%d의 소수 :\n", SIZE);	//파일 입력
//
//	for (int i = 2; i < SIZE; i++)
//	{
//		if (a[i] == 0) {
//			printf("%d ", i);
//			fprintf(fp, "%d ", i);	//파일 입력
//			count++;	//소수 갯수 추가
//		}
//	}
//
//	printf("\n소수 갯수 : %d개\n", count);	//소수 갯수 파악
//	fprintf(fp, "\n소수 갯수 : %d개\n", count);	//파일 입력
//
//
//	free(a);
//	fclose(fp);
//	clock_t end = clock();	//끝 시각
//	double time = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("경과시간 : %.3lf초\n", time);	//경과시간 표시
//	fprintf(fp, "\n경과시간 : %.2lf\n", time);	//파일 입력
//}//end of main

////////////////

//#include <stdio.h>
//
//int is_prime(int n) {	//소수 구하기 by ChatGPT
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

//#include <stdio.h>	//소수 판별기
//
//int main() {
//	int n;
//	printf("<<소수 판별기>>\n");
//	printf("숫자를 입력하세요 :");
//	scanf("%d", &n);
//
//	for (int i = 2; i <= n; i++)
//	{
//		if (n>2 && n % i == 0) {
//			printf("%d는 소수가 아닙니다.\n", n);
//			break;
//		}
//		else {
//			printf("%d는 소수입니다.\n", n);
//			break;
//		}
//	}
//
//	return 0;
//}//end of main

/////////////////

//#include <stdio.h>	//시간 코드 테스트
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