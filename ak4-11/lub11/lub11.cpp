#include <iostream>
int **input(FILE *f , int len)
{
    int **matrix= new int *[len];
    for (size_t i = 0; i < len; i++)
    {
        matrix[i]=new int[len];
        for (size_t j = 0; j < len; j++)
        {
            fscanf(f,"%d",&matrix[i][j]);
        }
        
    }
    return matrix;
}

void output(int **matrix,int len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int first(int **matrix,int len,int *index_i,int *index_j)
{
    *index_i=0;
    *index_j=0;
    int max=matrix[0][0];
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if(matrix[i][j]>max)
            {
                *index_i=i;
                *index_j=j;
                max=matrix[i][j];
            }
        }
    }
    return max;
}

int second(int **matrix,int len,int *index_i,int *index_j)
{
    *index_i=0;
    *index_j=0;
    int min=matrix[0][0];
    for (size_t i = 0; i < len; i++)
    {
    if(matrix[i][i]<=min)
        {
            *index_i=i;
            *index_j=i;
            min=matrix[i][i];
        }
    }
    return min;
}

int third(int **matrix,int len,int *index_i,int *index_j)
{
    int negative=0;
    for (size_t i = 0; i < len; i++)
    {
    if(matrix[i][len-i-1]<negative)
        {
            *index_i=i;
            *index_j=len-i-1;
            negative=matrix[i][len-i-1];
            break;
        }
    }
    return negative;
}

int main(int argc, char const *argv[])
{
/*Открыть файл; первое число размер квадратного динамического массива;
Считать размер считать элементы; ввести вывести
1 во всём массиве найти макс элемент и индексы первого максимального, знач. явна, при помощи параметра индексы ссылки
2 на главной диагонали найти мин элемент и индексы последнего минимального. Значение минимального явно, индексы ссылками
3 на побочной значение первого отрицательного элемента. Значение явно, индексы ссылки.
*/
    const char PATH[]="matrix.txt";
    printf(PATH);
    FILE *f = fopen(PATH,"r+");
    
    int len;
    fscanf(f,"\n%d",&len);
    printf("\nlen = %d\n",len);

    int **matrix= input(f,len);
    fclose(f); 

    output(matrix,len);
    
    
/*1 во всём массиве найти макс элемент и индексы первого максимального, знач.
 явна, при помощи параметра индексы ссылки*/
    int index_i,index_j;
    int max=first(matrix,len,&index_i,&index_j);
    index_i++;index_j++;
    printf("max=%d index_i=%d index_j=%d\n",max,index_i,index_j);

/*2 на главной диагонали найти мин элемент и индексы последнего минимального.
 Значение минимального явно, индексы ссылками*/
    int min=second(matrix,len,&index_i,&index_j);
    index_i++;index_j++;
    printf("min=%d index_i=%d index_j=%d\n",min,index_i,index_j);

/*3 на побочной значение первого отрицательного элемента. Значение явно, индексы ссылки.*/
    int negative=third(matrix,len,&index_i,&index_j);//При отсутситвии отрицательных: возвращает 0 , индексы не меняет
    if (negative)     printf("negative=%d index_i=%d index_j=%d\n",negative,index_i,index_j);

    else printf("there are no negative numbers\n");

    return 0;
}
