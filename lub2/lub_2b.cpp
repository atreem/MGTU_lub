#include <iostream>
#include <clocale>
#pragma waring(disable:4996)
double x(int n)
{
    if (n==1) return 5;
    if (n==2) return 3;
    
    else
        return ( x(n-1)/(n- 1) )*2 + x(n-2);
}


int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"");
    double x1,x2,swap;
    x1=5;x2=3;
    int n;
    printf("input index of number\n");
    scanf("%d",&n);
    if      (n==1)   {printf("5\n");}
    else if (n==2)   {printf("3\n");}
    else
    {
        for (int i=3;i<=n;i++)
        {
            swap=(x2/(i- 1))*2 + x1;
            x1=x2;
            x2=swap;
            printf("x%d = %lf\n",i,x2);
        }
//        printf("x = %lf\n",x(n));
        printf("x = %lf\n",x2);

    }
    return 0;
}
