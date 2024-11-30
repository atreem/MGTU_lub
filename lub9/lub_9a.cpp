#include <iostream>

char *fourth(size_t len) // 4 ввод одномерного денамического масива
{
    char *list_ch = new char[len];
    for (size_t i = 0; i < len; i++)
    {
        scanf("\n%c", &list_ch[i]);
    }
    return list_ch;
}
void output(char *list_ch, size_t len) // 4 ввывод одномерного динамического масива
{
    // как символы
    for (size_t i = 0; i < len; i++)
    {
        printf("%c", list_ch[i]);
    }

    // как числа
    for (size_t i = 0; i < len; i++)
    {
        printf("%4d", list_ch[i]);
    }
}

char **fifth(size_t m, size_t n) // 5 ввод двумерного денамического масива
{
    char **list_ch = new char *[m]; // создаём пустой динамический масив указателей
    for (size_t i = 0; i < m; i++)
    {
        list_ch[i] = new char[n]; // создаём динамический масив целых чисел
        for (size_t j = 0; j < n; j++)
        {
            scanf("%c", &list_ch[i][j]);
        }
    }
    return list_ch;
}

int main(int argc, char const *argv[])
{
/*1. Создать одну локальную переменную типа char. Ввести значение переменной с клавиатуры.
 Вывести значение переменной на экран и ее код.*/
    {
        char ch;
        printf("input ch\n");
        scanf("\n%c", &ch);
        printf("ch=%c       index in ASCII=%d\n", ch, ch);
    }
/*2. Создать одну динамическую переменную типа char.
Ввести значение переменной с клавиатуры.
Вывести значение переменной на экран и ее адрес.*/
    {
        printf("input dch\n");
        char *dch = new char;
        scanf("\n%c", dch);
        printf("dch= %c     address in sys=%p\n", *dch, dch);
    }
/*3. Создать динамический одномерный массив символов.
Размер массива и элементы массива вводятся с клавиатуры.
- подсчитать количество символов ‘a’в массиве;
Освободить память.*/
    {
        // ввод
        int len;
        printf("input len   ");
        scanf("%d", &len);
        char *list_ch = new char[len];
        for (size_t i = 0; i < len; i++)
        {
            scanf("\n%c", &list_ch[i]);
        }

        // вывод
        for (size_t i = 0; i < len; i++)
        {
            printf("%c ", list_ch[i]);
        }

        // подсчет кол-ва 'a'(англ)
        int count=0;
        for (size_t i = 0; i < len; i++)
        {
            if (list_ch[i]=='a')    count++;
        }
        printf("кол-во 'a'=%d",count);

        // освобождаем память
        delete [] list_ch;//освобождаем все элименты в list_ch(числа)
        
    }

/*4. В фале 1.txt записан размер динамического массива и элементы массива.
Структура файла: первое число – размер массива, на следующей строке записаны
символы (без пробелов). В функции выделить память под динамический массив и
заполнить массив. Передать адрес массива в основную функцию. Вывести массив
как символы и как целые числа (функция).
- подсчитать количество сочетаний ‘abc’ в массиве.
Освободить память.*/
    {
        // ввод масива
        int len;
        scanf("\n%d", &len);
        char *list_ch = fourth(len);

        // вывести кол-во 'abc'
        int count = 0;
        for (size_t i = 0; i < len - 2; i++)
        {
            if (list_ch[i] == 'a' && list_ch[i + 1] == 'b' && list_ch[i + 2] == 'c')
            {
                count++;
            }
        }
        printf("count of 'abc'=%d", count);

        // совобождаем память
        delete [] list_ch; //освобождаем все элименты в list_ch(числа)
    }
    /*5. В фале 2.txt записан размер двумерного динамического массива и элементы массива.
    Структура файла: первые два числа – размер массива, далее элементы массива по строкам
    через пробелы (рис.1).
    В функции выделить память под двумерный динамический массив и заполнить массив.
    Передать адрес массива в основную функцию. Вывести массив.
    Поменять местами первый и последний столбцы.
    Освободить память.*/
    {
        // ввод длины
        size_t m, n;
        scanf("%d%d", m, n);

        // ввод массива
        char **list_ch = fifth(m, n);

        // вывод массива
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                printf("%4d", list_ch[i][j]);
            }
            printf("\n");
        }

        // обмен местами первого и последнего столбцов
        char swap;
        for (size_t i = 0; i < m; i++)
        {
            swap=list_ch[i][0];
            list_ch[i][0]=list_ch[i][n-1];
            list_ch[i][n-1]=swap;
        }
        printf("\n\n\n");

        // вывод массива
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                printf("%4d", list_ch[i][j]);
            }
            printf("\n");
        }

        // освобожаем память
        for (size_t i = 0; i < m; i++)
        {
            delete [] list_ch[i];//освобождаем все элименты в list_ch[i](числа)
        }
        delete [] list_ch;//освобождаем все элименты в list_ch(указатели)
    }
    return 0;
}
