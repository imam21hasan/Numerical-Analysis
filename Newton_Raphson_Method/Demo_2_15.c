#include <stdio.h>
#include <math.h>

float fun(float x)
{
    return (x*x*x-2*x-5);
}
float fun_Derivative(float x)
{
    return (3*x*x-2);
}

int main()
{
    float x;
    int i = 0, n;

    printf("First Approximation: ");       //  Xo= 2
    scanf("%f", &x);

    printf("Iteration: ");
    scanf("%d", &n);

    while (i <= n)
    {
        if (fun_Derivative(x) == 0)
        {
            printf("Mathematical Error !!!\n");
            break;
        }
        else
        {
            x = x - fun(x) / fun_Derivative(x);
            i++;
        }
    }

    printf("Approximate Root: %.4f \n", x);
    return 0;
}