#include "lib.h"

int main(){
  int arr[7] = {5, 4, 19, 1, 3, 7, 12};
  TreeType root = NULL;
  NodeTree *ptr = NULL;

  for(int i = 0; i < 7; i++){
    ptr = makeNodeTree(arr[i]);
    root = insertNodeTree(root, ptr);
  }
  BFS(root);
  printf("\n");

  return 0;
}
