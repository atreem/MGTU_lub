/*
queue
<- *** <-

queue.add
new elem
last.next = elem
last = elem

queue.pop
tmp = first.next
del first
first = tmp

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
	int val;
	node *next;
};

void input(node **first, node **last) {
	node *cur;

	char str[50];
	printf("Input element or end: ");
	scanf("%s", str);
	
	while (strcmp(str, "end") != 0) {
		cur = new node;

		if (*first == NULL)
			*first = cur;
		else
			(*last)->next = cur;

		cur->val = atoi(str);
		cur->next = NULL;

		*last = cur;
		
		printf("Input number or end: ");
		scanf("%s", str);
	}
}

void output(node *first) {
	node *cur = first;
	printf("Elements: ");
	while (cur != NULL) {
		printf("%4d", cur->val);
		cur = cur->next;
	}
	puts("");
}

int len(node *first) {
	node *cur = first;
	int n = 0;
	
	while (cur != NULL) {
		n++;
		cur = cur->next;
	}
	return n;
}

void t1(node *first) {
	node *cur = first;
	int found = 0, sum = 0;

	printf("Elements divisible by 3: ");
	while(cur != NULL) {
		if (cur->val % 3 == 0) {
			found = 1;
			sum += cur->val;
			printf("%4d", cur->val);
		}
		cur = cur->next;
	}
	if (found == 0)
		printf("no elements");
	puts("");

	printf("sum=%d\n", sum);
}

int main() {
	node *first = NULL, *last;
	input(&first, &last);
	output(first);

	printf("n=%d\n", len(first));
	puts("");
	
	t1(first);

	return 0;
}
