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

 
    void insertionSortLinked(Node **headAddress) 
    {
        Node *currentNode= malloc(sizeof(Node)); //creating a node to store the head of current node which points to the sorted array upto that point
        Node *next;
        Node *temp; //stores the value of the next node to be compared with the current node
        
        while((*headAddress)==NULL) //outer loop runs till the end of the list 
        {
            next=(*headAddress)->linkNext; 
            while(temp->linkNext->data<(*headAddress)->data && temp->linkNext)
            {
                temp=temp->linkNext;
            }  //moves the temp node to the next node
            (*headAddress)->linkNext=temp->linkNext;
        

        
        }

    

        

    }
    //adding a function to add values to the created linked lists
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

        printList(head); //prints the linked list. 
        printf("\nYour sorted linked list is:\n");
        insertionSortLinked(&head); //calls the function to sort the linked list
        printList(head); //prints the sorted linked list

        
        return 0;

            
        }