/*

Лабораторная 5б
(список двунаправленный)
Создать структуру:
-поле для записи целого числа (r);
-поле для записи адреса предыдущего элемента (prev);
- поле для записи адреса следующего элемента (next).
Указатель на последний элемент (last) и указатель на первый элемент (first)– глобальная переменная. При заполнении списка количество элементов заранее не известно. Ввести список с клавиатуры (функция), вывести список на экран как очередь (функция) и как стек (другая функция). При выводе выводить значения всех полей и адрес элемента .
Все задания оформить функциями. При выполнении заданий работать со списком как с очередью. После изменения списка выводить список и как очередь и как стек.
1. Удалить первый элемент.
2. Перед первым элементом добавить новый элемент.
3. Удалить элемент, номер которого ввел пользователь с клавиатуры.

*/

#include <iostream>
#include <string.h>


struct sp
{
    int r;
    sp*prev;
    sp*next;
};



sp*last=NULL;
sp*first=NULL;
 


void input(sp*&first,sp*&last)
{
    printf("конец ввода 'stop'\n");
    char str[50];
    sp *cur;


    if (scanf("%s",str),strcmp(str,"stop"))//первый элемент, если сразу stop-прерываем функцию
    {
        first=new sp;
        first->next=NULL;
        first->prev=NULL;
        
        first->r=atoi(str);
        last=first;
            
        
        
        while (scanf("%s",str),strcmp(str,"stop"))
        {
            cur=new sp;
            last->next=cur;
            cur->prev=last;
            cur->r=atoi(str);  
            cur->next=NULL;
            last=cur;
            
        }
    }
    else 
    {
        first=NULL;
        last=NULL;
    }
}


void output_queue (sp*first)
{
    if (first==NULL)  {printf("пусто\n");return;}
    printf("\n\n\n");
    sp*cur=first;
    while (cur!=NULL)
    {
        
        printf("%d ",cur->r);
        cur=cur->next;
    }
    printf("\n");
}

void output_queue (sp*first,int lol)
{
    if (first==NULL)  {printf("пусто\n");return;}
    printf("\n\n\n");
    sp*cur=first;
    while (cur!=NULL)
    {
        
        printf("%d %p\n",cur->r,cur);
        cur=cur->next;
    }
    printf("\n");
}

void output_stak(sp*last)
{
    if (first==NULL)  {printf("пусто\n");return;}
    printf("\n\n\n");
    sp*cur=last;
    while (cur)
    {
        printf("%d ",cur->r);
        cur=cur->prev;
    }
    printf("\n");
}

void output_stak(sp*last,int lol)
{
    if (first==NULL)  {printf("пусто\n");return;}
    printf("\n\n\n");
    sp*cur=last;
    while (cur)
    {
        printf("%d %p\n",cur->r,cur);
        cur=cur->prev;
    }
    printf("\n");
}


void t_1(sp *& first,sp *& last)
{
    if (first==NULL)  {printf("пусто\n");return;}//на всякий случай везде проверка.

    if(first->next==NULL) {delete first;first=NULL;last=NULL;}
    else
    {
        sp *old_firs=first;
        first=first->next;//даж если во втором был NULL(список из 1 элемента) просто пишем его в новый первый, иполучаеться пустой список
        first->prev=NULL;
        delete old_firs;
    }
}

void t_2(sp *& first,sp *& last)
{
    
    if (first==NULL)  {printf("пусто\n");return;}//на всякий случай везде проверка.

    sp*cur=new sp;
    first->prev=cur;
    cur->next=first;
    cur->prev=NULL;
    first=cur;
    
    printf("input new first\n");
    scanf("%d",&first->r);    
}





void t_3(sp *& first,sp *& last)
{
    if (first==NULL)  
    {
        printf("пусто\n");
        return;
    }
    
    printf("input inpdex\n");
    int index;
    scanf("%d",&index);   
    sp*cur=first;  
    int i=0;                
    while (i<index && cur!=NULL)
    {
        i++;
        cur=cur->next;
    }
    if (i==index)
    {
        printf("exist\n");

        if (index==1) 
        {
            t_1(first,last);
            printf("lol\n");
        }

        else if(cur==NULL)
        {
            last=last->prev;
            delete last->next;
            last->next=NULL;
            
        }
        else 
        {
            cur=cur->prev;
            cur->prev->next = cur->next;
            cur->next->prev=cur->prev;
            delete cur;
        }


    }
    else printf("элимент не сущ\n"); 
    
      
}


int main(int argc, char const *argv[])
{
    input(first,last);
    output_queue(first,0);
    output_stak(last,0);

    t_1(first,last);
    output_queue(first);
    output_stak(last);

    t_2(first,last);
    output_queue(first);
    output_stak(last);

    t_3(first,last);
    output_queue(first);
    output_stak(last);



    return 0;
}
