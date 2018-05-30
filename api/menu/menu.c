#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int choice;


    printf("\
            1 - \n\
            2 - \n\
            3 - \n\
            4 - \n\
            5 - \n\
            6 - EXIT\n\
            ?");
    scanf("%d", &choice);
    // getchar();

    while(choice != 6){
        switch(choice){
            case 1:
                printf("\n\n\n");
                
                break;
            case 2:
                printf("\n\n\n");
                
                break;
            case 3:
                printf("\n\n\n");

                break;
            case 4:
                printf("\n\n\n");

                break;
            case 5:
                printf("\n\n\n");
                
                break;
            default:
                printf("\nOut of range!\n\n");
                break;
        }
        printf("\
            1 - \n\
            2 - \n\
            3 - \n\
            4 - \n\
            5 - \n\
            6 - EXIT\n\
            ?");
        scanf("%d", &choice);
        // getchar();
    }
    printf("\nEXIT\n");

    return 0;
}