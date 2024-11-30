#include <iostream>
#include <clocale>

void first(double a[10][10],int n ,int m)
/*Найти значение максимального элемента во всем массиве.
 Полученное значение вывести внутри функции.*/
{
    double max=a[0][0];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (max<a[i][j]) max=a[i][j];
        }
    }
    printf("max=%lf\n",max);
    
}


void second(double a[10][10],int n ,int m)
{/*Найти значение минимального элемента
 во всем массиве и индексы первого минимального (обход по строкам).
 Полученные значения вывести внутри функции.*/
    double min=a[0][0];
    int index_i,index_j;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (min>a[i][j]){ min=a[i][j];index_i=i+1;index_j=j+1;}
        }
    }
    printf("min=%lf\n",min);
    printf("index i=%d index j=%d\n",index_i,index_j);
}


double third (double a[10][10],int n ,int m)
{           
/*Найти значение максимального элемента в последней строке. 
Полученное значение вывести в основной функции.*/
    
    int i=n-1;
    double max=a[i][0];
    for (int j=0;j<m;j++)
    {
        if (max<a[i][j]) { max=a[i][j];}
    }
    return max;
//    printf("max=%lf\n",max);
}


double fourth (double a[10][10],int n ,int m,int index_i)
{/*Вычислить среднее арифметическое строки,
 индекс которой введен пользователем в основной программе. 
 Вычисление среднего элемента проводить в функции,
 полученное значение напечатать в основной функции.*/  
    double s=0;
    for(int j=0;j<m;j++)
    {
        s+=a[index_i][j];
    }
    return (s/m);  
}


int fifth (double a[10][10],int n ,int m)
{/*Подсчитать количество элементов>5 в столбце,
номер которого ввел пользователь.
Результат напечатать в основной функции.*/
    printf("input of column\n");
    int index_j;
    scanf("%d",&index_j);
    index_j--;
    int count=0;
    if(0<=index_j<m)
    {
        int flag=0;
        for (int i=0;i<n;i++)
        {
            if(a[i][index_j]>5)
                count++;
        }
        return count;
    }
    else { printf("index out of range\n");  return -1;}
   
}


void input(double a[10][10],int n,int m)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            printf("input a[%d][%d] ",i,j);
            scanf("%lf",&a[i][j]);
        }
    }
}


void output (double a[10][10],int n,int m)
{
     for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            printf("%4lf ",a[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    setlocale(LC_CTYPE,"");
    double a[10][10];
    int n,m;
    printf("input n,m\n");
    scanf("%d%d",&n,&m);
    input(a,n,m);//ввод масив
    output(a,n,m);// вывод масива
    first(a,n,m);//1.Найти значение максимального элемента во всем массиве. Полученное значение вывести внутри функции.
    second(a,n,m);//2.Найти значение минимального элемента во всем массиве и индексы первого минимального (обход по строкам). Полученные значения вывести внутри функции.
    printf("max at last row=%lf\n",third(a,n,m));//3.Найти значение максимального элемента в последней строке. Полученное значение вывести в основной функции.
    int index_i;    printf("input index of row\n");    scanf("%d",&index_i);    index_i--;
    if (index_i<m)   printf("mean of row=%lf\n",fourth(a,n,m,index_i));//4.Вычислить среднее арифметическое строки, индекс которой введен пользователем в основной программе. Вычисление среднего элемента проводить в функции, полученное значение напечатать в основной функции
    else printf("index out of range\n");
    int fif =fifth(a,n,m);
    if (fif+1)    printf("count el>5 of column=%d\n",fif);//5.Подсчитать количество элементов>5 в столбце, номер которого ввел пользователь. Результат напечатать в основной функции.
    else printf("index out of range\n");
    return 0;
}