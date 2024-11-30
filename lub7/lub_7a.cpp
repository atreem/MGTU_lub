#include <iostream>
#include <clocale>


void input(int a[10][10],int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("input a[%d][%d] ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}


void output (int a[10][10],int n)
{
    printf("\n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }
}

int first(int a[10][10],int n) 
/*1. Найти количество положительных элементов на главной диагонали.
Вывести полученный результат в основной функции.*/
{
    int count = 0;
    for (int i=0;i<n;i++)
    {
        if(a[i][i]>0)   count++;
    }
    return count;
}


int second(int a[10][10],int n)
/*2. Найти значение минимального элемента на побочной диагонали.
 Вывести полученный результат в основной функции.*/
{
    int min = a[0][n-1];
    for (int i=0;i<n;i++)
    {
        if(a[i][n-i-1]<min)  min=a[i][n-i-1];
    }
    return min;
}


void third (int a[10][10],int n)
/*3. Найти минимальный элемент и индексы первого минимального
 в области от главной диагонали и правее. Главная диагональ входит в область.
  Вывести результаты внутри функции.*/
{
    int min=a[0][0];
    for (int i =0; i<n;i++)
    {
        for (int j =i;j<n;j++)
        {
            if (a[i][j]<min) min =a[i][j];
        }
    }
    printf("third: min=%d\n",min);
}


void fourth (int a[10][10],int n)
/*4. Поменять местами строки, номера которых ввел пользователь.*/
{
    int i1,i2,swap;
    printf("Input 2 indexes of row\n");
    scanf("%d%d",&i1,&i2);
    if (0<=i1<n && 0<=i2<n)
    {
        int matrix[10][10];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                matrix[i][j]=a[i][j];
            }
        }
        
        for (int i=0;i<n;i++)
        {
            swap=matrix[i1][i];
            matrix[i1][i]=matrix[i2][i];
            matrix[i2][i]=swap;
        }
        output(matrix,n);
    }
    else printf("incorrect index\n");
}


void fifth (int a[10][10],int n)
/*5. Отсортировать по возрастанию столбец, номер которого ввел пользователь.*/
{
    int index_j;
    printf("input index  of column\n");
    scanf("%d",&index_j);
    
    
    if (0<=index_j<n)
    {
        int matrix[10][10];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                matrix[i][j]=a[i][j];
            }
        }


        bool exit=0;
        int temp=0;
        while (!exit)
        {
            
            exit =1;
            for (int i=0;i<(n-1);i++)
            {
                if (matrix[i][index_j] > matrix[i+1][index_j])
                {
                // выполняем перестановку элементов массива
                temp = matrix[i][index_j];
                matrix[i][index_j] = matrix[i + 1][index_j];
                matrix[i + 1][index_j] = temp;
                exit = false;
                }
            }
        }
        output(matrix,n);
    }
    else printf("incorrect index\n");
}





int main()
{
    setlocale(LC_CTYPE,"");
    int a[10][10];
    int n;
    printf("input n\n");
    scanf("%d",&n);
    input(a,n);//ввод масив
    output(a,n);// вывод масива
    printf("first: %d\n",first(a,n));//1. Найти количество положительных элементов на главной диагонали. Вывести полученный результат в основной функции.
    printf("second: %d\n",second(a,n));//2. Найти значение минимального элемента на побочной диагонали. Вывести полученный результат в основной функции.
    third(a,n);//3. Найти минимальный элемент и индексы первого минимального в области от главной диагонали и правее. Главная диагональ входит в область. Вывести результаты внутри функции.
    fourth(a,n);//4. Поменять местами строки, номера которых ввел пользователь.
    fifth(a,n);//5. Отсортировать по возрастанию столбец, номер которого ввел пользователь.
    return 0;
}