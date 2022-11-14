#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
struct tree_node {
  int item;
  struct tree_node *left;
  struct tree_node *right;
};
*/
struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
if(t==NULL){
  struct tree_node *temp = malloc(sizeof(struct tree_node));
  temp->item=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
if(x<=t->item)
{
  t->left=Insert(x,t->left);
  return t;
}
if(x>=t->item){
  
  t->right=Insert(x,t->right);
  return t;
}
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
  //struct tree_node *temp=t;

 if(Contains(x,t)!=true){//if x isn't in btree tree is returned.
  return t;
 }
  if(x==t->item){//
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

  if(t->item!=x){
    if(x<t->item){
      t->left=Remove(x,t->left);
  }
    if(x>t->item){
     t->right = Remove(x,t->right);
    }
  return t;
  }
 }

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
if(t==NULL){
  return 0;
}
if(t->item==x){
  return 1;
}
if(x<t->item){
  
  return Contains(x,t->left);
}
if(x>t->item){
  
  return Contains(x,t->right);
}

}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  t=NULL;
  return t;
}

int Empty(struct tree_node *t) {
  return t == NULL;
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}
