//header for mem.c

#ifndef MEM_H
#define MEM_H

#include <stddef.h> //something for the user idk im sleepy
#include <stdlib.h> 


#define DECLR_ARR(T) \
	typedef struct { T * data; size_t count; size_t capacity; } dyna_arr_##T; \
	static inline dyna_arr_##T * dyna_arr_##T##_create() { \
		dyna_arr_##T * arr = malloc(sizeof(dyna_arr_##T)); \
		arr->count = 0; \
		arr->capacity = 16; \
		arr->data = malloc(sizeof(T) * 16); \
		return arr; \
	}\
	static inline dyna_arr_##T * dyna_arr_##T##_append(dyna_arr_##T * arr, T value) { \
		if ( arr->count >= arr->capacity ) { \
			arr->capacity *= 2; \
			arr->data = realloc(arr->data, sizeof(T) * arr->capacity); \
		} \
		arr->data[arr->count] = value; \
		arr->count += 1; \
		return arr; \
	}\
	static inline void dyna_arr_##T##_destroy(dyna_arr_##T * arr) { \
		free(arr->data); \
		return; \
	} \
	static inline T dyna_arr_##T##_get(dyna_arr_##T * arr, size_t index) { \
		return arr->data[index]; \
	} \
	static inline void dyna_arr_resize(dyna_arr_##T * arr) { \
		arr->capacity *= 2; \
		arr->data = realloc(arr->data, sizeof(T) * arr->capacity); \
	} \
	static inline size_t dyna_arr_##T##_find(dyna_arr_##T * arr, T value) { \
		if( arr->count < 0 ) { return -1; } \
		for(size_t i = 0; i <= arr->count; i++) { \
			if( arr->data[i] == value) { \
				return i; \
			} \
		} \
		return arr->count + 1;\
	} \
	static inline size_t dyna_arr_get_capacity(dyna_arr_##T * arr) { \
		return arr->capacity; \
	} \
	static inline size_t dyna_arr_get_length(dyna_arr_##T * arr) { \
		return arr->count; \
	} \
	static inline void dyna_arr_##T##_remove(dyna_arr_##T * arr, size_t index) { \
		if( arr->count < 0 ) { return; } \
		for( size_t i = index; i <= arr->count; i++){ \
			if( i + 1 < arr->count ) { \
				arr->data[i] = arr->data[i + 1]; \
			} \
			else { \
				arr->data[i] = 0x0; \
			} \
		} \
	} \
	static inline void dyna_arr_##T##_set(dyna_arr_##T * arr, T value) { \
		if( arr->count < 0 ) { return; } \
		if( arr->count >= arr->capacity) { dyna_arr_resize(arr); } \
		for ( size_t i = 0; i <= arr->count; i++) { \
			arr->data[i] = value; \
		} \
	} 

	


DECLR_ARR(int);
//add a DECL_ARR(type) here and to support a diffrent type


#endif
