#include <stdio.h>

int main()
{
    float x[10], y[10][10];
    int i, j, n;
    float a, b, h, rslt;

    printf("Enter value of n : ");
    scanf("%d", &n);

    printf("Enter the value of x & y :\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);

        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    printf("Forward difference table is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%0.2f", x[i]);
        for (j = 0; j < n - i; j++)
        {
            printf("\t%0.2f", y[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the value of a for interpolation : ");
    scanf("%f", &a);

    h = x[1] - x[0];
    b = (a - x[0]) / h;

    rslt = y[0][0] + b * y[0][1] + b * (b - 1) / 2 * y[0][2] + b * (b - 1) * (b - 2) / 6 * y[0][3];

    printf("\nThe result is : %0.2f", rslt);

    return 0;
}
