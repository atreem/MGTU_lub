#include <string.h>
#include <iostream>

/*
1)сформировать список очередь целл чисел
определить кол-во эль и сумм кратных 3
вывести кратные 3 и их сумму.
2)сформировать стек из слов с клавы(не более 15 байт)
вывести
найти все слов на гласную букву
если таких нет вывести сообщение.
*/
void one()
{

    struct elem
    {
        int num;
        elem *next;
    };
    char input[10];

// firtst element
    printf("input elsements\n");
    elem *first=new elem;
    first->num=atoi(fgets(input,10,stdin));
    first->next=NULL;   

//other elements
    elem * cur;
    while (fgets(input,10,stdin),(strlen(input)!=1))
    {
        cur=new elem;
        cur->next=first;
        cur->num=atoi(input);
        first=cur;
    }
//multiples of three and their sum
    //printf("\n\n\n mult of 3:");
    int sum=0;
    elem * now = cur;
    
    while ((now != NULL))
    {
        if (now->num%3==0)
        {
            printf("%d ",now->num);
            sum+=now->num;
        }
        now=now->next;
    } 
    printf("\nsum =%d\n",sum);
    /*
    1
    2
    3
    4
    5
    6
    7
    8
    9

    */
}

/*
2)сформировать стек из слов с клавы(не более 15 байт)
вывести
найти все слов на гласную букву
если таких нет вывести сообщение.
*/
void two()
{
    struct elem
    {
        char word[15];
        elem *next;
    };
    
// firtst element
    printf("input words\n");
    elem *first=new elem;
    fgets(first->word,15,stdin);
    first->next=NULL;
    elem * last = first;

//other elements
    elem * cur;
    while (cur=new elem,fgets(cur->word,15,stdin),(strlen(cur->word)!=1))
    {
            last->next=cur;
            cur->next=NULL;
            last=cur;
    }
//output
    bool found=false;
    cur=first;
    char alf[25]="eyuoiaуеыаоэяию";
    
    char sim;
    while (cur!=NULL)
    {
        if (isalpha(cur->word[0]));
        {
            sim=tolower(cur->word[0]);
            for (int i = 0; i < 25; i++)
            {
                if(alf[i]==sim)
                {
                    printf("%s",cur->word);
                    found=true;
                }               
            }
        }    
        cur=cur->next;
    }
    if(!found)    printf("can`t find any string\n");
}


int main(int argc, char const *argv[])
{
    one();
    two();
    return 0;
}

