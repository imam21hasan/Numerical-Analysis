#include <stdio.h>

int main()
{
    int i, j, k, n = 3;
    float a[3][3], L[3][3] = {0}, U[3][3] = {0};

    printf("Input the 3x3 matrix to factorize :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {

        for (j = i; j < n; j++)
        {
            U[i][j] = a[i][j];
            for (k = 0; k < i; k++)
            {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        for (j = i; j < n; j++)
        {
            if (i == j)
                L[i][i] = 1;
            else
            {
                L[j][i] = a[j][i];
                for (k = 0; k < i; k++)
                {
                    L[j][i] -= L[j][k] * U[k][i];
                }
                L[j][i] /= U[i][i];
            }
        }
    }

    printf("\nLower triangular matrix :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%0.2f ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nUpper triangular matrix :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%0.2f ", U[i][j]);
        }
        printf("\n");
    }

    return 0;
}