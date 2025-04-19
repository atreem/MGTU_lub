#include <stdio.h>
#include <string.h>


struct node {
	char *str;
	node *next;
};

#define VOWELS 5
const char vowels[VOWELS] = {'a', 'i', 'u', 'e', 'o'};

void input(node **first) {
	node *cur, *last;
	static char str[50];
	
	printf("input words: ");
	fgets(str, 50, stdin);

	char *tok = strtok(str, " ");
	if (tok != NULL) {
		*first = last = cur = new node;
		cur->str = tok;
		cur->next = NULL;
	}

	tok = strtok(NULL, " ");
	while (tok != NULL) {
		cur = new node;

		last->next = cur;

		cur->str = tok;
		cur->next = NULL;

		last = cur;

		tok = strtok(NULL, " ");
	}
}

void output(node *first) {
	node *cur = first;
	printf("Elements:\n");
	while (cur != NULL) {
		printf("%s\n", cur->str);
		cur = cur->next;
	}
}

void t1(node *first) {
	node *cur = first;

	printf("Words starting with vowel: ");
	int i, found;
	while (cur != NULL) {
		i = found = 0;
		while (found == 0 && i < VOWELS) {
			if (cur->str[0] == vowels[i]) {
				found = 1;
				printf("%s ", cur->str);
			}
			i++;
		}
		cur = cur->next;
	}
	puts("");
}

int main() {
	node *first = NULL;
	input(&first);
	output(first);

	t1(first);
	
	return 0;
}
