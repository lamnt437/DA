#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef int Content_t;

typedef struct node{
  Content_t data;
  struct node *left, *right;
}NodeTree;

typedef NodeTree *TreeType;


TreeType makeNodeTree(Content_t v);
TreeType insertNodeTree(TreeType root, NodeTree *newNode);
void preOrder(TreeType root);
void inOrder(TreeType root);
void postOrder(TreeType root);
void BFS(TreeType root);