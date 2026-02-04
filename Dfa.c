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
	struct StatesAb *q1 = statePtr(Ab, "q1", NULL);
	// *q0 = stateVal(Ab, "q0", q1);
	*q0 = ((struct StatesAb) { "q0", (struct StatesAb const *const) { q1 } });
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
