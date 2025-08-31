#include <iostream>
#include <math.h>
/*
Лабораторная №10. Наследование.
Класс точка на плоскости XY (point)
Поля protected:
- координаты X и Y 
Конструктор:
-конструктор, в который передаются значения всех полей;
- конструктор без параметров;

Класс окружность (circle), потомок от класса точка (точка- центр окружности)
Поля private:
- радиус (r);
Поля public:
Конструктор:
-конструктор, в который передаются значения всех полей, конструктор класса родителя вызывается явным образом;
Методы:
- вычисление расстояния от центра окружности до начала координат(distans);
- вычисление площади окружности (S);
Дружественные функции:
- функция вывода на экран объекта класса цилиндр;
- функция вывода на экран объекта класса конус;


Класс цилиндр (cylinder), потомок от класса окружность
Поля public:
- высота цилиндра (h);
Конструктор:
-конструктор, в который передаются значения всех полей, конструктор класса родителя вызывается не явным образом;
Методы:
- вычисление объема цилиндра (V);

Класс конус (cone), потомок от класса окружность
Поля public:
- высота конуса (h);
Конструктор:
-конструктор, в который передаются значения всех полей, конструктор класса родителя вызывается явным образом;
Методы:
- вычисление объема конуса (V);



Задания

1. Ввести из файла динамический массив объектов класса цилиндр. Вывести элементы массива и методы.
2. Ввести из второго файла динамический объект класса конус. Вывести элементы массива и методы.
3. Найти, чему равен максимальный объем среди цилиндров и конусов.
4. Вывести информацию о конусах, у которых площадь основания больше введенной пользователем.
5. Для цилиндров, у которых высота больше указанной пользователем, уменьшить ее на 10 процентов.


*/
class cone;
class cylinder;
class point;
class circle;


class point
{

protected:
    double x;
    double y;
public:
    point(){printf("point created\n");}
    ~point(){printf("point del\n");}
    point(double x_,double y_)
    {
        x=x_;
        y=y_;
    }

};



class circle: public point
{
private:
    double r;
public:
    circle(){printf("circle create\n");}
    circle(double x_,double y_,double r_):point(x_,y_)
    {
        r=r_;
    }
    ~circle(){printf("circly dell\n");}

    void set_r(double r_)
    {
        r=r_;
    }

    double get_r()
    {
        return r;
    }

    double dictance()
    {
        return sqrt(x*x+y*y);
    }
    

    double S()
    {
        return M_PI*r*r;
    }

    friend void output(cylinder *obj);
    friend void output(cone *obj);
};





class cylinder:public circle
{
private:
   
public:

    double h;

    cylinder () {printf("celinder created\n");}
    ~cylinder (){printf("cylinder del\n");}

    cylinder(double x_,double y_,double r_,double h_)
    {
        x=x_;
        y=y_;
        set_r(r_);
        h=h_;
    }

    double V()
    {
        return S()*h;
    }


};

class cone:public circle
{
private:
    

public:
    double h;
    cone() {printf("cone created\n");}
    ~cone() {printf("cone del\n");}

    cone(double x_,double y_,double r_,double h_):circle(x_,y_,r_)
    {
        h=h_;
    }

    double V()
    {
        return S()*h/3;
    }
};

void output(cylinder *obj)
{
    printf("cylinder x=%lf y=%lf r=%lf h=%lf\n S=%lf V=%lf\n",obj->x,obj->y,obj->r,obj->h, obj->S(),obj->V());
}

void output(cone *obj)
{
    printf("cone x=%lf y=%lf r=%lf h=%lf\n S=%lf V=%lf\n",obj->x,obj->y,obj->r,obj->h, obj->S(),obj->V());
}

void t1(cylinder**& a,int &n)
{
    FILE *f= fopen("cylinder.txt","r");
    if (f==NULL)
    {
        printf("file not exist\n");
        return ;
    }
    char str[100];
    n=0;
    while (fgets(str,100,f))
    {
        n++;   
    }
    if (n==0)
    {
        printf("file is empty");
        return ;
    }
    rewind(f);
    a=new cylinder*[n];

    double x_; double y_; double r_; double h_;
    for (int i = 0; i < n; i++)
    {
        fscanf(f,"%lf%lf%lf%lf",&x_,&y_,&r_,&h_);
        a[i]= new cylinder(x_, y_, r_, h_);
        output(a[i]);
    }

}


void t2(cone **&b,int &n)
{
    printf("\n\n\n");
    FILE *f= fopen("cone.txt","r");
    if (f==NULL)
    {
        printf("file not exist\n");
        return ;
    }
    char str[100];
    n=0;
    while (fgets(str,100,f))
    {
        n++;   
    }
    if (n==0)
    {
        printf("file is empty");
        return ;
    }
    rewind(f);
    b=new cone*[n];

    double x_; double y_; double r_; double h_;
    for (int i = 0; i < n; i++)
    {
        fscanf(f,"%lf%lf%lf%lf",&x_,&y_,&r_,&h_);
        b[i]= new cone(x_, y_, r_, h_);
        output(b[i]);
    }
}


void t3(cylinder **a,int n, cone **b,int n2)
{
    printf("\n\n\n");

    double v_m=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]->V()>v_m) v_m=a[i]->V();
    }
    for (int i = 0; i < n2; i++)
    {
        if (b[i]->V()>v_m) v_m=b[i]->V();
    }
    printf("max V=%lf\n",v_m);
    
}


void t4(cone **b,int n2)
{
    printf("\n\n\ncone\n");

    double s;
    printf("4. Вывести информацию о конусах, у которых площадь основания больше введенной пользователем.\ninput s\n");
    scanf("%lf",&s);
    for (int i = 0; i < n2; i++)
    {
        if (b[i]->S() >s)
        {
            output(b[i]);
        }
    }
}


void t5(cylinder **a,int n)
{
    printf("\n\n\ncylinder\n");

    double H;
    printf("5. Для цилиндров, у которых высота больше указанной пользователем, уменьшить ее на 10 процентов.\ninput h\n");
    scanf("%lf",&H);
    for (int i = 0; i < n; i++)
    {
        if (a[i]->h>H)
        {
            a[i]->h*=0.9;
            output(a[i]);
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    int n,n2;
    cylinder **a=NULL;
    cone **b=NULL;
    t1(a,n);
    t2(b,n2);
    t3(a,n,b,n2);
    t4(b,n2);
    t5(a,n);


    for (size_t i = 0; i < n; i++)
    {
        a[i]->~cylinder();
        delete a[i];
    }
    for (size_t i = 0; i < n2; i++)
    {
        b[i]->~cone();
        delete b[i];
    }
    
    
    delete[] a;
    delete[] b;
    
    return 0;

}
