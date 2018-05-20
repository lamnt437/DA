#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
#define STACK_SIZE 50
#define MAX_LENGTH 100

typedef struct element{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
}Element;
typedef Element KeyType;

typedef struct Node {
  KeyType data;
  struct Node* left;
  struct Node* right;
} NodeType;
typedef struct Node* TreeType;

int start = 0;
int end = 0;
int counter = 0;
TreeType queue[STACK_SIZE];

TreeType InsertNode(KeyType x, TreeType Root);
void enqueue(TreeType root);
TreeType dequeue();
void inOrder(TreeType root);
void BFS(TreeType root, FILE *write);
TreeType pop(TreeType stack[], int *top);
void push(TreeType stack[], int *top, TreeType temp);
void stack_inOrder(TreeType root);

int main(int argc, char *argv[]){
    //check arguments
    if(argc != 3){
        puts("Wrong number of arguments!");
        return 1;
    }
    FILE *read = fopen(argv[1], "rb");
    FILE *write = fopen(argv[2], "wb");
    if(read == NULL){
        puts("Input file doesn't exist!");
        return 2;
    }

    //input
    Element buff;
    TreeType root = NULL;
    while(fread(&buff, sizeof(Element), 1, read)){
        root = InsertNode(buff, root);
    }
    fclose(read);

    //traverse
    int choice;
    do{
        printf("1-inOrder traversal, 2-inOrder traversal using stack, 3-BFS?");
        scanf("%d", &choice);
    }while(choice != 1 && choice != 2 && choice != 3);

    switch(choice){
    case 1:
        printf("\nIN-ORDER TRAVERSAL\n\n");
        inOrder(root);
        break;
    case 2:
        printf("\nIN-ORDER TRAVERSAL USING STACK\n\n");
        stack_inOrder(root);
        break;
    case 3:
        printf("\nBFS\n\n");
        BFS(root, write);
        printf("Result has been written to %s!\n", argv[2]);
        break;
    }

    fclose(write);
    return 0;
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

void enqueue(TreeType root){
    if(counter < 50){
        queue[end] = root;
        end = (end + 1)%50;
        counter++;
    }
}

TreeType dequeue(){
    if(counter >0){
        TreeType temp = queue[start];
        start = (start + 1)%50;
        counter--;
        return temp;
    }
}

void inOrder(TreeType root){
    if(root != NULL){
        inOrder(root->left);
        printf("%20s%20s%20s\n", (root->data).name, (root->data).phone, (root->data).email);
        inOrder(root->right);
    }
}

void BFS(TreeType root, FILE *write){
    TreeType temp = NULL;
    if(root != NULL){
        enqueue(root);
        while(counter > 0){
            temp = dequeue();
            printf("%20s%20s%20s\n", (temp->data).name, (temp->data).phone, (temp->data).email);
            fwrite(&(temp->data), sizeof(KeyType), 1, write);
            if(temp->left != NULL)
                enqueue(temp->left);
            if(temp->right != NULL)
                enqueue(temp->right);
        }
    }
}

TreeType pop(TreeType stack[], int *top){
	TreeType temp =  NULL;
	if(*top >=  0){
		temp = stack[*top];
		*top = (*top) - 1;
	}
	return temp;
}

void push(TreeType stack[], int *top, TreeType temp){
	if(*top < STACK_SIZE){
		*top = (*top) + 1;
		stack[*top] = temp;
	}
}

void stack_inOrder(TreeType root){
    TreeType stack[STACK_SIZE];
    int top = -1;
    while(1){
        for(; root; root = root->left)
            push(stack, &top, root);
        root = pop(stack, &top);
        if(root == NULL)
            break;
        printf("%20s%20s%20s\n", (root->data).name, (root->data).phone, (root->data).email);
        root = root->right;
    }
}

