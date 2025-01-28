#include <stdio.h>

int main()
{
    int n, i, j, k;
    float x[10];

    printf("Enter the number of equations : ");
    scanf("%d", &n);

    float A[10][10] = {{2, 1, 1, 10}, {3, 2, 3, 18}, {1, 4, 9, 16}};

    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            float ratio = A[k][i] / A[i][i];
            for (j = 0; j <= n; j++)
            {
                A[k][j] -= ratio * A[i][j];
            }
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        x[i] = A[i][n];
        for (j = i + 1; j < n; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    printf("The result is : \n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %0.2f\n", i + 1, x[i]);
    }

    return 0;
}