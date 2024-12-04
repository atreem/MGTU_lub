#include <iostream>

void input(int *list,size_t len)
{ //3
    for (size_t i=0;i<len;i++)
    {
        printf("input el %d ",i);
        scanf("%d", &list[i]);
    }
    printf("\n");
}

void input(int **list,size_t len1,size_t len2)
{ //4
    for (int i=0;i<len1;i++)
    {
        list[i]=new int [len2];
    }
    
    for (size_t i=0;i<len1;i++)
    {
        for (size_t j=0;j<len2;j++)
        {
            printf("input list[%d][%d]",i,j);
            scanf("%d",&list[i][j]);
        }
    }
    
    printf("\n");
}


template <size_t len1,size_t len2> void input(int list[len1][len2])
{ //5
    for (size_t i=0;i<len1;i++)
    {
        for (size_t j=0;j<len2;j++)
        {
            printf("input list[%d][%d]",i,j);
            scanf("%d",&list[i][j]);
        }
    }
    printf("\n");
}


void output(int *list,size_t len)
{   //3
    for (size_t i=0;i<len;i++)
        {
            printf("%4d",list[i]);
        }
    printf("\n");
}

void output(int **list,size_t len,size_t len2)
{   //4
    for (size_t i=0;i<len;i++)
    {
        printf("%p ",list[i]);
    }
    printf("\n\n\n");

    for (size_t i=0;i<len;i++)
    {
        for (size_t j=0;j<len2;j++)
        {
            printf("%16d ",list[i][j]);
        }
        printf("\n");

        for (size_t j=0;j<len2;j++)
        {
            printf("%p ",&list[i][j]);
        }
        printf("\n\n");
    }    
}


template <size_t len1,size_t len2> void output(int list[len1][len2])
{  //5 
    
    printf("address list = %p",list);
    for (size_t i=0;i<len1;i++)
    {
        printf("%p ",list[i]);
    }
    printf("\n\n\n");

    for (size_t i=0;i<len1;i++)
    {
        for (size_t j=0;j<len2;j++)
        {
            printf("%16d ",list[i][j]);
        }
        printf("\n");

        for (size_t j=0;j<len2;j++)
        {
            printf("%p ",&list[i][j]);
        }
        printf("\n\n");
    }    
}

int main()
{

    
    /*1. Создать переменную int a. Ввести с клавиатуры значение. 
Вывести адрес переменной и ее значение.*/
    {
        int a;
        printf("input a\n");
        scanf("%d",&a);
        printf("a=%d, address a = %p\n",a,(&a));
    }


    /*2.Создать указатель на переменную целого типа "с".
Попробовать вывести значение указателя. Создать переменную для записи ее адреса в указатель.
 Ввести с клавиатуры значение переменной.
Вывести адрес переменной и ее значение.*/
    {
        int c;
        int *adrec_c=&c;
        printf("input c ");
        scanf("%d",adrec_c);
        printf("input= %d, adrec of input=%p\n", *adrec_c,adrec_c);
    }


/*3. В основной программе создать одномерный динамический массив целых чисел d1. Размер массива вводит пользователь.
Заполнение массива в функции. Значения элементов вводит пользователь с клавиатуры.
Вывести в функции адрес массива, значения элементов массива и их адреса.*/
    {
        int len;
        printf("input len ");
        scanf("%d",&len);
        int *d1=new int [len];
        input(d1,len);
        output(d1,len);
    }


/*4. В основной программе создать двумерный динамический массив целых чисел d2.
 Размер массива вводит пользователь.
Заполнение массива в функции. Значения элементов вводит пользователь с клавиатуры.
Вывести в функции адрес массива, массив указателей на строки, значения элементов массива и их адреса.*/
    {
    
        int n,m;
        printf("input n m ");
        scanf("%d%d",&n,&m);
        int **d2=new int*[n];
        
        input(d2,n,m);
        output(d2,n,m);
    
    }


/*
 5. В основной программе создать двумерный статический массив целых чисел d3 [2*3]. 
 Заполнение массива в функции. Значения элементов вводит пользователь с клавиатуры.
 Вывести в функции значения элементов массива и их адреса, адрес массива.
*/
    {
        printf("input list 2*3");
        const int a=2;
        const int b=3;
        int d3[a][b];
        input<a,b>(d3);
        output<a,b>(d3);
    }


    return 0;
}