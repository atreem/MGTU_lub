#include <stdio.h>
#include <string.h>

struct node {
	char *str;
	node *next;
};


#define VOWELS 5
const char vowels[VOWELS] = {'a', 'i', 'u', 'e', 'o'};

// строка из символов
// 2 списка
// 1) слова с нечётными номерами
// 2) слова с чётными номерами
// где больше слов на гласную

void input(node **first1, node **first2) {
	char *str = new char[80];
	printf("введи слова: ");
	fgets(str, 80, stdin);

	int n = 1;
	node *cur, *last1, *last2;
	node **first = first1, **last = &last1;

	char *tok = strtok(str, " ");
	if (tok != NULL && strcmp(tok, "\n") != 0) {
		cur = new node;
		cur->str = tok;
		cur->next = NULL;
		
		*first = cur;

		*last = cur;
	}
	
	tok = strtok(NULL, " ");
	while (tok != NULL) {
		cur = new node;
		cur->str = tok;
		cur->next = NULL;

		n++;
		if (n % 2 != 0) {
			first = first1;
			last = &last1;
		}
		else {
			first = first2;
			last = &last2;
		}

		if (*first == NULL)
			*first = cur;
		else
			(*last)->next = cur;

		*last = cur;

		tok = strtok(NULL, " ");
	}

	(*last)->str[strlen((*last)->str)-2] = '\0';
}

void output(node *first) {
	printf("элименты:\n");
	
	if (first == NULL)
		printf("нет элиментов\n");

	node *cur = first;
	while (cur != NULL) {
		puts(cur->str);
		cur = cur->next;
	}
}

void t1(node *first1, node *first2) {
	int c1 = 0, c2 = 0;

	printf("слова (list1) начинающиеся с гласных: ");
	node *cur = first1;
	int i, found = 0, foundvowel;
	while (cur != NULL) {
		i = foundvowel = 0;
		while (foundvowel == 0 && i < VOWELS) {
			if (cur->str[0] == vowels[i]) {
				foundvowel = found = 1;
				printf("%s ", cur->str);
				c1++;
			}
			i++;
		}
		cur = cur->next;
	}
	if (found == 0)
		printf("нет жлиментов");
	puts("");
	printf("count1=%d\n", c1);
	puts("");
	
	printf("слова(list2) начинающиеся с гласных:");
	cur = first2;
	found = 0;
	while (cur != NULL) {
		i = foundvowel = 0;
		while (foundvowel == 0 && i < VOWELS) {
			if (cur->str[0] == vowels[i]) {
				foundvowel = found = 1;
				printf("%s ", cur->str);
				c2++;
			}
			i++;
		}
		cur = cur->next;
	}
	if (found == 0)
		printf("no elements");
	puts("");
	printf("count2=%d\n", c2);
	puts("");
	
	if (c1 > c2)
		printf("count1 > count2\n");
	else if (c1 < c2)
		printf("count1 < count2\n");
	else
		printf("count1 == count2\n");
} 

int main() {
	node *first1 = NULL, *first2 = NULL;

	input(&first1, &first2);
	puts("");
	
	printf("List1\n");
	output(first1);
	puts("");
	printf("List2\n");
	output(first2);
	puts("");
	
	t1(first1, first2);
	
	return 0;
}
