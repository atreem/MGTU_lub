 //лаба 1Б но х задаётся интервалом от а до b и с шагом h
#include <clocale>
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
    
    setlocale(LC_CTYPE,"");
    double a,b,n,y;
    printf("введите а(от), b(до) и n(шаг)\n");
    scanf("%lf%lf%lf",&a,&b,&n);
    while (a<=b)
    {
        if (8<=a && a<100){
            if( 20<=a){ y= (sin(a)+cos(a));}
            else { y= ( sqrt( a-8) );}
            printf("y = %lf, x= %lf\n",y,a);
        }
        else
        {
            printf("y∄ x= %lf\n",a);
        }
        
        a=a+n;
        
    }
    
    return 0;
}
