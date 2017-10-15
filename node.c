#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node { int i; struct node *next; };

void print_list(struct node *n){
    while (n){
      printf("\n%d", n-> i);
      n = n -> next; //(*n).next
    }
    printf("\n");
}
struct node * insert_front(struct node *pointer , int num){
  struct node *frontP = (struct node *)malloc(sizeof(struct node));
  (* frontP).i = num;
  (* frontP).next = pointer;
  return frontP;
}
struct node * free_list(struct node *pointer){
  struct node *retpoint = pointer;
  while(pointer){
    struct node *updater = pointer;
    pointer = pointer->next;
    free(updater);
    updater = NULL;
  }
  return pointer;
}

int main(){
  srand(time(NULL));
  struct node *node = NULL;
  int i = 0;
  printf("insert_front w random ints");
  while(i <= 10){
    int r = rand();
    node = insert_front(node,r);
    i++;
  }
  print_list(node);
  printf("free_list:");
  printf("value returned from free list: %p:\n", free_list(node));
  printf("check if freed");
  print_list(node);
  return 0;
}
