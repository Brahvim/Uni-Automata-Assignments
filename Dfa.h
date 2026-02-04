#pragma once

#define STRI(x)					#x
#define STR(x)					STRI(x)
#define statePtr(...)			(&stateVal(__VA_ARGS__))
#define stateVal(p_apbet, p_name, ...)	\
((struct State ## p_apbet) {			\
	p_name, 							\
	(									\
		(struct Struct const[			\
			dfaAlphabetTotal(p_apbet)	\
		]) { __VA_ARGS__ }) })

#define dfaAlphabetTotal(p_apbet)	\
dfaAlphabetEnumEntry(p_apbet, TOTAL)

#define dfaAlphabetEnumEntry(p_apbet, p_entry)	\
ALPHABET_ ## p_apbet ## _ ## p_entry

#define dfaAlphabetEnumBody(p_apbet, ...) {	\
											\
	__VA_ARGS__,							\
	dfaAlphabetTotal(p_apbet)				\
											\
}

#define dfaStateStructBody(p_apbet, p_struct) {		\
													\
	char const *name;								\
	struct p_struct const 							\
		transitions[dfaAlphabetTotal(p_apbet)];		\
													\
}
