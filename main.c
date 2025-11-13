#include <stdlib.h>
#include "mem.h"



// basic func like get, set, append, remove
// util func like len, capacity, item size
// extra ,when len of struct == capacity, double len of struct

	

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

	printf("\n %zu ", dyna_arr_int_find(num_list, 5));

	dyna_arr_int_destroy(num_list);

	return 0;
}
