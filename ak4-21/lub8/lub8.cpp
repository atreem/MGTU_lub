/*
Лабораторная работа №8
Класс: товар (product)
Поля приватные:
- количество товара (quantity)
Поля публичные: 
- цена закупки товара (cost)
- цена продажи товара (price)
- наименование товара (name)
Конструкторы:
- Конструктор, в который передаются все параметры, кроме цены продажи. Цена продажи вычисляется по формуле (цена_закупки*1,1).
- Конструктор, в который передаются все параметры.
Методы:
- вычисление стоимости закупки всего товара;
- вычисление прибыли с одной единицы товара;
- метод заполнения приватного поля;
- метод возвращения значения приватного поля;
Дружественные функции:
- функция вывода
Задания
1. Создать одну динамическую переменную типа товар. Использовать конструктор, в который передаются все параметры. Ввод параметров с клавиатуры.
2. Создать текстовый файл, в который записана информация о нескольких товарах: наименование, количество, цена закупки товара. 
Открыть фал с проверкой, подсчитать количество товара. Создать динамический массив, используя конструктор, в котором цена продажи вычисляется.
Вывести информацию на экран (поля данных и методы).
3. Пользователь вводит наименование товара. Изменить для указанного товара количество на величину, указанную пользователем.
4. Вычислить прибыль со всех товаров.
5. Вычислить стоимость закупки всех товаров.
*/

#include <iostream>
#include <string.h>


class product
{
private:
    int quantity;
public:
    double cost=0;
    double price;
    char name[50];


    product( double _cost, int _quantity,char _name[50])
    {

        // scanf("%d%d%s",&cost,&quantity,name);
        cost=_cost;
        quantity=_quantity;
        memcpy(name,_name,50* sizeof(char));
        price=cost*1.1;
    }

    product( double _cost, int _quantity,char _name[50],double _price)
    {
        cost=_cost;
        quantity=_quantity;
        memcpy(name,_name,50* sizeof(char));
        price=_price;
        // scanf("%d%d%s%d",&cost,&quantity,name,&cost);
    }

    ~product()
    {
        printf("el delet\n");
    }


    double cost_all()
    {
        return cost*quantity;
    }

    double profit()
    {
        return price-cost;
    }

    int r_quantity(){return quantity;}
    void w_quantity(int q){quantity=q;}
    friend void output(product * pr);
    
};

void output(product*pr)
{
    //         scanf("%d%d%s%d",&cost,&quantity,name,&cost);
    printf("cost=%lf quantity=%d name=%s prise=%lf all_cost=%lf profit=%lf\n",pr->cost,pr->quantity,pr->name,pr->price,pr->cost_all(),pr->profit());
}



void t1()
{
    // 1 2 lol 5
    printf("\n\n\nt1\n");
    printf("input  cost quantity neme price\n");
    double _cost,_price;
    int _quantity;
    char _name[50];
    scanf("%lf%d%s%lf",&_cost,&_quantity,_name,&_price);
    product *pr=new product(_cost,_quantity,_name,_price);
    output(pr);

    pr->~product();
}

// void t2(product**pr,int &n)
// {
   
    
// }


void t3(product**pr,int &n)
{
    printf("\n\n\nt3\ninput name and new quantity\n");
    bool flag=0;
    char _name[50];
    int q;
    scanf("%s%d",_name,&q);
    printf("%d\n",q);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(pr[i]->name,_name)==0)
        {
            flag=1;
            pr[i]->w_quantity(q);
        }
        output(pr[i]);
    }
    if (flag==0) printf("not found\n");
}



void t4(product**pr,int &n)
{
    double sum=0;
    printf("\n\n\nt4\n");
    for (int  i = 0; i < n; i++)
    {
        sum+=pr[i]->profit()*pr[i]->r_quantity();
    }
    printf("full profit=%lf\n",sum);
}


void t5(product**pr,int &n)
{
    printf("\n\n\nt5\n");
    double cost_all=0;
    for (int i = 0; i < n; i++)
    {
        cost_all+=pr[i]->cost_all();
    }
    printf("cost_all=%lf\n",cost_all);
}


int main(int argc, char const *argv[])
{
    t1();
    product**pr=NULL;
    int n;
   //t2
   printf("\n\n\nt2\n");
   FILE *f=fopen("lub8.txt","r");
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
       return 0;
   }
   rewind(f);
   int _quantity;
   double _cost;
   char _name[50];
   pr=new product*[n];
   for (int i = 0; i < n; i++)
   {
       fscanf(f,"%lf%d%s",&_cost,&_quantity,_name);
       pr[i]= new product(_cost,_quantity,_name);
   }
   
   for (int i = 0; i < n; i++)
   {
       output(pr[i]);
   }
    if (pr==NULL) return 0;
   fclose(f);
    //t2
    t3(pr,n);
    t4(pr,n);
    t5(pr,n);


    for (int i = 0; i < n; i++)
    {
        pr[i]->~product();
    }
    delete pr;
    return 0;

}

