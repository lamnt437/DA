/*Exercise 2*/

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
void inOrder(TreeType root);
TreeType pop(TreeType stack[], int *top);
void push(TreeType stack[], int *top, TreeType temp);
void i_inOrder(TreeType root);

int start = 0;
int end = 0;
int counter = 0;
TreeType queue[50];

int isEmpty(){
    return counter == 0;
}

void enqueue(TreeType root){
    if(counter < 50){
        queue[end] = root;
        end = (end + 1)%50;
        counter++;
        //printf("enqueue: %s%s%s\n", (root->data).name);
    }
}

TreeType dequeue(){
    if(counter >0){
        TreeType temp = queue[start];
        //printf("dequeue: %s%s%s\n", (temp->data).name);
        start = (start + 1)%50;
        counter--;
        return temp;
    }
}

void BFS(TreeType root);
void preOrder(TreeType root){
	if(root != NULL){
		printf("%20s%20s%20s\n", (root->data).name, (root->data).email, (root->data).phone);
		preOrder(root->left);
		preOrder(root->right);
	}
}
/* 
void preOrder(TreeType root){
	if(root != NULL){
		printf("%20s%20s%20s\n", (root->data).name, (root->data).email, (root->data).phone);
		preOrder(root->left);
		preOrder(root->right);
	}
}
*/


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

    int choice, choice2;
    char key[MAX_LENGTH];
    Element temp;
    TreeType ptr = NULL;
    printf("1 - print tree\n2 - search\n3 - delete\n4 - quit\n?");
    scanf("%d", &choice);

    while(choice != 4){
        switch(choice){
        case 1://PRINT
        /*
        	do{
	        	printf("1 - pre, 2 - in, 3 - post?");
	        	scanf("%d", &choice2)
       		}while(choice2 != 1 && choice2 != 2 && choice2 != 3);
       		switch(choice2){
       			case 1:

       				break;

       			case 2:	
       				break;

       			case 3: 
       				break;
       		}
       		*/
            //BFS(root);
            //enqueue(root);
            //printf("counter: %d\n", counter);
            //TreeType buff = dequeue();
            //BFS(root);
        	i_inOrder(root);
            //printf("%s\ncounter: %d\nstart: %d\nend: %d\n", (buff->data).name, counter, start, end);
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

void inOrder(TreeType root){
    if(root != NULL){
        inOrder(root->left);
        printf("%15s%15s%15s\n", (root->data).name, (root->data).phone, (root->data).email);
        inOrder(root->right);
    }
}

void BFS(TreeType root){
    if(root != NULL){
        enqueue(root);
        TreeType temp;
        while(counter > 0){
            temp = dequeue();
            printf("%20s%20s%20s\n", (temp->data).name, (temp->data).email, (temp->data).phone);
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
		//printf("Pop: %20s%20s%20s\n", (temp->data).name, (temp->data).email, (temp->data).phone);
		*top = (*top) - 1;
	}
	return temp;
}

void push(TreeType stack[], int *top, TreeType temp){
	if(*top < STACK_SIZE){
		*top = (*top) + 1;
		stack[*top] = temp;
		//printf("Push: %20s%20s%20s\n", (temp->data).name, (temp->data).email, (temp->data).phone);
	}
}

void i_inOrder(TreeType root){
	int top = -1;
	TreeType stack[STACK_SIZE];
	while(1){
		for(; root; root = root->left)
			push(stack, &top, root);
		root = pop(stack, &top);
		if(root == NULL)
			break;
		printf("%20s%20s%20s\n", (root->data).name, (root->data).email, (root->data).phone);
		root = root->right;
	}
}