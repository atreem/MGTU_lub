#include <iostream>
#include <clocale>

const char text[]=
R"L(1. Вывести на экран элементы массива, кратные трем.
2. Четные элементы массива увеличить в два раза.
3. Вычислить сумму положительных элементов.
4. Поменять местами первый и последний элементы. 
5. Поменять местами элементы, индексы которых введены с клавиатуры. Нумерация индексов при вводе с клавиатуры как в математике, с единицы.
6. Вычислить среднее арифметическое всех элементов.
7. Найти значение максимального элемента.
8. Найти значение минимального элемента в массиве и индекс первого минимального.
9. Подсчитать количество минимальных элементов.
10. Найти значение минимального элемента среди четных элементов.
11. Вычислить среднее арифметическое элементов, кратных пяти.)L";

void first(int *l,int len)
{ //Вывести на экран элементы массива, кратные трем.
    bool flag=0;
    printf("Элементы крытые трём: ");
    for (int i=0; i < len; i++)
    {
        if ((l[i])%3==0){ printf("%d ",l[i]);flag=1;}
    }
    if (flag==0)    printf("нет нужных элиментов");
    printf("\n");
}


void second(int *l,int len)
{ //Четные элементы массива увеличить в два раза.
    printf("Четные элементы массива увеличить в два раза: ");
    
    for (int i=0; i < len; i++)
    {
        if (l[i]%2==0) printf("%d ",l[i] * 2);
        else printf("%d ",*l);
    }
    printf("\n");
}


void third(int *l,int len)
{ //Вычислить сумму положительных элементов.
    printf("Сумма положительных элементов: ");
    int s=0;
    for (int i=0; i < len; i++)
    {
        if (l[i]>0) s+=l[i];
    }
    if (s!=0)    printf("%d\n",s);
    else    printf("элементов > 0\n");
}


void fourth (int *l , int len)
{ //Поменять местами первый и последний элементы. 
    int list[len];
    for (int i=0; i < len; i++)  list[i] =l[i];
    printf("Меняем первый и последний\n");
    int swap = list[0];
    list[0]=list[len-1];
    list[len-1]=swap;
    for (int i=0; i < len; i++)
    {
        printf("%d ",*l);
        l++;
    }
    printf("\n");
}


void fifth (int *l, int len)
{/*Поменять местами элементы, индексы которых введены с клавиатуры.
 Нумерация индексов при вводе с клавиатуры как в математике, с единицы.*/
    printf ("введите 2 индекса\n");
    int i1,i2;
    int list[len];
    for (int i=0; i < len; i++)  list[i] =l[i];
    scanf("%d%d",&i1,&i2);
    i1--;i2--;
    int swap = list[i1];
    list[i1]=list[i2];
    list[i2]=swap;
    for (int i=0; i < len; i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}


void sixth(int *l, int len)
{//Вычислить среднее арифметическое всех элементов.
    double s=0;
    for (int i=0; i < len; i++) {s+=l[i];}
    printf("среднее арифметическое всех элементов: %lf\n",s/len);
}


void seveth (int *l , int len)
{//Найти значение максимального элемента.
    int mx=*l;
    for (int i=0;i<len;i++)
    {
        if (mx<l[i]) mx=l[i];
    }
    printf("максимальный элеент: %d\n",mx);
}


void eightn (int *l,int len)
{/*Найти значение минимального элемента в массиве
 и индекс первого минимального.*/
    int index_min,min;
    index_min=0;min=*l;
    for (int i;i<len;i++)
    {
        if(min>l[i])
        {
            min=l[i];index_min=i;
        }
    }
    printf("минимальный элемент: %d\nиндекс минимального элемента %d\n",min,++index_min);
}


void nineth(int *l, int len)
{//Подсчитать количество минимальных элементов.
    int min,count;
    min=*l; count=0;
    for (int i;i<len;i++)
    {
        if(min>l[i])
        {
            min=l[i];
        }
    }
    for (int i=0;i<len;i++)
    {
        if (l[i]==min) count++;
    }
    printf("количество минимальных элементов %d\n",count);
}


void tenth(int *l,int len)
{//Найти значение минимального элемента среди четных элементов.
    int min_ch=0;
    bool flag=0;
    for (int i=0;i<len;i++)
    {
        if ((flag==1) && l[i]%2==0 && l[i]<min_ch)
             min_ch=l[i];
        if ( (flag==0) && l[i]%2==0)  { min_ch=l[i];flag=1;}
    }
    if(flag)    printf("значение минимального элемента среди четных элементов %d\n",min_ch);
    else printf("нет чектных элиментов\n");
}


void eleventh(int *l,int len)
{//Вычислить среднее арифметическое элементов, кратных пяти.
    int count,s;
    s=0;count=0;
    for (int i=0;i<len;i++)
    {
        if (l[i]%5==0) {s+=l[i];count++;}
    }
    if (count!=0)   printf("среднее арифметическое элементов, кратных пяти: %d\n",s/count);
    else    printf("нет элементов кратных 5\n");    
}


int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE,"");
    int list [20];
    printf("Введите раазмер, не более 20\n");
    int len;
    scanf("%d",&len);

    if (len>20 || len<1)
    {
        printf("введён некоректный размер\n");  return 0;
    }
    for (int i=0; i < len; i++)
    {
        printf ("введите элемент %d\n",i);
        scanf("%d",&list[i]);
    }
    printf("размер масива=%d\n",len);
    int *l=list;
    int input=1;
    printf("%s",text);
    for (int i=0;i<len;i++) printf("%d ",list[i]);
    printf("\nвведите номомер задания\nдля выхода введите 0\n");

    while (input!=0)
    {
        scanf("%d",&input);
        switch (input)
        {
        case 0:
            printf("выход");
            break;
        case 1:
            first(l,len);
            break;
        case 2:
            second(l,len);
            break;
        case 3:
            third(l,len);
            break;
        case 4:
            fourth(l,len);
            break;
        case 5:
            fifth(l,len);
            break;
        case 6:
            sixth(l,len);
            break;
        case 7:
            seveth(l,len);
            break;
        case 8:
            eightn(l,len);
            break;
        case 9:
            nineth(l,len);
            break;
        case 10:
            tenth(l,len);
            break;
        case 11:
            eleventh(l,len);
            break;
        default:
            printf("некоректный ввод\n");
            break;
        }
    }
    return 0;
}