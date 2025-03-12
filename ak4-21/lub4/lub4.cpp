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
    
    

    if (scanf("%s",str),strcmp(str,"stop"))
    {
        first=new sp;
        first->next=NULL;
        first->r=atoi(str);
        
    }
    // else return;
    
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
    if (first==NULL)  {printf("пусто\n");return;};
    sp *old_firs=first;
    first=first->next;
    delete old_firs;
}

void t_2(sp *& first)
{
    if (first==NULL)  {printf("пусто\n");return;};
    sp*now=first;
    while (now->next!=NULL)
    {
        now=now->next;
    }

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
    if (first==NULL)  {printf("пусто\n");return;};
    sp*new_first=new sp;
    printf("input new first el\n");
    scanf("%d",&new_first->r);
    new_first->next=first;
    first=new_first;
}

void t_4(sp*&first)
{
    if (first==NULL)  {printf("пусто\n");return;};
    printf("input number\n");
    int num;
    scanf("%d",&num);
    sp*now=first;
    sp*last;
    int i=0;
    
    while (now->next!=NULL)
    {
        i++;
        if (i==num) break;
        last=now;
        now=now->next;
    }
    
    if (num==1) 
    {
        t_1(first);
    }

    else if (i==num)
    {
        last->next=now->next;
    }
    
    else printf("no elem\n");

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