#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>





struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
if(t==NULL){//edge case for empty tree. x is set as root and roots right and left are set to point at NULL.
  struct tree_node *temp = malloc(sizeof(struct tree_node));
  temp->item=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
if(x<=t->item)//if value of x is less than or equal to root, then roots left is set to point at x
{
  t->left=Insert(x,t->left);
  return t;
}
if(x>t->item){// if value of x is greater than root, then roots right is set to point at x
  
  t->right=Insert(x,t->right);
  return t;
}
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t

 if(Contains(x,t)!=true){//edge case for when x isn't in tree.
  return t;
 }
  if(x==t->item){//when x is found in tree root is replaced with right if possible:
    if(t->right==NULL){
      t = t->left;
      return t;
    }
    t = t->right;
    while(t!=NULL){
      t = t->left;
    }
  return t;
  }

  if(t->item!=x){//searches through btree for x.
    if(x<t->item){//goes left when x is less than root
      t->left=Remove(x,t->left);
  }
    if(x>t->item){//goes right when x is greater than root
     t->right = Remove(x,t->right);
    }
  return t;
  }
 }

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
if(t==NULL){//edge case for empty btree.
  return 0;
}
if(t->item==x){//when x is found 1 is returned:
  return 1;
}
if(x<t->item){//searches left if x is less than root
  
  return Contains(x,t->left);
}
if(x>t->item){//searches right if x is greater than root
  
  return Contains(x,t->right);
}

}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  t=NULL;//tree node points to NULL when empty
  return t;
}

int Empty(struct tree_node *t) {//empty btree points to NULL.
  return t == NULL;
}

int Full(struct tree_node *t) {//linked list can't be full.
  // Test if full
  return 0;
}
