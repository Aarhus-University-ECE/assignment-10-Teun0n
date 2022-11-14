#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  if(p!=NULL)//stops at the end of the list
  printf("%d",p->value);//prints value of p node.
  print_list(p->next);//goes to next node.
  // There is NO testcode for this
}

int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp

/*using square function below the sum is found by adding
the return value of square function of all nodes until p=NULL.
*/

  if(p==NULL){
    return 0;
  }
    return square(p->value)+sum_squares(p->next);
}
typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3
  //operation from function f is applied to linked all values of linked list p, and the returned.

if(p==NULL){//edge case for empty list, returns NULL when empty.
return NULL;
}
else{
  node *t=malloc(sizeof(node));// temporary node t is made.

  t->value=f(p->value);// the value of the is set to return value of f(p->value)
  t->next = map(p->next, f);//t's next is set to return of map function. This is how
  
  return t;
}

}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
