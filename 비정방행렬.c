#include <stdio.h>
#define size1 2
#define size2 3
int main()
{
    int a[size1][size2] = {{2, 3, 7}, {1, 4, 8}};
    int b[size2][size1] = {{4, 7}, {3, 9}, {1, 5}};
    int c[size1][size1];
    int i, j, k= 0;

    //배열 초기화
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            c[i][j] = 0;
        }
    }
    
    //비정방 행렬
    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size1; j++)
        {
            int res = 0;
            for (int k = 0; k < size2; k++)
            {
                res += a[i][k] * b[k][j];
            }
            c[i][j] = res;
            printf("c[%d][%d] = %d ", i, j, c[i][j]);
        }
        printf("\n");
    }
    
    printf("-----------------------\n");

    //c배열 출력
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}//end of main
