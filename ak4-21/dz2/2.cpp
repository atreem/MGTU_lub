#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int num;
	node *next;
};

void input(node **first1, node **last1, node **first2, node **last2) {
	node **first = first1, **last = last1;

	char str[50];
	
	printf("введи эдимент или конец: ");
	scanf("%s", str);

	node *cur;
	while (strcmp(str, "end") != 0) {
		cur = new node;
		cur->num = atoi(str);
		cur->next = NULL;

		if (cur->num == 0) {
			first = first2;
			last = last2;
		}

		if (*first == NULL)
			*first = cur;
		else
			(*last)->next = cur;

		*last = cur;
		
		printf("введи эдимент или конец: ");
		scanf("%s", str);
	}
}

void output(node *first) {
	printf("элименты: ");
	
	if (first == NULL)
		printf("нет элиментов");

	node *cur = first;
	while (cur != NULL) {
		printf("%4d", cur->num);
		cur = cur->next;
	}

	puts("");
}

void t1(node *first1, node *first2) {
	int s1 = 0, s2 = 0, found = 0;

	printf("элименты(list1) делимые на 3: ");
	node *cur = first1;
	while (cur != NULL) {
		if (cur->num % 3 == 0) {
			found = 1;
			printf("%4d", cur->num);
			s1 += cur->num;
		}
		cur = cur->next;
	}
	if (found == 0)
		printf("нет элименов");
	puts("");
	printf("s1=%d\n", s1);

	
	printf("элименты(list2) делимые на 3: ");
	cur = first2;
	found = 0;
	while (cur != NULL) {
		if (cur->num % 3 == 0) {
			found = 1;
			printf("%4d", cur->num);
			s2 += cur->num;
		}
		cur = cur->next;
	}
	if (found == 0)
		printf("нет элиментов");
	puts("");
	printf("s2=%d\n", s2);
	puts("");

	if (s1 > s2)
		printf("s1 > s2\n");
	else if (s1 < s2)
		printf("s1 < s2\n");
	else
		printf("s1 == s2\n");
}
 
int main() {
	node *first1 = NULL, *last1;
	node *first2 = NULL, *last2;
	input(&first1, &last1, &first2, &last2);
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
