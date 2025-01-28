#include <stdio.h>

int main()
{
    int n, i, j;
    float x[10], y[10][10];

    printf("Enter the value of n : ");
    scanf("%d", &n);

    printf("Enter the values of x and y :\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }
    for (int i = 1; i < n; i++)
    {
        for (j = n - 1; j >= i; j--)
        {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }
    printf("Backward difference table is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%0.2f", x[i]);
        for (j = 0; j <= i; j++)
        {
            printf("\t%0.2f", y[i][j]);
        }
        printf("\n");
    }

    return 0;
}
