#include <stdio.h>

struct node
{
	char ch;
	node *next;
};

void input(node **first, node **last)
{
	printf("ввкди строку ");
	char ch = getchar();

	node *cur;
	while (ch != '\n')
	{
		cur = new node;
		cur->ch = ch;
		cur->next = NULL;

		if (*first == NULL)
			*first = cur;
		else
			(*last)->next = cur;

		*last = cur;

		ch = getchar();
	}
}

void output(node *first)
{
	printf("элименты: ");

	if (first == NULL)
		printf("<нет элиметов>");

	node *cur = first;
	while (cur != NULL)
	{
		printf("%c", cur->ch);
		cur = cur->next;
	}

	puts("");
}

void t1(node *first)
{
	node *cur = first;
	int star = 0, hash = 0, dollar = 0;

	while (cur != NULL)
	{
		if (cur->ch == '*')
			star++;
		else if (cur->ch == '#')
			hash++;
		else if (cur->ch == '$')
			dollar++;
		cur = cur->next;
	}

	printf("номер  зведочек: ");
	if (star > 0)
		printf("%d\n", star);
	else
		printf("нет звездочек\n");

	printf("номер хэш: ");
	if (hash > 0)
		printf("%d\n", hash);
	else
		printf("нет хэш\n");

	printf("номер долора: ");
	if (dollar > 0)
		printf("%d\n", dollar);
	else
		printf("нет долора\n");
}

int main()
{
	node *first = NULL, *last;

	input(&first, &last);
	puts("");

	output(first);
	puts("");

	t1(first);

	return 0;
}
