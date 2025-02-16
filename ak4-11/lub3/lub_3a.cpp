// сумма ряда с заданной точностью (ряд из второй лабы (2А))
#include <iostream>
#include <clocale>
#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"");
    double w;
    printf("введите точность\n");
    scanf("%lf",&w);
    double i,s,nfac,n1;i=1;
    n1=1;nfac=1;s=0;
    int n=0;
    
    while (fabs(i)>=fabs(w))
    {   
        n++;
        nfac=nfac*n;
        n1=n1*(-1);
        i=n1/nfac;
        s=s+i;
        printf("i= %lf\n",i);
    }
    printf("s= %lf\n",s);
    return 0;
}
