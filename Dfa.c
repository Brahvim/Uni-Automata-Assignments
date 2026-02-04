#include "Dfa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

dfaStateStruct(Ab);
dfaAlphabetEnumBody(
	Ab, AB,
	dfaAlphabetEnumEntry(AB, A),
	dfaAlphabetEnumEntry(AB, B)
);

int main(int const p_argCount, char const *const p_argValues[]) {
	struct StatesAb *q0 = calloc(1, sizeof(struct StatesAb));
	struct StatesAb *q1 = calloc(1, sizeof(struct StatesAb));
	q0->transitions = calloc(2, sizeof(struct StatesAb));
	*(q0->transitions + 0) = q0;
	*(q0->transitions + 1) = q1;
	q1->transitions = NULL;
	q0->name = "q0";
	q1->name = "q1";

	enum AlphabetsAb const input[] = {

		ALPHABET_AB_A,
		ALPHABET_AB_B,

	};
	size_t const len = sizearr(input);
	struct StatesAb *state = q0;

	for (size_t i = 0; i < len; ++i) {

		if (!state->transitions) { // ...Or `exit()` in `q1()`?

			break;

		}

		struct StatesAb const *const prev = state;
		enum AlphabetsAb symbol = *(input + i);
		state = *(state->transitions + symbol);

		printf(
			state == prev
				? "Input `%d` does not transform machine state.\n"
				: "Input `%d` transforms machine state from `%s` -> `%s`.\n",
			symbol,
			prev->name,
			state->name
		);

	}

	free(q0->transitions);
	free(q0);
	free(q1);
	exit(EXIT_SUCCESS);
}
