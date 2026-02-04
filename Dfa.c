#include "Dfa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum AlphabetAb dfaAlphabetEnumBody(
	AB,
	dfaAlphabetEnumEntry(AB, A),
	dfaAlphabetEnumEntry(AB, B)
);

// struct StateAb dfaStateStructBody(AB, StateAb);
struct StateAb {

	char const *name;
	struct StateAb *transitions[ALPHABET_AB_TOTAL];

};

int main(int argc, char const *argv[]) {
	return 0;
}

/*
int main() {
	char const *const input = "bba";
	struct State state = stateVal(q0);
	size_t const len = strlen(input);

	for (size_t i = 0; i < len; ++i) {

		if (!state.transition) { // ...Or `exit()` in `q1()`?

			break;

		}

		struct State const *const prev = &state;
		char const character = *(input + i);
		state = state.transition(character);
		printf(
			state.transition == state.transition
				? "Input `%c` does not transform machine state.\n"
				: "Input `%c` transforms machine state from `%s` -> `%s`.\n",
			state.name,
			prev->name
		);

	}

	exit(EXIT_SUCCESS);
}
*/
