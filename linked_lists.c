#include<stdlib.h>
#include<stdio.h>
    //creating a struct called node to create linked lists. 
    struct node{
        int data;
        struct node* linkNext;
    };  
    typedef struct node Node; //making a node structure better abstraction and less typing.

    void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            printf((temp==head)?"%d":"->%d", temp->data);
            temp = temp->linkNext;
        }
        printf("->NULL");
    }

    void appendLast(Node **headAddress, int input)
    {
        Node *newNode = malloc(sizeof(Node));
        newNode->data = input;
        newNode->linkNext = NULL;
        if(*headAddress == NULL)
        {
            *headAddress= newNode; //sets the address to the new node, when the headAddress is null.
        }
        else
        {
            Node *lastNode = *headAddress;
            while(lastNode -> linkNext != NULL)
            {
                lastNode = lastNode -> linkNext;
            }
            lastNode -> linkNext = newNode;

        }


    }


    //adding a function to add values to the created linked lists
    int main()
    {
        Node *head= NULL;
        
        int lengthList;
        int flag = 0;
        

        do{
            printf("Input the length of the linked list below:");
            scanf("%d", &lengthList);
            if(lengthList<=0){
                printf("Length of the list is invalid and should be positive!"); //invalid for negative input since length should be positive
                flag=1; //sets flag to 1 to to repeat the loop
            }
            else{
                flag=0; //exits the loop if the length is correct
            }
           


        }while(flag == 1);
        
        int i = 0;
    //adding values through linked lists throug user
        while(i<lengthList)
        {
            int value;
            printf("Enter the value of the node %d:", i+1);
            scanf("%d", &value);
            appendLast(&head, value); //calling the function to append the value to the last node of the linkedList.
            i++;
            }

        printList(*head);

        
        return 0;

            
        }