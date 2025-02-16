#include <iostream>
#include <clocale>


int main()
{
    setlocale(LC_CTYPE,"");
    printf ("input x and y\n");
    double x,y;
    scanf("%lf%lf",&x,&y);
    bool flag = 0;
    if ( y>0 )    
    {
        if ( y<1.5*x-3) flag= 1;
        else if ( y<-1.5*x+9) flag= 1;        
    }
    if (flag) {printf("ДА\n");}
    else {printf("НЕТ\n");}
    
    return 0;
}