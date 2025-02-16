#include <iostream>
#include <clocale>

int main(int argc, char const *argv[])
{
    setlocale (LC_CTYPE,"");
    double sum=0;
    double fact=1;//fact 0
    int pw=1;
    int n;
    printf("введите n\n");
    scanf("%d",&n);
    for (int i = 1;i<=n;i++)
    {
        fact=fact*(i);

        pw*=-1;
        sum+=pw/fact;
        printf ("i=%d fact=%lf\n",i,fact);
        
    }
    
    printf("сумма = %lf",sum);
    return 0;
}
