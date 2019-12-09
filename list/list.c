// list/list.c
// 
// Implementation for linked list.
//
// dskvll

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() {
  printf("\nAllocating memory .");
  list_t *l = (list_t*) malloc(sizeof(list_t));
  l->head = NULL;
  return l;
}

void list_free(list_t *l) {
  printf("\nFreeing memory .");
  node_t *currentnode = l->head;
  if (currentnode == NULL) {
    printf("\nNo elements.");
    free(l->head);
    free(l);
    return;
  }
  // Traverse list until last node.
  node_t *temp;
  while (currentnode != NULL) {
    temp = currentnode;
    currentnode = currentnode->next;
    // Free each node from left to right, iteratively.
    free(temp);
  }
  free(l);
}

void list_print(list_t *l) {
  node_t *currentnode;
  
  // Check if list is empty.
  if (l->head == NULL) {
    printf("\n\nempty list");
    return;
  }
  // Traverse list and print each element.
  currentnode = l->head;
  printf("\nList Items");
  while (currentnode != NULL) {
    printf("\n%d", currentnode->value);
    currentnode = currentnode->next;
  }      
}

int list_length(list_t *l) {
  node_t *currentnode = l->head;
  // Check if the list is empty
  if (currentnode == NULL) {
    return 0;
  }
  // If list is not empty, counter from head to tail.
  int counter = 0;
  while (currentnode != NULL) {
    counter++;
    currentnode = currentnode->next;
  }
  return counter;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *currentnode = l->head;
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  
  // Add to back of list if list has elements
  if (currentnode != NULL) {
    printf("\nAdding element to back of list.");
    while (currentnode->next != NULL) currentnode = currentnode->next;
    currentnode->next = new_node;
  }
  // List has no elements, so just add.
  else {
    l->head = new_node;
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t *currentnode = l->head;
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  
  // Add to front of list if list has elements
  if (currentnode != NULL) {
    printf("\nAdding element to front .");
    new_node->next = l->head;
    l->head = new_node;
  }
  // List has no elements, so just add.
  else {
    new_node->next = NULL;
    l->head = new_node;
  }
}

void list_add_at_index(list_t *l, elem value, int index) {
  node_t *previousnode = l->head;
  
  int counter = 0;
  if ((index > list_length(l)) || (index < 0)) {
    printf("\nInvalid index.");
    return;
  }
  if (previousnode == NULL) {
    l->head = (node_t*) malloc(sizeof(node_t));
    l->head->value = value;
    l->head->next = NULL;
    return;
  }
  // Index must be valid.
  else {
    while ((counter < index - 1) && (previousnode->next != NULL)) {
      previousnode = previousnode->next;
      counter++;
    }
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->next = previousnode->next;
    new_node->value = value;
    previousnode->next = new_node;
  }
}

elem list_remove_from_back(list_t *l) { 
  int value;
  node_t *currentnode = l->head;
  
  if (currentnode == NULL) {
    printf("\nNo elements.");
    return -1;
  }
  else {
    if (list_length(l) < 2) {
      l->head = NULL;
      free(currentnode);
    }
    else {
      while (currentnode->next->next != NULL) currentnode = currentnode->next;
      node_t *temp = currentnode->next;
      currentnode->next = NULL;
      free(temp);
    }
  }
}

elem list_remove_from_front(list_t *l) { 
  node_t *currentnode = l->head;
  if (currentnode == NULL) {
    printf("\nNo elements .");
    return -1;
  }
  int value = currentnode->value;
  l->head = (list_length(l) < 2) ? NULL : currentnode->next;
  free(currentnode);
  return value;
}

elem list_remove_at_index(list_t *l, int index) {
  node_t *currentnode = l->head;
  node_t *temp;
  int value, counter = index;
  
  if ((index > list_length(l) + 1) || (index < 1)) {
    printf("\nInvalid index.");
    return -1;
  }
  // Index must be valid.
  else {
    while (counter > 1) {
      currentnode = currentnode->next;
      counter--;
    }
    // Remove the node at specified index.
    temp = currentnode->next;
    currentnode->next = NULL;
    value = temp->value;
    free(temp);
    printf("\nNode removed from index %d", index);
  }
  return value;
}

bool list_is_in(list_t *l, elem value) { 
  node_t *currentnode = l->head;
  
  while (currentnode != NULL) {
    if (currentnode->value == value) return true;
     currentnode = currentnode->next;
  }
  return false; 
}

elem list_get_elem_at(list_t *l, int index) {
  node_t *currentnode = l->head;
  if ((index > list_length(l) - 1) || (index < 0)) {
    printf("\nInvalid index.");
    return -1;
  }
  while (currentnode->next != NULL && index >= 0) {
    currentnode = currentnode->next;
    index--;
  }
  return currentnode->value;
}

int list_get_index_of(list_t *l, elem value) {
  node_t *currentnode = l->head;
  int index = 0;
  
  while (currentnode != NULL) {
    if (currentnode->value == value) return index;
     currentnode = currentnode->next;
    index++;
  }
  return -1; 
}