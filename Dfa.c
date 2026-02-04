#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct State {

	char const *name;
	struct State(*transition)(char const);

};

#define STRI(x)					#x
#define STR(x)					STRI(x)
#define statePtr(...)			(&stateVal(__VA_ARGS__))
#define stateVal(p_function)	((struct State) { STR(p_function), p_function })

struct State q0(char const input);
struct State q1(char const input);

struct State q0(char const p_input) {

	switch (p_input) {

		case 'a': {

			return stateVal(q1);

		} break;

		case 'b': {

			return stateVal(q0);

		} break;

	}

	return stateVal(NULL);

}

struct State q1(char const p_input) {
	return stateVal(NULL);
}

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
