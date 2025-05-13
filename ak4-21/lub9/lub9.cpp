/*
Лабораторная №9. Наследование.
Класс транспорт (transport)
Поля private:
-название (name);
Поля protected:
- цена закупки товара (cost)
- цена продажи товара (price)
Конструктор:
-конструктор, в который передаются значения всех полей;
- конструктор без параметров;
Дружественные функции:
- функция вывода на экран объекта класса машина;
- функция вывода на экран объекта класса автобус;

Класс машина (car), потомок от класса транспорт
Поля public:
- год изготовления (year);
- количество (quantity);
Конструктор:
-конструктор, в который передаются значения всех полей, конструктор класса родителя вызывается явным образом;
Методы:
- функция вычисления прибыли от продажи всех машин (profit_all);

Класс автобус (bus), потомок от класса транспорт
Поля public:
- количество мест в автобусе (col);
Конструктор:
-конструктор, в который передаются значения всех полей, конструктор класса родителя вызывается не явным образом;
Методы:
- функция вычисления прибыли от продажи одного автобуса (profit);

Задания
1. Создать один локальный объект класса транспорт, использовать конструктор с параметрами.
2. Создать один динамический объект класса машина.
3. Ввести с клавиатуры или из файла динамический объект класса автобус.
4. Вывести всю информацию об автобусах, в которых количество мест больше введенного пользователем.




*/

#include <iostream>

class car;
class bus;

class transport
{
private:
    char name[50];

protected:
    double cost;
    double price;



public:
    char *get_name()
    {
        return name;
    }
    void set_name(char name_[50])
    {
        memcpy(name,name_,sizeof(char)*50);
    }

    transport(/* args */)
    {
    }

    transport(char name_[50],double cost_,double price_)
    {
        memcpy(name,name_,sizeof(char)*50);
        cost=cost_;
        price=price_;
    }


    ~transport()
    {
    }
    friend void output(transport * t);
    friend void output(bus * b);
    friend void output(car * c);
    
};



class car : public transport
{
private:
    /* data */
public:
    
    int year;
    int quantity;
    int profit_all()
    {
        return (-cost+price)*quantity;
    }



    car(/* args */);
    ~car();
    car(char name_[50],double cost_,double price_,int year_,int quantity_):transport( name_, cost_, price_)    {
        year=year_;
        quantity=quantity_;
        
    }
};

car::car(/* args */)
{
}

car::~car()
{
}






class bus :public transport
{
private:
    /* data */
public:
    int col;
    int porfir(){return -cost+price;}

    bus(char name_[50],double cost_,double price_,int col_){set_name(name_); cost=cost_;price=price_; col=col_;}
    
    bus(/* args */);
    ~bus();
};


bus::bus(/* args */)
{
}

bus::~bus()
{
}







void output(transport * t)
{
    
    printf("name=%s cost=%lf price=%lf\n",t->name,t->cost,t->price);
}
void output(bus * b)
{
    printf("name=%s cost=%lf price=%lf col=%d\n" , b->name,b->cost,b->price,b->col);

}
void output(car * c)
{
    printf("name=%s cost=%lf price=%lf year=%d quantity=%d\n",c->name,c->cost,c->price,c->year,c->quantity);

}






void t1()
{
    printf("input transport\n");
    char name_[50];double cost_;double price_;
    scanf("%s%lf%lf",name_,&cost_,&price_);
    transport t=transport( name_, cost_, price_);
    output(&t);

}

void t2()
{
    printf("input car \n");
    char name_[50];double cost_;double price_;int year_;int quantity_;
    scanf("%s%lf%lf%d%d",name_,&cost_,&price_,&year_,&quantity_);
    car *c= new car( name_, cost_, price_, year_, quantity_);
    output(c);
}



void t3(bus **b,int&n)
{
    printf("\n\n\nt3\n");
    FILE *f=fopen("lub9.txt","r");
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
    b=new bus *[n];
    for (int i = 0; i < n; i++)
    {
        char name_[50];double cost_;double price_;int col_=-1;
        fscanf(f,"%s%lf%lf%d",name_,&cost_,&price_,&col_);
        b[i]= new bus( name_, cost_, price_, col_);
        output(b[i]);
    }
}








void t4(bus ** b,int n)
{
    printf("input kol-vo mest\n");
    int mest;
    scanf("%d",&mest);
    for (int i = 0; i < n; i++)
    {
        if((b[i]->col)>(mest))
        {
             output(b[i]);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    /* code */
    t1();
    t2();
    bus **b;
    int n;
    // t3(b,n);
    printf("\n\n\nt3\n");
    FILE *f=fopen("lub9.txt","r");
    if (f==NULL)
    {
        printf("file not exist\n");
        return 0;
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
        return 0 ;
    }
    rewind(f);
    b=new bus *[n];
    for (int i = 0; i < n; i++)
    {
        char name_[50];double cost_;double price_;int col_=-1;
        fscanf(f,"%s%lf%lf%d",name_,&cost_,&price_,&col_);
        b[i]= new bus( name_, cost_, price_, col_);
        output(b[i]);
    }
    t4(b,n);
   





    return 0;
}

