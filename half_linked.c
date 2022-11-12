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
    void printhalfList(Node* head, Node *end){
        printf("\n\nThe first half of the linked List is: \n");
        Node* temp = head; //creates a temporary node and sets the value of the first node to it.
        while(temp != end){ //loops till node reaches the end of the list. i.e, the value from the har.e-tortiose method, slow pointer or halfway
            printf("%d", temp->data); 
            printf("->"); //prints the first node or the head node as it is and the rest with an arrow.
            temp = temp->linkNext; //points to the next node to move forward in the linkedList. 
        }
        printf("NULL"); //ends the list by pointing to the null value.
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

    void halfList(Node **headAddress){
        Node *slowerPtr = *headAddress; //creats a slower pointer to point to the head address
        Node *fasterPtr = *headAddress; //creates a faster pointer to point to the head address
        while(fasterPtr != NULL && fasterPtr->linkNext != NULL){ //checks if the faster pointer is not null and the next node is not null
            fasterPtr = fasterPtr->linkNext->linkNext; //moves the faster pointer by 2 nodes
            slowerPtr = slowerPtr->linkNext; //moves the slower pointer by 1 node
        }
        printhalfList(*headAddress, slowerPtr); //calls the print function to print the first half of the list
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
        printf("\nThe linked list is: \n");
        printList(head); //prints the linked list. 
        halfList(&head);
        
        return 0;

            
        }