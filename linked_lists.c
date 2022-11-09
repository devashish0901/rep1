#include<stdlib.h>
#include<stdio.h>

    //creating a struct called node to create linked lists. 
    struct node{
        int input;
        struct node* next;
    };  

    //adding a function to add values to the created linked lists
    int main(int argc, char** argv)
    {
        struct node *linked_lists = NULL;
        int length_List;
        int flag = 0;

        do
        {
            printf("Input the length of the linked list below:");
            scanf("%d", &length_List);
            if(length_List<=0){
                printf("Length of the list is invalid and should be positive!"); //invalid for negative input since length should be positive
                flag=1; //sets flag to 1 to to repeat the loop
            }
            else{
                flag=0; //exits the loop if the length is correct
            }
           


        } while(flag == 1);
            {
               printf("Length of the list is invalid and should be positive!"); 
            }

    }