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
	stateVar(Ab, a,
		stateVal(Ab, NULL)
	);
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
