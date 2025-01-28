#include <stdio.h>

int main()
{
    int n,i, j;
    float x[10],y[10][10];

    printf("Enter value of n : ");
    scanf("%d", &n);

    printf("Enter the values of x & y :\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);

        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    for ( i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    printf("Central difference table :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            printf("%0.2f \t", y[i][j]);
        }
        printf("\n");
    }
    return 0;
}

