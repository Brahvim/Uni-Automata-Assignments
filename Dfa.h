#pragma once

#define statePtr(p_name, ...)	(&stateVal(p_apbet, __VA_ARGS__))
#define dfaAlphabetTotal(p_apbet)	dfaAlphabetEnumEntry(p_apbet, TOTAL)
#define dfaAlphabetEnumEntry(p_apbet, p_entry)	ALPHABET_ ## p_apbet ## _ ## p_entry
#define stateVal(p_name, ...)	((struct p_name) { p_name, (struct Struct*) { __VA_ARGS__ } })

#define dfaAlphabetEnumBody(p_apbet, ...) {	\
											\
	__VA_ARGS__,							\
	dfaAlphabetTotal(p_apbet)				\
											\
}

#define dfaStateStruct(p_apbet, p_struct)	\
struct p_struct {							\
											\
	char const *name;						\
	struct p_struct const *transitions;		\
											\
}
