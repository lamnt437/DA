#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LENGTH 10

typedef struct word{
    char s[MAX_LENGTH];
    int number;
}Word;

typedef Word KeyType;

typedef struct node{
    KeyType data;
    struct node *left;
    struct node *right;
}NodeType;

typedef NodeType *TreeType;

TreeType InsertNode(TreeType Root, KeyType x){
    if(Root == NULL){
        Root = (TreeType)malloc(sizeof(NodeType));
        Root->data = x;
        Root->left = NULL;
        Root->right = NULL;
    }
    else if(strcmp(x.s, (Root->data).s) < 0)
        Root->left = InsertNode(Root->left, x);
    else if(strcmp(x.s, (Root->data).s) > 0)
        Root->right = InsertNode(Root->right, x);
    return Root;
}

TreeType Search(TreeType Root, KeyType x){
    if(Root == NULL)    return NULL;
    if(!strcmp((Root->data).s, x.s))
        return Root;
    else if(strcmp(x.s, (Root->data).s) < 0)
        return Search(Root->left, x);
    else
        return Search(Root->right, x);
}

void inOrder(TreeType root){
    if(root != NULL){
        inOrder(root->left);
        printf("%s %d\n", (root->data).s, (root->data).number);
        inOrder(root->right);
    }
}

void string_toupper(char s[]){
    for(int i = 0; s[i] != '\0'; i++){
        s[i] = toupper(s[i]);
    }
}

int main(){
    FILE *read = fopen("test.txt", "r");
    char value[MAX_LENGTH];
    KeyType temp;
    char *ptr = NULL;
    TreeType root = NULL;
    TreeType ptr = NULL;

    while(!feof(read)){
        fscanf(read, "%s", value);
        string_toupper(value);
        strcpy(temp.s, value);
        temp.number = 1;
        ptr = Search(root, temp);
        if(ptr == NULL){
            root = InsertNode(root, temp);
        }
        else{
            (ptr->data).number += 1;
        }
    }

    fclose(read);

    inOrder(root);
    return 0;
}

