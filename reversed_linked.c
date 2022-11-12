#include<stdlib.h>
#include<stdio.h>
    //creating a struct called node to create linked lists. 
    struct node{
        int data;
        struct node* linkNext;
    };  
    typedef struct node Node; //making a node structure better abstraction and less typing.

    void printList(Node* head){
        Node* temp = head; //creates a temporary node and sets the value of the first node to it.
        while(temp != NULL){ //loops till node reaches the end of the list. i.e, the last node has a NULL value.
            printf((temp==head)?"%d":"->%d", temp->data); //prints the first node or the head node as it is and the rest with an arrow.
            temp = temp->linkNext; //points to the next node to move forward in the linkedList. 
        }
        printf("->NULL"); //ends the list by pointing to the null value.
    }


    void appendLast(Node **headAddress, int input)
    {
        Node *newNode = malloc(sizeof(Node)); //allocate memory for a new node
        newNode->data = input; //sets the data of the new node to the input by the user
        newNode->linkNext = NULL;
        if(*headAddress == NULL)
        {
            *headAddress= newNode; //sets the address to the new node, when the headAddress is null.
        }
        else //executes if the the headAddress is not null, therefore there are already nodes in the list, therefore it finds the previous node
        {
            Node *lastNode = *headAddress; //points to the head address or the first node
            while(lastNode -> linkNext != NULL) //checks for the lastNode since the last node will reference to the next Node which wil be null
            { 
                lastNode = lastNode -> linkNext;
            }
            lastNode -> linkNext = newNode; //adds the new node ahead of the last node at the end of the list

        }


    }

    void reverse_list(Node **headAddress){
        Node *previousNode = NULL;
        Node *currentNode = *headAddress;
        Node *nextNode = NULL;
        while(currentNode != NULL){
            nextNode = currentNode->linkNext; //points and links to the next node from from the head or the currentNode 
            currentNode->linkNext = previousNode; //sets the pointer and link of the current node to the previous node
            previousNode = currentNode; //sets the previous node to the current node to move forward in the list
            currentNode = nextNode; //sets the current node to the next node to move forward in the list
        } //loop runs till the last node is reached and the currentNode is set to NULL
        *headAddress = previousNode; //sets the address of the head node to the previous node, which is the last node in the list.
        Node *reversed_head= *headAddress; // creates a new node and sets the address of the head node to it.
        printf("\n\nThe reverse linked list is : \n");
        printList(reversed_head); //calls the print function to print the reversed list

    }

    int main()
    {
        Node *head= NULL; //creates a node head and sets it to null, this wil be the first node in the list
        
        int lengthList;
        int flag = 0;
        

        do{
            printf("Input the length of the linked list below:"); //asks the user for an input for the list
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
        printf("\nThe linked list is : \n");
        printList(head); //prints the linked list.  
        reverse_list(&head); //calls the function to reverse the linked list.

        
        return 0;

            
        }