#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
// File for sandboxing and trying out code
int main(int argc, char **argv) {
  // Add your code
node* ns = make_node(1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));

sum_squares(ns);
  return 0;
}