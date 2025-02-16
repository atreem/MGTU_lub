#include <iostream>
/*Файл имеет структуру:

Фамилия

Имя

Группа(целоле число)

оценки(4шт) за сессию

открыть файл с проверкой подсчитать кол-во строк/ записей
создать динамический массив для записи фамилий "surname"(farm) кол-во записей - количество строк каждая строка из массива символов(20 симв)

аналогично динам массив имен (name) 
 одномерн динам массив для записи групп(gr)
 и двумерный динам массив для записи оценок (marc)
 
в стороке 20 сим
 */

 void input(int n,FILE *f,char **&name,char **&farm,int **&mark,int *&gr)
 {
    for (int i = 0; i < n; i++)
    {
        fscanf(f,"%s %s %d %d %d %d %d",farm[i],name[i],&gr[i],&mark[i][0],&mark[i][1],&mark[i][2],&mark[i][3]);
        printf ("%s %s %d %d %d %d %d\n",farm[i],name[i],gr[i],mark[i][0],mark[i][1],mark[i][2],mark[i][3]);
    }
 }

void first(int n,FILE *f,char **&name,char **&farm,int **&mark,int *&gr)//. Вывести на экран и записать в новый файл фамилии и имена студентов, у которых нет двоек.
{
    printf("\nstuden without 2:\n");
    FILE *out=fopen("lub1_out.txt","w");
    for (int i = 0; i < n; i++)
    {
        if (mark[i][0]!=2&&mark[i][1]!=2&&mark[i][2]!=2&&mark[i][3]!=2)
        {   
            printf ("%s %s %d %d %d %d %d\n",farm[i],name[i],gr[i],mark[i][0],mark[i][1],mark[i][2],mark[i][3]);
            fprintf (out,"%s %s %d %d %d %d %d\n",farm[i],name[i],gr[i],mark[i][0],mark[i][1],mark[i][2],mark[i][3]);
        }
    }   
}


void second (int n,FILE *f,char **&name,char **&farm,int **&mark,int *&gr)//Пользователь вводит с клавиатуры номер группы, вывести всю информацию о студентах, которые учатся в этой группе.
{
    printf("\ninput index of grup\n");
    int grub;
    bool flag=0;
    scanf("%d",&grub);
    for (int i = 0; i < n; i++)
    {
        if (grub==gr[i])
        {
            printf ("%s %s %d %d %d %d %d\n",farm[i],name[i],gr[i],mark[i][0],mark[i][1],mark[i][2],mark[i][3]);flag=1;
        }
    }
    if (!flag) {printf("grup not fuond\n");}
}

void third(int n,FILE *f,char **&name,char **&farm,int **&mark,int *&gr)//. Вывести на экран всю информацию о студентах, у которых за сессию только четверки и пятерки
{
    printf("\nstudentss with only 5 and 4:\n");
    {
        /* data */
    };
    
    for (int  i = 0; i < n; i++)
    {
        if ((mark[i][0]-3>0)&&(mark[i][1]-3>0)&&(mark[i][2]-3>0)&&(mark[i][3]-3>0))
        {
            printf ("%s %s %d %d %d %d %d\n",farm[i],name[i],gr[i],mark[i][0],mark[i][1],mark[i][2],mark[i][3]);
        }
    }
    
}

void     fourth(int n,FILE *f,char **&name,char **&farm,int **&mark,int *&gr)//Найти максимальный средний балл студентов.
{
    int max,max_index,sr;
    max=0;
    for (int i = 0; i < n; i++)
    {
        sr=(mark[i][0]+mark[i][1]+mark[i][2]+mark[i][3]-3)/2;
        if (sr>max)
        {
            max=sr;
            max_index=i;
        }
    }
    printf ("%s %s %d %d %d %d %d\n",farm[max_index],name[max_index],gr[max_index],mark[max_index][0],mark[max_index][1],mark[max_index][2],mark[max_index][3]);
}


#include <iostream>
int main(int argc, char const *argv[])
{
    FILE *f = fopen("lub1.txt","r");
    int n=0;
    char str [100];
    while (fgets(str,100,f))
    {
        n++;
    }
    rewind(f);
    printf("%d\n",n);
    char **name=new char*[n];
    char **farm=new char*[n];
    int **mark=new int *[n];
    for (int i = 0; i < n; i++)
    {
        name[i]=new char[20];
        farm[i]=new char[20];
        mark[i]=new int[4];
    }
    int *gr=new int [n];

    


    input(n,f,name,farm,mark,gr);
    first(n,f,name,farm,mark,gr);
    second(n,f,name,farm,mark,gr);
    third(n,f,name,farm,mark,gr);
    fourth(n,f,name,farm,mark,gr);

    



   
    




  
    

    return 0;
}
