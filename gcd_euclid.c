#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  //��Ŭ���� ȣ����

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

    printf("�� ���� �Է��ϼ���: ");
    scanf("%d %d", &num1, &num2);

    printf("%d�� %d�� �ִ������� %d�Դϴ�.", num1, num2, gcd(num1, num2));

    return 0;
}
