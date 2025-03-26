/*
Лабораторная 5а
(список стек)
Создать структуру:
-поле для записи целого числа (r);
-поле для записи адреса предыдущего элемента (prev).
Указатель на последний элемент (last)– не глобальная переменная. При заполнении списка количество элементов заранее не известно. Ввести список с клавиатуры (функция), вывести список на экран (функция)-вывести значения всех полей и адрес элемента.
Все задания оформить функциями.
1. Удалить первый введенный элемент. 
2. Удалить последний введенный элемент.

*/

#include <iostream>


struct sp
{
    int r;
    sp* prev;
};


void input(sp *&last)
{
    printf("введитет кол-во элиментов\n");
    int count;
    scanf("%d",&count);
    if (count)
    {
        last=new sp;
        last->prev=NULL;
        printf("input el 1\n");
        scanf("%d",&last->r);
        sp*_prev;
        for (int i = 1; i < (count); i++)
        {  
            _prev=last;
            last=new sp;
            last->prev=_prev;          
            printf("input el %d\n",i+1);
            scanf("%d",&last->r);
        }
    }
    else last=NULL;
}


void output(sp*last)
{
    printf("\n\n\n");
    sp*cur=last;
    while (cur)
    {
        printf("%d %p\n",cur->r,cur);
        cur=cur->prev;
    }
}


void t_1(sp*&last)
{
    sp *first =last;
    sp*second;
    while (first->prev!=NULL)
    {
        second=first;
        first=first->prev;
    }

    second->prev=NULL;
    delete first;
}

void t_2(sp*& last)
{
    sp*new_last=last->prev;
    delete last;
    last=new_last;
}



int main(int argc, char const *argv[])
{
    sp*last=NULL;
    input(last);
    if (last!=NULL)
    {
        output(last);

        t_1(last);output(last);
        t_2(last);output(last);
    }
    else printf("пустой список\n");



    return 0;
}
