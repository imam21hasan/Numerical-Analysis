#include <stdio.h>
#include <math.h>
void inter(int n, float k)
{
    float x[20], y[20][20];
    printf("Enter the values of x and corresponding y:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d]= ", i);
        scanf("%f", &x[i]);
        printf("y[%d]= ", i);
        scanf("%f", &y[i][0]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
    printf("\nFORWARD DIFFERENCE TABLE\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%0.2f", x[i]);
        for (int j = 0; j < n - i; j++)
        {
            printf("\t%0.4f", y[i][j]);
        }
        printf("\n");
    }
    double h = x[1] - x[0];
    double z;
    z = (1.0 / h) * (y[1][1] - (1.0 / 2.0) * y[1][2] + (1.0 / 3.0) * y[1][3] - (1.0 / 4.0) * y[1][4] + (1.0 / 5.0) * y[1][5]);
    printf("\nAnswer : %lf", z);
}
int main()
{
    int n;
    float k;
    printf("Enter the size of the table : ");
    scanf("%d", &n);
    printf("Enter the value of x to find y : ");
    scanf("%f", &k);
    inter(n, k);
    return 0;
}
