/*
Лабораторная №2 (структуры)
Создать структуру product включающую поля:
- название товара (name)
- цена одного товара (price)
- количество товара (number)
1. Создать локальную переменную типа product. Ввести с клавиатуры значение всех полей, вывести на экран поля переменной.
2. Создать динамическую переменную типа product. Ввести с клавиатуры значение всех полей, вывести на экран поля переменной.
3. Создать текстовый файл. Информацию о нескольких товарах записать в текстовый файл. Открыть файл с проверкой, подсчитать количество записей(n). Создать динамический массив продуктов. Заполнить его информацией из файла.
3.1 Вычислить стоимость всех товаров.
3.2 Для каждого наименования товара вычислить стоимость (цена*количество).
3.3 Пользователь вводит название товара, вывести цену и количество введенного товара.
3.4 Вывести наименования товаров, количество которых минимальное из всех.
*/
#include <iostream>
#include <string.h>

struct product
    {
        char name[15];
        int price;
        int number;
    };

void input(product &pr)
{
    
    printf("input name(<15),price and number of product\n");
    scanf("%s%d%d",&pr.name,&pr.price, &pr.number);
}

void output(product pr)
{
    printf("name=%s price=%d number=%d\n",pr.name,pr.price, pr.number );
}

int main(int argc, char const *argv[])
{
    //1
    setlocale(LC_CTYPE,"Russian");
    product pr1;
    input(pr1);
    output(pr1);

    //2
    product * pr2=new product;
    input(*pr2);
    output(*pr2);

    //3
    FILE *f= fopen("lub2.txt","r");
    if(f==NULL) 
    {
        printf("no such file\n");
        return 0;
    }
    int n=0;
    char str[100];
    while (fgets(str,100,f))
    {
        n++;
    }
    printf("n=%d\n\n",n);
    rewind(f);

    product *by_file=new product[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(f,"%s%d%d",&by_file[i].name,&by_file[i].price, &by_file[i].number);
        output(by_file[i]);
    }


    //3.1
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=by_file[i].number*by_file[i].price;
    }
    printf("\n\ntoatl price = %d\n\n\n",sum);
    //3.2
    
    for (int i = 0; i < n; i++)
    {
        sum=by_file[i].number*by_file[i].price;
        printf("%s total price = %d\n",by_file[i].name,sum);
    }

    //3.3
    printf("input product name\n");
    scanf("%s",str);
    printf("%s",str);
    bool found=0;
    for (int i = 0; i < n; i++)
    {
        if(strcmp(str,by_file[i].name)==0)
        {
            printf(" price=%d number=%d",by_file[i].price,by_file[i].number);
            found=1;
        }
    }
    if(found==0)printf(" not found\n");
    //3.4  
    printf("\n\n\n");
    int min=by_file->number; 
        for (int i = 0; i < n; i++)
    {
        if (min>by_file[i].number)
        {
            min=by_file[i].number;
        }
    }
    printf("\nmin count %d:\n",min);
    for (int i = 0; i < n; i++)
    {
        if (min==by_file[i].number)
        {
            output(by_file[i]);
        }
    }
    return 0;
}
