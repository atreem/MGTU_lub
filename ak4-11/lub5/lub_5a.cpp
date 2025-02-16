#include <iostream>
#include <clocale>

const char text[]= 
R"0(
1. Подсчитать количество минимальных элементов. Вывести индексы минимальных элементов.
2. Найти значение первого положительного элемента и его индекс.
3. Поменять местами первый максимальный элемент и элемент, индекс которого введен с клавиатуры.
4. Удалить из массива элементы, которые больше 5. Новый массив не создавать.
5. Отсортировать массив по убыванию.
)0";


void first(int *l,int len)
{//Подсчитать количество минимальных элементов. Вывести индексы минимальных элементов.
    int min,count;
    min=*l; count=0;

    for (int i;i<len;i++)
    {
        if(min>l[i])
        {
            min=l[i];
        }
    }
    printf("индекс мин элкметов: ");
    for (int i=0;i<len;i++)
    {
        if (l[i]==min) {count++;printf("%d ",i+1);}
    }
    printf("\nколичество минимальных элементов %d\n",count);
}

int second (int *l, int len)
{//Найти значение первого положительного элемента и его индекс.
    printf("значение первого положительного элемента и его индекс: ");
//    bool flag=0;
    for (int i=0;i<len;i++)
    {
        if (l[i]>0)
        {
            printf("индекс = %d     значение =%d\n",i,l[i]);return 0;//falg=1;
        }
    }
    //if (flag==0)
    printf("нет полжительных элеиментов\n");
    return 0;
}

void third(int *l, int len)
{//Поменять местами первый максимальный элемент и элемент, индекс которого введен с клавиатуры.
    int list[len];
    for (int i=0;i<len;i++)        {list[i]=l[i];}
    int index=0; int index_mx=0;
    printf("введите индекс элемента обмена ");
    scanf("%d",&index);

    for (int i=0;i<len;i++)
    {
        if (list[i]>list[index_mx])
        {
            index_mx=i;
        }
    }
    int swap=list[index];
    list[index]=list[index_mx];
    list[index_mx]=swap;
    for (int i=0;i<len;i++) printf("%d ",list[i]);
    printf("\n");
}

void fourth (int *l,int len)
{//Удалить из массива элементы, которые больше 5. Новый массив не создавать.
    int list[len];
    for (int i=0;i<len;i++) list[i]=l[i];
    int i = 0;
    printf("элименты < 5: ");
    while (i<len)
    {
        if (list[i]>5)
        {
            for (int j=i;j<len-1;j++)
            {
                list[j]=list[j+1];
            }
            list[len]=0;len--; 
        }
        else i++;
    }
    if(len!=0)
    {
        printf("len=%d\n",len);
        for (int i=0;i<len;i++)
        {
            printf("%d ",list[i]);
        }
        printf("\n");
    }
    else printf("нет элементов <5\n");
}

void fifth (int *l,int len)
{//Отсортировать массив по убыванию
    int temp = 0; // временная переменная для хранения элемента массива
    bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован
    while (!exit) // пока массив не отсортирован
    {
        exit = true;
        for (int i = 0; i < (len - 1); i++) // внутренний цикл
        //сортировка пузырьком по возрастанию - знак >
        //сортировка пузырьком по убыванию - знак <
        if (l[i] < l[i + 1]) // сравниваем два соседних элемента
        {
            // выполняем перестановку элементов массива
            temp = l[i];
            l[i] = l[i + 1];
            l[i + 1] = temp;
            exit = false; // на очередной итерации была произведена перестановка элементов
        }
    }
/*
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++) {
            if (l[j] < l[j + 1]) {
                // меняем элементы местами
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
        }
    }*/
    for (int i = 0; i < len ; i++) {printf ("%d ",l[i]);}
    printf("\n");
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
        default:
            printf("некоректный ввод\n");
            break;
        }
    }
    return 0;
    
}
