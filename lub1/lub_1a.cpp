#include <iostream>
#include <math.h>
#include <clocale>
int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"");
    for (int i = 0; i < 10; i++)
    {
        printf("input x\n");
        double x,y;
        scanf("%lf",&x);
        if (20<=x && x<100)  {y=sin(x)+cos(x);printf("y=%lf\n",y);}
        else if (8<=x && x<20)     {y=sqrt(x-8);printf("y=%lf\n",y);}
        else
        {
            printf("y∄");
            return 0;
        }
        
    }
    getchar();
    return 0;

}
