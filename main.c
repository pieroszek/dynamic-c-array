#include <stdlib.h>
#include "mem.h"


// create and destroy the data struct
// basic func like get, set, append, remove
// util func like len, capacity, item size
// extra ,when len of struct == capacity, double len of struct

#define IMPL_ARR(T) \
	dyna_arr_##T * dyna_arr_##T##_create() { \
		dyna_arr_##T * arr = malloc(sizeof(dyna_arr_##T)); \
		arr->count = -1; \
		arr->capacity = 16; \
		arr->data = malloc(sizeof(T) * 16); \
		return arr; \
	}\
	dyna_arr_##T * dyna_arr_##T##_append(dyna_arr_##T * arr, T value) { \
		if ( arr->count >= arr->capacity ) { \
			arr->capacity *= 2; \
			arr->data = realloc(arr->data, sizeof(T) * arr->capacity); \
		} \
		arr->count += 1; \
		arr->data[arr->count] = value; \
		return arr; \
	}
	
// supported types, look at .h
IMPL_ARR(int);
IMPL_ARR(float);
IMPL_ARR(char);
IMPL_ARR(double);

int main(){
	printf("\nhi");
	dyna_arr_int * num_list = dyna_arr_int_create();
	dyna_arr_int_append(num_list, 5);

	for(int i = 1; i <= 19; i++){
		dyna_arr_int_append(num_list, i);	
	}

	for(int i = 0; i <= num_list->count; i++){
		printf("\n %d ", num_list->data[i]);
	}

	return 0;
}
