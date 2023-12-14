#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  //유클리드 호제법

int gcd(int a, int b) {
    int r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int num1, num2;

    printf("두 수를 입력하세요: ");
    scanf("%d %d", &num1, &num2);

    printf("%d와 %d의 최대공약수는 %d입니다.", num1, num2, gcd(num1, num2));

    return 0;
}
