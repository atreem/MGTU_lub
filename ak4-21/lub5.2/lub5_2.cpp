#include <iostream>
#include <string.h>
/*
двунаправленные список
кол-во известно
вывод как список и как очередь 

фамилия группа оценка_за_егэ

1)по фамилии  всё информации
2)найти макс бал за егэ
3)добавить новый элемент в конец
4)в файл записать всё инфу о студентах из указанной группы 
5)удалить из списка людей у которых балл за егэ меньше введённого с клавиатуры (на потом мб)
6)поменять местами 1 и последний эл


6
a 10 1 
b 20 2
c 30 3
d 40 4 
e 50 5
a 60 6
*/

struct sp
{
    sp*prev;
    sp*next;
    
    char surname[30];
    int grup;
    int mark;
};


void input(sp*&first,sp*&last)
{
    printf("input count\n");
    int count;
    scanf("%d",&count);

    if(count>0)
    {
        first=new sp;
        first->prev=NULL;
        first->next=NULL;
        printf("введите фамилия група оценка_за_егэ\n");
        scanf("%s%d%d",first->surname,&first->grup,&first->mark);
    }
    sp * cur=NULL;
    sp*_prev_=first;
    
    for (int i = 0; i < count-1; i++)
    {
        cur=new sp;
        cur->prev=_prev_;
        _prev_->next=cur;
        _prev_=cur;
        cur->next=NULL;
        printf("введите фамилия група оценка_за_егэ\n");
        scanf("%s%d%d",cur->surname,&cur->grup,&cur->mark);
    }

    last=cur;
}




void output_queue (sp*first)
{
    if (first==NULL)  {printf("пусто\n");return;}
    printf("\n\n\n");
    sp*cur=first;
    while (cur!=NULL)
    {
        printf("%s %d %d prev%p адрес %p next %p\n",cur->surname,cur->grup,cur->mark,cur->prev,cur,cur->next);
        
        cur=cur->next;
    }
    printf("\n");
}

// void output_queue (sp*first,int lol)
// {
//     if (first==NULL)  {printf("пусто\n");return;}
//     printf("\n\n\n");
//     sp*cur=first;
//     while (cur!=NULL)
//     {
        
//         printf("%d %p\n",cur->r,cur);
//         cur=cur->next;
//     }
//     printf("\n");
// }

void output_stak(sp*last)
{
    if (last==NULL)  {printf("пусто\n");return;}
    printf("\n\n\n");
    sp*cur=last;
    while (cur)
    {
        printf("%s %d %d\n",cur->surname,cur->grup,cur->mark);
        cur=cur->prev;
    }
    printf("\n");
}

// void output_stak(sp*last,int lol)
// {
//     if (first==NULL)  {printf("пусто\n");return;}
//     printf("\n\n\n");
//     sp*cur=last;
//     while (cur)
//     {
//         printf("%d %p\n",cur->r,cur);
//         cur=cur->prev;
//     }
//     printf("\n");
// }



void t1(sp*first,sp*last)
{
    printf("input surname\n");
    char _surname_[30];
    scanf("%s",_surname_);
    sp*cur=first;
    while (cur!=NULL)
    {
        if (strcmp(cur->surname,_surname_)==0)      
        {
            printf("%s %d %d\n",cur->surname,cur->grup,cur->mark);
        }
        
        cur=cur->next;
    }
    printf("\n\n\n");
}

void t2(sp*first,sp*last)
{
    sp*cur=first;
    int max_mark;
    while (cur!=NULL)
    {
        if (cur->mark>max_mark)
        {
            max_mark=cur->mark;
        }
        cur=cur->next;
    }
    
    printf("max mark=%d\n\n\n\n",max_mark);
}

void t3(sp *&first,sp*&last)
{
    sp*new_last=new sp;
    new_last->next=NULL;
    new_last->prev=last;
    last->next=new_last;
    last=new_last;

    printf("введите фамилия група оценка_за_егэ\n");
    scanf("%s%d%d",last->surname,&last->grup,&last->mark);
    output_queue(first);
    output_stak(last);
}



void t4(sp*&first,sp*&last)
{
    printf("input grup\n");
    int grup;
    scanf("%d",&grup);
    sp*cur=first;
    FILE *f=fopen("lub5_2.txt","w");
    while (cur!=NULL)
    {
        if (cur->grup==grup)
        {
            fprintf(f,"%s %d %d\n",cur->surname,cur->grup,cur->mark);
        }
        cur=cur->next;
    }
    
}



void dell_el(sp *& first,sp *& last,sp* el)
{
    
    if (el!=NULL)
    {
        printf(el->surname);
        printf("exist\n");

        if (el==first) 
        {
            if(first->next==NULL) {delete first;first=NULL;last=NULL;}
            else
            {
                sp *old_firs=first;
                first=first->next;//даж если во втором был NULL(список из 1 элемента) просто пишем его в новый первый, иполучаеться пустой список
                first->prev=NULL;
                delete old_firs;
            }
        }

        else if(el->next==NULL)
        {
            last=last->prev;
            delete last->next;
            last->next=NULL;
            
        }
        else 
        {
            el=el->prev;
            el->prev->next = el->next;
            el->next->prev=el->prev;
            delete el;
        }


    }
     
}

void t5(sp*&first,sp*&last)
{
    printf("input min mark\n");
    int min_mark;
    scanf ("%d",&min_mark);
    sp*cur=first;
    sp*cur_copy;
    while (cur!=NULL)
    {
        if(cur->mark<min_mark)
        {
            cur_copy=cur;
            cur=cur->next;
            dell_el(first,last,cur_copy);
        }
        else
        {
            cur=cur->next;
        }
    }
    output_queue(first);
    output_stak(last);
}



void t6(sp*first,sp*last)
{
    if (first!=last)
    {
        sp *swap;
        first->next->prev=last;
        last->prev->next=first;
        first->prev=last->prev;
        last->next=first->next;
        last->prev=NULL;
        first->next=NULL;
        swap=first;
        first=last;
        last=swap;
    }
    output_queue(first);
    output_stak(last);
}

int main(int argc, char const *argv[])
{
    sp*first;
    sp*last;
    input(first,last);

    output_queue(first);
    output_stak(last);
    
    t1(first,last);
    t2(first,last);
    t3(first,last);
    t4(first,last);
    t5(first,last);
    t6(first,last);
    return 0;
}
