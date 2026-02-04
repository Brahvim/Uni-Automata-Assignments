#pragma once

#define sizearr(p_array) sizeof(p_array) / sizeof(p_array[0])

#define statePtr(p_apbet, p_name, ...)	\
(&stateVal(p_apbet, p_name, __VA_ARGS__))

#define stateVal(p_apbet, p_name, ...)	\
((struct States ## p_apbet) { p_name, (struct States ## p_apbet*) { __VA_ARGS__ } })

#define stateVar(p_apbet, p_var, p_name, ...)	\
struct States ## p_apbet p_var = stateVal(p_apbet, p_name, __VA_ARGS__)

#define stateVarPtr(p_apbet, p_var, p_name, ...)	\
struct States ## p_apbet *p_var = statePtr(p_apbet, p_name, __VA_ARGS__)

#define dfaAlphabetTotal(p_apbet)	\
dfaAlphabetEnumEntry(p_apbet, TOTAL)

#define dfaAlphabetEnumEntry(p_apbet, p_entry)	\
ALPHABET_ ## p_apbet ## _ ## p_entry

#define dfaAlphabetEnumBody(p_enum, p_apbet, ...)	\
enum Alphabets ## p_enum { 							\
													\
	__VA_ARGS__,									\
	dfaAlphabetTotal(p_apbet)						\
													\
}

#define dfaStateStruct(p_struct)				\
struct States ## p_struct {						\
												\
	char const *name;							\
	struct States ## p_struct **transitions;	\
												\
}
