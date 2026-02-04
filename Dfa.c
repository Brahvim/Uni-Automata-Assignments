#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void*(*state_t)(char const);

void *q0(char const);
void *q1(char const);

void *q0(char const p_input) {

	if (p_input == 'a') {

		return q1;

	}

	if (p_input == 'b') {

		return q0;

	}

	return NULL;

}

void *q1(char const p_input) {

	if (p_input == 'a') {

		return NULL;

	}

	if (p_input == 'b') {

		return NULL;

	}

	return NULL;

}

int main() {

	char *const input = "ba";
	state_t state = q0;

	size_t const len = strlen(input);
	int i = 0;
	char c;


	for (size_t i = 0; state && (i < len); ++i) {

		c = *(input + i);
		state = state(c);
		i++;

	}

	exit(EXIT_SUCCESS);

}
