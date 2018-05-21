#include "tree.h"

TreeType makeNodeTree(Content_t v){
  TreeType newNode = (TreeType)malloc(sizeof(NodeTree));
  newNode->data = v;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

TreeType insertNodeTree(TreeType root, NodeTree *newNode){
  if(root == NULL)
    return newNode;
  if(root->data < newNode->data)
    root->right = insertNodeTree(root->right, newNode);
  else
    root->left = insertNodeTree(root->left, newNode);
  return root;
}

void preOrder(TreeType root){
  if(root != NULL){
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(TreeType root){
  if(root != NULL){
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
  }
}

void postOrder(TreeType root){
  if(root != NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
  }
}

void BFS(TreeType root){
  if(root != NULL){
    Queue q1;
    q1.counter = 0;
    q1.front = 0;
    q1.rear = 0;
    TreeType ptr = NULL;

    enqueue(&q1, root);
    while(!isEmpty(q1)){
      ptr = dequeue(&q1);
      printf("%d ", ptr->data);
      if(ptr->left != NULL)
        enqueue(&q1, ptr->left);
      if(ptr->right != NULL)
        enqueue(&q1, ptr->right);
    }
  }
}