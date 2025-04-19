/*
Лабораторная работа №7
Тема: конструктор
Класс: круг (circle)
Поля приватные:
Центр окружности - centre (статический массив из двух вещественных чисел – координаты X и Y);
Поля публичные: 
Радиус окружности - r;
Цвет окружности - color;
Конструкторы:
- конструктор без параметров;
- конструктор, заполняющий все поля.
Деструктор
Методы:
- запись координат центра окружности (set_XY);
- возвращение значения координаты X центра;
- вычисление длины окружности;
Дружественная функция вывода на экран координат центра окружности, радиуса и цвета.
----------------------------------------------------------------------------------------------------
1. Создать статический массив из трех объектов - a. Данные ввести с клавиатуры. Для записи введенных параметров использовать метод set_XY. Вывести массив на экран (значения полей данных и длину окружности).
2. Создать динамический массив объектов - b. Ввод массива из файла. При создании массива использовать конструктор с параметрами. Вывести массив на экран (значения полей данных и длину окружности).
3. Пользователь вводит цвет окружности. Вывести параметры всех окружностей такого цвета (просмотреть два массива).
4. В динамическом массиве (b) найти значение максимальной координаты X центра окружности.
5. Отсортировать динамический массив по возрастанию радиуса.


*/

#include <iostream>
#include <math.h>
#include <string.h>


class cercle
{
private:
    double center[2];
public:
    double r;char color[100];

    cercle(double center[2],double r,char color[100]);
    ~cercle();
    cercle();
    void set_XY(double x,double y)
    {
        center[0]=x;
        center[1]=y;
    }

    double output_X(){return center[0];}

    double find_len(){return 2*M_PI*r;}

    friend void output(cercle *a);
    
};

void output(cercle *a)
{
    printf("x=%lf y=%lf r=%lf color=%s\n",a->center[0],a->center[1],a->r,a->color);
}

cercle::cercle()
{
    printf("Constructor cercle empty\n");
}

cercle::cercle(double _center[2],double _r,char _color[100])
{
    memcpy(center,_center,sizeof(double)*2);
    memcpy(color,_color,sizeof(char)*100);
    r=_r;
}

cercle::~cercle()
{
    printf("диструктор сработал\n");
}




void t1(cercle *a)//1. Создать статический массив из трех объектов - a. Данные ввести с клавиатуры. Для записи введенных параметров использовать метод set_XY. Вывести массив на экран (значения полей данных и длину окружности).

{
    printf("\n\n\nt1\n");
    
    double x,y;
    for (int i = 0; i < 3; i++)
    {
        printf("input x,y,r,color\n");
        scanf("%lf%lf%lf%s",&x,&y,&a[i].r,a[i].color);
        a[i].set_XY(x,y);

    }
    for (int i = 0; i < 3; i++)
    {
        output(&a[i]);
    }
}

void t2(cercle **&b,int &n)//2. Создать динамический массив объектов - b. Ввод массива из файла. При создании массива использовать конструктор с параметрами. Вывести массив на экран (значения полей данных и длину окружности).

{
    printf("\n\n\nt2\n");
    n=0;
    FILE *f=fopen("lub7.txt","r");
    if (f==NULL)    {   printf("file not exist\n");    return;    }

    char str[200];
    while (fgets(str,200,f))    {   n++;    }

    printf("n=%d\n",n);
    if (n==0)        {   printf("file is empty\n");      return;    }
    
    rewind(f);
    b=new cercle*[n];
    double _center[2],_r;
    char _color [100];

    for (int i = 0; i < n; i++)
    {
        fscanf(f,"%lf%lf%lf%s",&_center[0],&_center[1],&_r,_color);
        b[i]=new cercle(_center,_r,_color);
    }
    for (int i = 0; i < n; i++)
    {
        output(b[i]);
    }
}


void t3(cercle a[3],cercle **b,int n)//3. Пользователь вводит цвет окружности. Вывести параметры всех окружностей такого цвета (просмотреть два массива).

{
    bool flag=0;
    printf("\n\n\nt3\ninput color\n");
    char _color[100];
    scanf("%s",_color);
    for (int i = 0; i < 3; i++)
    {
        if(strcmp(a[i].color,_color)==0)
        {
            output(&a[i]);flag=1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(strcmp(b[i]->color,_color)==0)
        {
            output(b[i]);flag=1;
        }
    }
    
    
}


void t4(cercle **b,int n)//4. В динамическом массиве (b) найти значение максимальной координаты X центра окружности.

{
    double max_X=b[0]->output_X();
    for (int i = 0; i < n; i++)
    {
        if(max_X<b[i]->output_X())
        {
            max_X=b[i]->output_X();
        }
    }
    printf("\n\n\nt4\nMAX X = %lf\n",max_X);

}


void t5(cercle **b,int n)//5. Отсортировать динамический массив по возрастанию радиуса.

{
    printf("\n\n\nt5\n");
    cercle * swap;
    bool flag=0;
    for (int i = 0; i < n &&flag==0; i++)
    {
        flag=0;
        for (int j = 0; j < n-1; j++)
        {
            if(b[j]->r > b[j+1]->r)
            {
                swap=b[j];
                b[j]=b[j+1];
                b[j+1]=swap;
                flag=1;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        output(b[i]);
    }
    
}

int main(int argc, char const *argv[])
{
    cercle **b=NULL;
    int n=0;
    cercle a[3];

    t1(a);
    t2(b,n);
    if (b==NULL)
    {
        return 0;
    }
    
    t3(a,b,n);
    t4(b,n);
    t5(b,n);
    
    


    printf("end\n");
    return 0;
}

