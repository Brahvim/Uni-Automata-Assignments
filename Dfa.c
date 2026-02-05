#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define sizearr(p_array) sizeof(p_array) / sizeof(p_array[0])

enum Alphabet {

	ABET_A,
	ABET_B,
	ABET_TOTAL

};

enum Alphabet* strabet(char const *const p_string, size_t p_length) {
	enum Alphabet *const out = calloc(p_length, sizeof(enum Alphabet));

	for (size_t i = 0; i < p_length; i++) {

		switch (p_string[i]) {

			default: {

				perror("`strabet()`: Unacceptable input string!");
				exit(EXIT_FAILURE);
				free(out);
				return NULL;

			} break;

			case 'a': out[i] = ABET_A;
			case 'b': out[i] = ABET_B;

		}

	}

	return out;
}

int main() {
	size_t const dfa[][ABET_TOTAL] = {

		{ 1, 2, },
		{ 0, 0, },

	};

	size_t prev = 1;
	size_t state = 1;
	char const *const inputStr = "abbab";
	size_t const inputLen = strlen(inputStr);
	enum Alphabet const *const inputAbet = strabet(inputStr, inputLen);

	for (size_t i = 0; i < inputLen; i++) {

		if (!state) {

			break;

		}

		prev = state;

		enum Alphabet const abet = inputAbet[i];
		state = dfa[state][abet];

		printf(
			state == prev
				? "Input `%d` does not transform machine state.\n"
				: "Input `%d` transforms machine state from `%d` -> `%d`.\n",
				abet,
				prev,
				state
		);

	}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
	free(inputAbet);
	exit(EXIT_SUCCESS);
#pragma GCC diagnostic pop
}
