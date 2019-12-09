// list/main.c
// 
// Tests for linked list implementation.
//
// dskvll

#include <stdio.h>
#include "list.h"

int main() {
	printf("Tests for linked list implementation.\n");
  
	list_t *list = list_alloc();
	
    
	list_add_to_front(list,8);
    printf("Add %d to the front: ", 8);
    list_print(list);
    
	list_add_to_back(list,7);
    printf("Add %d to the back: ", 7);
    list_print(list);

    	list_add_at_index(list,5,2);
    printf("Add %d at index %d: ", 5,2);
    list_print(list);
    
  list_add_to_front(list,9);
    printf("Add %d to the front: ", 9);
    list_print(list);
    
	list_add_to_back(list,4);
    printf("Add %d to the back: ", 4);
    list_print(list);
    
	list_add_at_index(list,1,2);
    printf("Add %d at index %d: ", 1,2);
    list_print(list);
    
	elem val1 = list_remove_from_front(list);
    printf("\nRemoved %d from the front: ", val1);
    list_print(list);
    
	elem val2 = list_remove_at_index(list, 3);
    printf("Removed %d from the index, %d: ", val2, 3);
    list_print(list);
    
	elem val3 = list_remove_from_back(list);
    printf("Removed %d from the back: ", val3);
	list_print(list);
	
	int length = list_length(list);
	printf("\nLength of the list is: %d.\n", length);
	
	list_free(list1);
	return 0;
}