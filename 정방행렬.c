#include <stdio.h>
#define size 3

int main()
{
    int a[size][size] = {{2, 5, 1}, {6, 7, 3}, {1, 8, 6}};
    int b[size][size] = {{4, 8, 2}, {6, 4, 1}, {3, 6, 2}};
    int c[size][size];
    int i, j, cnt= 0;

    //배열 초기화
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            c[i][j] = 0;
        }
    }
    
    //정방 행렬
    for(int k = 0; k < size; k++)
    {
        for (i = 0; i < size; i++)
        {
            int res2 = 0;
            for (j = 0; j < size; j++)
            {
                int res1 = a[k][i];
                res1 *= b[j][i];
                res2 += res1;
            }
            c[k][i] = res2;
            printf("c[%d][%d] = %d ", k, i, c[k][i]);
        }
        printf("\n");
    }

    //c배열 출력
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%3d ", c[i][j]);
        }
        printf("\n");
    }
}//end of main
