//header for mem.c

#ifndef MEM_H
#define MEM_H

#include <stddef.h> //something for the user idk im sleepy
#include <stdlib.h> 


#define DECLR_ARR(T) \
	typedef struct { T * data; size_t count; size_t capacity; } dyna_arr_##T; \
	dyna_arr_##T * dyna_arr_##T##_create();	\
	
	


DECLR_ARR(int);
DECLR_ARR(float);
DECLR_ARR(char);
DECLR_ARR(double);
//add a DECL_ARR(type) here and a IMPL_ARR(type) in the .c to support a diffrent type

