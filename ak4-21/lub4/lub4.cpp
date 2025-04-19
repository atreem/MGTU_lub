/*
Лабораторная 4
(список очередь, вторая часть)
Создать структуру:
-поле для записи целого числа (r);
-поле для записи адреса следующего элемента (next).
Указатель на первый элемент – не глобальная переменная. При заполнении списка количество элементов заранее не известно. Ввести список с клавиатуры (функция), вывести список на экран (функция).
Все задания оформить функциями.
1. Удалить первый элемент. 
2. После последнего элемента добавить два новых элемента.
3. Перед первым элементом добавить новый элемент.
4. Удалить элемент, номер которого ввел пользователь с клавиатуры.
5. После элемента, номер которого ввел пользователь с клавиатуры, добавить новый элемент, равный десяти.
6. Удалить из списка элементы, равные введенному пользователем числу.

`*/
#include <iostream>
#include <string.h>

struct sp
{
    int r;
    sp* next;
};


void input(sp*&first)
{
    printf("конец ввода 'stop'\n");
    char str[50];
    sp *last,*cur;


    if (scanf("%s",str),strcmp(str,"stop"))//первый элемент
    {
        first=new sp;
        first->next=NULL;
        first->r=atoi(str);
        
    }
    else return;//если сразу stop-прерываем функцию
    
    last=first;
    
    while (scanf("%s",str),strcmp(str,"stop"))
    {
        cur=new sp;
        last->next=cur;
        cur->r=atoi(str);  
        cur->next=NULL;
        last=cur;
        
    }
    
}

void output(sp*first)
{
    sp*now=first;
    while (now!=NULL)
    {
        printf("%d\n",now->r);
        now=now->next;
    }
}

void t_1(sp *& first)
{
    if (first==NULL)  {printf("пусто\n");return;}//на всякий случай везде проверка.
    sp *old_firs=first;
    first=first->next;//даж если во втором был NULL(список из 1 элемента) просто пишем его в новый первый, иполучаеться пустой список
    delete old_firs;
}

void t_2(sp *& first)
{
    if (first==NULL)  {printf("пусто\n");return;}
    sp*now=first;
    while (now->next!=NULL)//находим полседний не NULL элемент 
    {
        now=now->next;
    }
    //скопировал из ввода
    sp *last,*cur;
    last=now;
    char str[50];
    for (int i = 0; i < 2; i++)
    {
        printf("input new el\n");
        cur=new sp;
        last->next=cur;
        // cur->r=atoi(str);  
        scanf("%d",&cur->r);
        cur->next=NULL;
        last=cur;
    }
    
}

void t_3(sp*&first)
{
    if (first==NULL)  {printf("пусто\n");return;}
    sp*new_first=new sp;
    printf("input new first el\n");
    scanf("%d",&new_first->r);
    new_first->next=first;
    first=new_first;
}

void t_4(sp*&first)
{
    if (first==NULL)  {printf("пусто\n");return;}
    printf("input number\n");
    int num;
    scanf("%d",&num);
    sp*now=first;
    sp*last;
    int i=0;
    // находим нужный элемент, если до него возникает NULL(конец) или он сам является NULL(конец) прирываем перед сложением(i++)
    while (now->next!=NULL)
    {
        i++;
        if (i==num) break;
        last=now;
        now=now->next;
    }
    
    if (num==1) 
    {
        t_1(first);//функция удаления первого элимента
    }

    else if (i==num)
    {
        last->next=now->next;//если всё норм
    }
    
    else printf("no elem\n");//елси i!=num

}

void t_5(sp*&first)
{
    if (first==NULL)  {printf("пусто\n");return;};
    printf("input nuber\n");
    int num;
    scanf("%d",&num);

    sp*now=first;
    int i=0;
    
    while (now->next!=NULL)
    {
        i++;
        if (i==num) break;
        now=now->next;
    }

    if (i==num)
    {
        sp*dop=new sp;
        dop->r=10;
        dop->next=now->next;
        now->next=dop;
    }
    
    else printf("no elem\n");
}

void t_6(sp*&first)
{
    if (first==NULL)  {printf("пусто\n");return;};
    printf("какое число удалить\n");
    int num;
    scanf("%d",&num);

    // проверяем не являеться ли первый элимент нужным нам
    // если все элименты подходят,то по окончанию(NULL) прирываем функцию
    while (first!=NULL&&first->r==num)
    {
        t_1(first);
    }
    if (first==NULL) {printf("пусто\n");return;}
    sp*last=first;
    sp*now=first->next;
    
    while (now!=NULL)
    {
        if(now->r==num)
        {
            last->next=now->next;
            now=last->next;
        }
        else 
        {
            last=now;
            now=now->next; 
        }

    }
    
}

int main(int argc, char const *argv[])
{
    sp * first=NULL;
    input(first);
    if (first!=NULL)
    {
        output(first);
        printf("\n\n\n1)\n"); t_1(first); printf("\n"); output(first);
        printf("\n\n\n2)\n"); t_2(first); printf("\n"); output(first);
        printf("\n\n\n3)\n"); t_3(first); printf("\n"); output(first);
        printf("\n\n\n4)\n"); t_4(first); printf("\n"); output(first);
        printf("\n\n\n5)\n"); t_5(first); printf("\n"); output(first);
        printf("\n\n\n6)\n"); t_6(first); printf("\n"); output(first);

    }
    else
    {
        printf("список пуст");
    } 
    return 0;
}