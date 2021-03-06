/*Exercise 1*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

//TREE STRUCT
typedef char KeyType;
typedef struct Node{
    KeyType data;
    struct Node *left, *right;
}NodeType;
typedef struct Node *TreeType;

//STACK STRUCT
typedef NodeType *KeyTypeList;
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

/*Tree*/
void makeNullTree(TreeType *T);
NodeType *createNewNode(KeyType data);
TreeType addRight(TreeType *Tree, KeyType NewData);
TreeType addLeft(TreeType *Tree, KeyType NewData);
int getHeight(TreeType T);
int isLeaf(TreeType T);
int numberOfLeaves(TreeType T);
int numberOfIntNodes(TreeType T);
int numberOfLeftChildren(TreeType T);
int numberOfRightChildren(TreeType T);
TreeType createNode(char c);
void printTree(TreeType root);
TreeType createFrom2(KeyType value, TreeType root1, TreeType root2);
TreeType treeExpression(char s[]);

/*StackNode*/
int isEmptyList(List p);
void printList(List p);
KeyTypeList peek(List root);
KeyTypeList pop(List *root);
void push(List *root, KeyTypeList value);
void freeList(List *root);

/*StackChar*/
void printListChar(ListChar root);
int isEmptyChar(ListChar root);
char peekChar(ListChar root);
void pushChar(ListChar *root, char c);
char popChar(ListChar *root);
void freeListChar(ListChar *root);

/*Other*/
int order(char c);
int checkOperation(char c);
void convert(char s1[], char s2[]);
int calculate2(int A, char o, int B);
int calculate(TreeType root);


int main(){
    char s[MAX_LENGTH];
    char s_post[MAX_LENGTH];
    TreeType root = NULL;

    printf("Enter expression: ");
    fgets(s, MAX_LENGTH -1, stdin);
    s[strlen(s) - 1] = '\0';

    convert(s, s_post);

    root = treeExpression(s_post);
    printTree(root);
    printf("Result: %d\n", calculate(root));

    return 0;
}

//OPERATION ON TREE
void makeNullTree(TreeType *T){
    *T = NULL;
}

NodeType *createNewNode(KeyType data){
    NodeType *temp = (NodeType *)malloc(sizeof(NodeType *));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

TreeType addLeft(TreeType *Tree, KeyType NewData){
    NodeType *NewNode = (NodeType*)malloc(sizeof(NodeType));
    NewNode->data = NewData;
    NewNode->left = NULL;
    NewNode->right = NULL;

    if((*Tree) == NULL){
        (*Tree) = NewNode;
    }
    else{
        NodeType *ptr = *Tree;
        while(ptr->left != NULL)
            ptr = ptr->left;
        ptr->left = NewNode;
    }
    return NewNode;
}

TreeType addRight(TreeType *Tree, KeyType NewData){
    NodeType *NewNode = (NodeType*)malloc(sizeof(NodeType));
    NewNode->data = NewData;
    NewNode->left = NULL;
    NewNode->right = NULL;

    if((*Tree) == NULL){
        (*Tree) = NewNode;
    }
    else{
        NodeType *ptr = *Tree;
        while(ptr->right != NULL)
            ptr = ptr->right;
        ptr->right = NewNode;
    }
    return NewNode;
}

int getHeight(TreeType T){
    if(T == NULL) return 0;
    int h1 = getHeight(T->left);
    int h2 = getHeight(T->right);
    return 1 + (h1 > h2?h1: h2);
}

int isLeaf(TreeType T){
    return (T->right == NULL)&&(T->left == NULL);
}

int numberOfLeaves(TreeType T){
    if(T == NULL)   return 0;
    if(isLeaf(T))   return 1;
    return numberOfLeaves(T->left) + numberOfLeaves(T->right);
}
int numberOfIntNodes(TreeType T){
    if(T == NULL)   return 0;
    if(isLeaf(T))   return 0;
    return 1 + numberOfIntNodes(T->left) + numberOfIntNodes(T->right);
}
int numberOfLeftChildren(TreeType T){
    if(T == NULL)   return 0;
    if(T->left == NULL) return 0;
    return 1 + numberOfLeftChildren(T->left) + numberOfLeftChildren(T->right);
}
int numberOfRightChildren(TreeType T){
    if(T == NULL)   return 0;
    if(T->right == NULL)    return 0;
    return 1 + numberOfRightChildren(T->right) + numberOfRightChildren(T->left);
}

TreeType createNode(char c){
    TreeType temp = (TreeType)malloc(sizeof(NodeType));
    temp->data = c;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printTree(TreeType root){
    if(root == NULL)    return;
    printf("%c: ", root->data);
    if(root->left != NULL) printf("%c ", (root->left)->data);
    if(root->right != NULL) printf("%c ", (root->right)->data);
    printf("\n");
    printTree(root->left);
    printTree(root->right);
}

TreeType createFrom2(KeyType value, TreeType root1, TreeType root2){
    TreeType newRoot = (TreeType)malloc(sizeof(NodeType));
    newRoot->data = value;
    newRoot->left = root1;
    newRoot->right = root2;
    return newRoot;
}

TreeType treeExpression(char s[]){
    List o_stack = NULL;
    TreeType temp, temp1, temp2;
    for(int i = 0; s[i] != '\0'; i++){
        if(isdigit(s[i])){
            temp = createNode(s[i]);
            push(&o_stack, temp);
        }
        else{
            temp2 = pop(&o_stack);
            temp1 = pop(&o_stack);
            temp = createFrom2(s[i], temp1, temp2);
            push(&o_stack, temp);
        }
    }
    temp = pop(&o_stack);
    return temp;
}

//OPERATION ON STACK
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

//OTHER

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
        //printListChar(o_stack);
        if(isdigit(s1[i])){
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

int calculate2(int A, char o, int B){
    switch(o){
    case '+':
        return A+B;

    case '-':
        return A-B;

    case '*':
        return A*B;

    case '/':
        return A/B;
    }
}

int calculate(TreeType root){
    if(root == NULL)    return 0;
    if(isLeaf(root)){
        char i[2]; i[0] = root->data; i[1] = '\0';
        return atoi(i);
    }
    int a = calculate(root->left);
    int b = calculate(root->right);
    return calculate2(a, root->data, b);
}




/*Exercise 2*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
#define MAX_LENGTH 100

typedef struct element{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
}Element;

typedef Element KeyType; // specify a type for the data
typedef struct Node {
  KeyType data;
  struct Node* left;
  struct Node* right;
} NodeType;
typedef struct Node* TreeType;

TreeType Search(KeyType x, TreeType Root);
TreeType InsertNode(KeyType x, TreeType Root);
KeyType DeleteMin(TreeType *Root);
void deleteNode(KeyType X, TreeType *Root);
void freeTree(TreeType tree);
void printTree(TreeType root);


int main(int argc, char *argv[]){
    if(argc != 3){
        puts("Wrong number of arguments!");
        return 1;
    }
    FILE *read = fopen(argv[1], "rb");
    if(read == NULL){
        puts("Input file doesn't exist");
        return 2;
    }
    FILE *write = fopen(argv[2], "ab");
    TreeType root = NULL;
    Element buff;
    while(fread(&buff, sizeof(Element), 1, read)){
        root = InsertNode(buff, root);
    }
    fclose(read);

    int choice;
    char key[MAX_LENGTH];
    Element temp;
    TreeType ptr = NULL;
    printf("1 - print tree\n2 - search\n3 - delete\n4 - quit\n?");
    scanf("%d", &choice);

    while(choice != 4){
        switch(choice){
        case 1://PRINT
            printTree(root);
            break;
        case 2://SEARCH
            printf("Enter email to search: ");
            scanf("%s", key);
            strcpy(temp.email, key);
            ptr = Search(temp, root);
            if(ptr != NULL){
                puts("Result:");
                printf("%s %s %s\n", (ptr->data).name, (ptr->data).email, (ptr->data).phone);
                fwrite(&(ptr->data), sizeof(Element), 1, write);
                printf("Result has been written to %s!\n", argv[2]);
            }
            else
                puts("No record!");
            break;
        case 3://DELETE
            printf("Enter email to delete: ");
            scanf("%s", key);
            strcpy(temp.email, key);
            deleteNode(temp, &root);
            puts("New tree:");
            printTree(root);
            break;
        default:
            puts("Try again!");
            break;
        }
        printf("1 - print tree\n2 - search\n3 - delete\n4 - quit\n?");
        scanf("%d", &choice);
    }

    freeTree(root);
    fclose(write);
    return 0;
}

TreeType Search(KeyType x, TreeType Root){
    if(Root == NULL)    return NULL;
    if(!strcmp((Root->data).email, x.email))
        return Root;
    else if(strcmp(x.email, (Root->data).email) < 0)
        return Search(x, Root->left);
    else
        return Search(x, Root->right);
}

TreeType InsertNode(KeyType x, TreeType Root){
    if(Root == NULL){
        Root = (TreeType)malloc(sizeof(NodeType));
        Root->data = x;
        Root->left = NULL;
        Root->right = NULL;
    }
    else if(strcmp(x.email, (Root->data).email) < 0)
        Root->left = InsertNode(x, Root->left);
    else if(strcmp(x.email, (Root->data).email) > 0)
        Root->right = InsertNode(x, Root->right);
    return Root;
}

KeyType DeleteMin(TreeType *Root){
    KeyType k;
    if((*Root)->left == NULL){
        k = (*Root)->data;
        TreeType ptr = *Root;
        *Root = NULL;
        free(ptr);
        return k;
    }
    else
        return DeleteMin(&((*Root)->left));
}

void deleteNode(KeyType X, TreeType *Root){
    if(*Root != NULL){
        if(strcmp(X.email, (*Root)->data.email) < 0)
            deleteNode(X, &((*Root)->left));
        else if(strcmp(X.email, (*Root)->data.email) > 0)
            deleteNode(X, &((*Root)->right));
        else if((*Root)->left == NULL && (*Root)->right == NULL){
            TreeType ptr = *Root;
            *Root = NULL;
            free(ptr);
        }
        else if((*Root)->left == NULL){
            TreeType ptr = *Root;
            *Root = (*Root)->right;
            free(ptr);
        }
        else if((*Root)->right == NULL){
            TreeType ptr = *Root;
            *Root = (*Root)->left;
            free(ptr);
        }
        else{
            (*Root)->data = DeleteMin(&((*Root)->right));
        }
    }
}

void freeTree(TreeType tree){
    if(tree != NULL){
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
    }
}

void printTree(TreeType root){
    if(root != NULL){
        printf("%s: ", (root->data).email);
        TreeType ptr = root->left;
        if(ptr != NULL)
            printf("%s ", (ptr->data).email);
        ptr = root->right;
        if(ptr != NULL){
            printf("%s", (ptr->data).email);
        }
        printf("\n");
        printTree(root->left);
        printTree(root->right);
    }
}
