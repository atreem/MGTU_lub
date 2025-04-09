/*
Лабораторная 6 (объекты).
Класс студент:
приватные поля:
- фамилия (fam)
- массив из трёх оценок за последнюю сессию (mark)
- группа (gr)
публичные поля:
- массив из трех оценок за ЕГЭ (ege)
- метод заполнения приватного поля группа (set_gr)
- методы возвращения всех приватных полей
- метод вычисления суммарной оценки за ЕГЭ (sum_ege)
- метод вычисления средней оценки за сессию (sr_mark)
В классе объявить дружественными:
- функцию заполнения динамического массива студентов
- функцию нахождения студентов, сдавших сессию на 4 и 5
--------------------------------------------------------------------------------
В файл записать информацию о нескольких студентах.
В программе открыть файл с проверкой, подсчитать количество студентов. 
Создать динамический массив студентов. Ввод (заполнение массива) и вывод массива при помощи функций. При выводе выводить все поля данных и результаты работы методов.
1. Вывести на экран фамилии студентов, сдавших сессию на 4 и 5.
2. Вывести на экран фамилии студентов, у кого есть неудовлетворительные оценки.
3. Студентов, у которых средняя оценка за сессию больше 4, поместить в 10 группу (изменить номер группы на десять).
4)найти мин ср бал вывести инфу о студентах с таким балом
5) вычислить ср бал для каждой группы 
*/


#include <iostream>


class student
{
private:
    char fam[30];
    int gr;
    int mark[3];
    
public:

    friend void input(FILE *F,student *a,int n);
    friend void norm(student *a,int n);


    int ege[3];

    char * get_fam(){return fam;}
    void set_gr(int q){gr=q;}
    int get_gr(){return gr;}
    int *get_mark(){return mark;}


    int sum_ege(){return ege[0]+ege[1]+ege[2];}
    double sr_mark(){return (mark[0]+mark[1]+mark[2])/3.0;}
};

void input(FILE *F,student *a,int n)
{
    for (int i = 0; i < n; i++)
    {
        
        fscanf(F,"%s%d%d%d%d%d%d%d",a[i].fam,&a[i].mark[0],&a[i].mark[1],&a[i].mark[2],&a[i].gr,&a[i].ege[0],&a[i].ege[1],&a[i].ege[2]);
    }
}


void norm(student*a,int n)
{
    printf("\n\n\nхор/отл\n");
    for (int i = 0; i < n; i++)
    {
        if(a[i].mark[0]>3&&a[i].mark[1]>3&&a[i].mark[2]>3)
        {
            printf("%s \n",a[i].get_fam());
        }
    }
}


void output(student*a,int n)
{   
    printf("все\n");
    for (size_t i = 0; i < n; i++)
    {
        
        // fscanf(F,"%s%d%d%d%d",a[i].fam,&a[i].mark[0],&a[i].mark[0],&a[i].mark[0],&a[i].gr);
        printf("fam %s mark %d %d %d gr %d ege %d %d %d\n",a[i].get_fam(),a[i].get_mark()[0],a[i].get_mark()[1],a[i].get_mark()[2],a[i].get_gr(),a[i].ege[0],a[i].ege[1],a[i].ege[2]);
    }
    
}



void t_2(student*a,int n)
{
    printf("\n\n\nнеуд:\n");
    for (int i = 0; i < n; i++)
    {
        if(a[i].get_mark()[0]==2||a[i].get_mark()[1]==2||a[i].get_mark()[2]==2)
        {
            printf("%s \n",a[i].get_fam());
        }
    }
    
}

void t_3(student*a,int n)
{
    printf("\n\n\n>4 в 10\n");

    for (int i = 0; i < n; i++)
    {
        if(a[i].sr_mark()>4)
        {
            printf("%s\n",a[i].get_fam());
            a[i].set_gr(10);
        }
    }
    output(a,n);
}



void t_4(student*a, int n )
{
    double min_sr=5.0;
    double sr;
    printf("\n\n\nминимальный средний бал:\n");
    for (int i = 0; i < n; i++)
    {
        sr=(a[i].get_mark()[0]+a[i].get_mark()[1]+a[i].get_mark()[2])/3.0;
        if (min_sr>sr)
        {
            min_sr=sr;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        sr=(a[i].get_mark()[0]+a[i].get_mark()[1]+a[i].get_mark()[2])/3.0;
        if (min_sr==sr)
        {
            printf("fam %s mark %d %d %d gr %d ege %d %d %d\n",a[i].get_fam(),a[i].get_mark()[0],a[i].get_mark()[1],a[i].get_mark()[2],a[i].get_gr(),a[i].ege[0],a[i].ege[1],a[i].ege[2]);
        }
        
    }
    
}


void t_5(student*a,int n)
{
    struct sp
    {
        int gr;
        double sum;
        int count;
        sp * next;
    };
    

    sp*first=new sp;
   
    first->next=NULL;
    first->count=1;
    first->gr=a[0].get_gr();
    first->sum=(a[0].get_mark()[0]+a[0].get_mark()[1]+a[0].get_mark()[2])/3.0;



    sp*cur;
    bool flag;
    for (int i = 1; i < n; i++)
    {
        cur=first;
        flag=0;
        while (cur!=NULL)
        {
            if (cur->gr==a[i].get_gr())
            {
                cur->count++;
                cur->sum+=(a[i].get_mark()[0]+a[i].get_mark()[1]+a[i].get_mark()[2])/3.0;
                flag=1;
            } 
            cur=cur->next;
        }
        

        if(flag==0)
        {
            cur=first;
            while (cur->next!=NULL){cur=cur->next;}
            cur->next=new sp;
            cur=cur->next;
            cur->next=NULL;
            cur->count=1;
            cur->gr=a[i].get_gr();
            cur->sum=(a[i].get_mark()[0]+a[i].get_mark()[1]+a[i].get_mark()[2])/3.0;
        }
    }


    printf("\n\n\nсреднее по группам\n");
    cur=first;
    while (cur!=NULL)
    {
        printf("gr=%d sr=%lf\n",cur->gr,cur->sum/cur->count);
        cur=cur->next;
    }
    
    
}




int main(int argc, char const *argv[])
{
    FILE *f= fopen("lub6.txt","r");
    student *a;
    int n=0;
    
    if(f==NULL) 
    {
        printf("no such file\n");
        return 0;
    }

    else
    {
        
        char str[100];
        while (fgets(str,100,f))
        {
            n++;
        }
        rewind(f);
            
        a=new student[n];
        input(f,a,n);
    }
    
    printf("n=%d\n",n);
    if(n==0) 
    {
        printf("пустой файл\n");
        return 0;
    }


    output(a,n);

    norm(a,n);

    t_2(a,n);
    t_3(a,n);
    t_4(a,n);
    t_5(a,n);

    return 0;
}

