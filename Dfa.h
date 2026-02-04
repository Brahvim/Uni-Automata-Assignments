#pragma once

#define statePtr(p_name, ...)	\
(&stateVal(p_apbet, __VA_ARGS__))

#define stateVal(p_struct, ...)	\
((struct States ## p_name) { p_name, (struct p_name*) { __VA_ARGS__ } })

#define stateVar(p_name, p_var, ...)	\
struct States ## p_name p_var = stateVal(p_name, __VA_ARGS__)

#define stateVarPtr(p_name, p_var, ...)	\
struct States ## p_name *p_var = statePtr(p_name, __VA_ARGS__)

#define dfaAlphabetTotal(p_apbet)	\
dfaAlphabetEnumEntry(p_apbet, TOTAL)

#define dfaAlphabetEnumEntry(p_apbet, p_entry)	\
ALPHABET_ ## p_apbet ## _ ## p_entry

#define dfaAlphabetEnumBody(p_enum, p_apbet, ...)	\
enum Alphabets ## p_struct	{ 						\
													\
	__VA_ARGS__,									\
	dfaAlphabetTotal(p_apbet)						\
													\
}

#define dfaStateStruct(p_struct)		\
struct States ## p_struct {				\
										\
	char const *name;					\
	struct p_struct const *transitions;	\
										\
}
