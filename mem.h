//header for mem.c

#ifndef MEM_H
#define MEM_H

#include <stddef.h> //something for the user idk im sleepy
#include <stdlib.h> 


#define DECLR_ARR(T) \
	typedef struct { T * data; size_t count; size_t capacity; } dyna_arr_##T; \
	static inline dyna_arr_##T * dyna_arr_##T##_create() { \
		dyna_arr_##T * arr = malloc(sizeof(dyna_arr_##T)); \
		arr->count = -1; \
		arr->capacity = 16; \
		arr->data = malloc(sizeof(T) * 16); \
		return arr; \
	}\
	static inline dyna_arr_##T * dyna_arr_##T##_append(dyna_arr_##T * arr, T value) { \
		if ( arr->count >= arr->capacity ) { \
			arr->capacity *= 2; \
			arr->data = realloc(arr->data, sizeof(T) * arr->capacity); \
		} \
		arr->count += 1; \
		arr->data[arr->count] = value; \
		return arr; \
	}\
	static inline void dyna_arr_##T##_destroy(dyna_arr_##T * arr) { \
		free(arr->data); \
		return; \
	} \
	static inline T dyna_arr_##T##_get(dyna_arr_##T * arr, size_t index) { \
		return arr->data[index]; \
	} \
	static inline size_t dyna_arr_##T##_find(dyna_arr_##T * arr, T value) { \
		if( arr->count < 0 ) { return -1; } \
		for(size_t i = 0; i <= arr->count; i++) { \
			if( arr->data[i] == value) { \
				return i; \
			} \
		} \
		return -1;\
	} \
	static inline size_t dyna_arr_get_capacity(dyna_arr_##T * arr) { \
		return arr->capacity; \
	} \
	static inline size_t dyna_arr_get_length(dyna_arr_##T * arr) { \
		return arr->count; \
	} 

	


DECLR_ARR(int);
//add a DECL_ARR(type) here and a IMPL_ARR(type) in the .c to support a diffrent type


#endif
