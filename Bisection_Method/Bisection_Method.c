#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

float fun(float x)
{
    return x * x * x - 2 * x - 5; // Example 2.2
}

void bisection(float a, float b)
{
    if (fun(a) * fun(b) >= 0)
    {
        printf("Invalid interval !!!\n");
        return;
    }

    float c;

    while ((b - a) >= EPSILON)
    {
        c = (a + b) / 2;

        if (fun(c) == 0)
        {
            break;
        }

        if (fun(c) * fun(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    if (c != 0)
    {
        printf("The root is : %0.4f\n", c);
    }
}

int main()
{
    float a, b;

    printf("Enter the interval of a & b : ");
    scanf("%f %f", &a, &b);

    bisection(a, b);

    return 0;
}