#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100

//TREE STRUCT
typedef char KeyType;
typedef struct Node{
    KeyType data;
    struct Node *left, *right;
}NodeType;
typedef struct Node *TreeType;

typedef NodeType *KeyTypeList;

//STACK STRUCT
typedef struct linkE{
    KeyTypeList data;
    struct linkE* next;
}ListElement;

typedef ListElement *List;

//STACK CHAR STRUCT
typedef struct listC{
    char data;
    struct listC *next;
}ListCharElement;
typedef ListCharElement *ListChar;

//OPERATION ON STACK
    /*CHECK EMPTY*/
    int isEmptyList(List p){
        return p == NULL;
    }

    void printList(List p){
        ListElement *ptr = p;
        while(ptr != NULL){
            printf("%c ", (ptr->data)->data);
            ptr = ptr->next;
        }
        printf("\n");
    }

    KeyTypeList peek(List root){
        KeyTypeList temp = root->data;
        return temp;
    }
    KeyTypeList pop(List *root){
        KeyTypeList temp = NULL;
        if(!(isEmptyList(*root))){
            ListElement *ptr = *root;
            temp = (*root)->data;
            *root = ptr->next;
            free(ptr);
        }
        return temp;
    }
    void push(List *root, KeyTypeList value){
        List temp = (List)malloc(sizeof(ListElement));
        temp->data = value;
        temp->next = *root;//address that root points to
        *root = temp;//edit root point to temp
    }

    void freeList(List *root){
        ListElement *ptr = *root;
        while((*root) != NULL){
            (*root) = (*root)->next;
            free(ptr);
            ptr = *root;
        }
    }

//OPERATION ON CHAR STACK
    void printListChar(ListChar root){
        ListCharElement *ptr = root;
        while(ptr != NULL){
            printf("%c ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    int isEmptyChar(ListChar root){
        return root == NULL;
    }

    char peekChar(ListChar root){
        if(!isEmptyChar(root)){
            return root->data;
        }
        return '#';
    }

    void pushChar(ListChar *root, char c){
        ListCharElement *temp = (ListCharElement *)malloc(sizeof(ListCharElement));
        temp->data = c;
        temp->next = *root;
        *root = temp;
    }

    char popChar(ListChar *root){
        char temp = '#';
        if(!isEmptyChar(*root)){
            ListCharElement *ptr = *root;
            temp = ptr->data;
            *root = (*root)->next;
            free(ptr);
        }
        return temp;
    }

    void freeListChar(ListChar *root){
        ListCharElement *ptr = *root;
        while(!(isEmptyChar(*root))){
            *root = (*root)->next;
            free(ptr);
            ptr = *root;
        }
    }

//CONVERT

int order(char c){
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return -1;
}

int checkOperation(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void convert(char s1[], char s2[]){
    ListChar o_stack = NULL;//stack store operation +-'('
    char temp;
    int i, k = 0;
    for(int i = 0; s1[i] != '\0'; i++){
        printListChar(o_stack);
        if(isalpha(s1[i])){
            s2[k] = s1[i];
            k++;
        }
        else{
            if(checkOperation(s1[i])){
                //pop out until reach empty or reach '(' or reach order <= order(s1[i])
                while(!(isEmptyChar(o_stack) || peekChar(o_stack) == '(' || order(peekChar(o_stack)) < order(s1[i]))){
                    temp = popChar(&o_stack);
                    s2[k] = temp;
                    k++;
                }
                pushChar(&o_stack, s1[i]);
            }
            else{
                if(s1[i] == '(')
                    pushChar(&o_stack, s1[i]);
                else{
                    while(peekChar(o_stack) != '('){
                        temp = popChar(&o_stack);
                        s2[k] = temp;
                        k++;
                    }
                    temp = popChar(&o_stack);//REMOVE '('
                }
            }
        }
    }
    while(!isEmptyChar(o_stack)){
        temp = popChar(&o_stack);
        s2[k] = temp;
        k++;
    }
    s2[k] = '\0';

    freeListChar(&o_stack);
}

//TREE
TreeType createNode(char c){
    TreeType temp = (TreeType)malloc(sizeof(NodeType));
    temp->data = c;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(){

    char s[MAX_LENGTH];
    char s_post[MAX_LENGTH];
    /*get string s*/

    printf("Enter expression: ");
    fgets(s, MAX_LENGTH -1, stdin);
    s[strlen(s) - 1] = '\0';
    convert(s, s_post);
    printf("%s", s_post);
    /*convert to postfix*/

    return 0;
}

