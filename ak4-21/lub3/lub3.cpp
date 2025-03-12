#include <iostream>
#include <string.h>

/*
Лабораторная №3. Список очередь 1часть.
Список очередь (first) содержит информационные поля фамилия (fam)
 и номер группы (gr), поле ссылку на следующий элемент (next).
Размер списка заранее не известен. При вводе каждый раз спрашивать,
 будет ли пользователь вводить следующий элемент. Ввести список.
Вывести список (вывести значения всех полей и адрес элемента).

1. Пользователь вводит номер группы, вывести фамилии студентов,
 которые учатся в указанной группе.

2. Подсчитать количество студентов, фамилия которых начинается на букву «А».

3. Для всех студентов, который учатся в 1 группе,
 поменять номер группы на введенную пользователем.

4. Сохранить в переменную «four» и вывести на экран адрес элемента,
 который располагается в списке четвертым.

5. Сохранить в переменную «last» и вывести на экран адрес элемента,
 который располагается в списке последним.
*/




struct  sp
{
    char fam[50];
    int gr;
    sp *next;

};

sp *first=NULL;

void input()
{


    
    char str[50];
    int a;


    printf("окончание ввода сивол '0'\n");

    bool flag=0;
    if(scanf("%s%d",str,&a),(strcmp(str,"0\0")!=0 && a!=0))
    {
        first=new sp;
        strcpy(first->fam,str);
        first->gr=a;
        first->next=NULL;
        flag=1;
    }
   
    sp *cur;
    sp *last=first;
    if (flag)
    {
        while(scanf("%s%d",str,&a),(strcmp(str,"0\0")!=0 && a!=0))
        {
            cur=new sp;
            strcpy(cur->fam,str);
            cur->gr=a;
            last->next=cur;
            cur->next=NULL;
            last=cur;
        }
    }
}


void output(sp * now)
{
    while (now!=NULL)
    {
        printf("%s %d\n",now->fam,now->gr);
        now=now->next;
    }
    
}


void f_first(sp*first)
{
    printf("(1)input gup ");
    int gr;
    scanf("%d",&gr);
    bool flag=1;
    while (first!=NULL)
    {
        if(first->gr==gr)
        {
            printf("%s\n",first->fam);flag=0;
        }
        first=first->next;
    }
    if(flag)printf("not find\n");
}
void second(sp*first)
{
    int count=0;
    while (first!=NULL)
    {
        if(first->fam[0]=='A')//engl
        {
            count++;
        }
        first=first->next;
    }
    printf("(2)start by A:%d\n",count);
}
void therd(sp*first)
{
    printf("(3)input new gr\n");
    int gr;
    scanf("%d",&gr);
    while (first!=NULL)
    {
        if(first->gr==1)
        {
            first->gr=gr;
        }
        first=first->next;
    }
    
}
void fourth(sp*first,sp**four)
{
    int i=0;
    while (first!=NULL&&i<3){first=first->next;i++;}
    if (i!=3){
        printf("(4)error len\n");
        return;
    }
    *four=first;
    printf("(4)%p %s\n",four,(*four)->fam);   
}
void fith(sp*first,sp**last)
{

    if(first!=NULL)    {do{*last=first;first=first->next;}while (first!=NULL);printf("(5)%p %s\n ",*last,(*last)->fam);   }
    else {first=NULL;printf("no element");}
    
    
}





int main(int argc, char const *argv[])
{

    
    input();
    output(first);   
    
    f_first(first);
    second(first);
    therd(first);
    output(first);
    sp*four;
    fourth(first,&four);
    sp*last;
    fith(first,&last);
    std::cout<<last;

    return 0; 
}
/*
Alone 1
two 2
three 3
four 4
five 5
six 6
seven 7
eight 8
second_one 1
0 0
*/