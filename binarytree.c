#include <stdlib.h>
#include <stdio.h>

struct Nodetype {
    int val;
    struct Nodetype *left; //Everything to the left is small
    struct Nodetype *right; //Everything to the right is large
};
typedef struct Nodetype *NodeAddress;

int* UserInput(int n)
{
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        printf("Enter the value of the element %d", i+1);
        printf(": ");
        scanf("%d", &arr[i]);
    }
    return arr;
}

NodeAddress createNode(int val) {
    NodeAddress new = malloc(sizeof(NodeAddress));
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

NodeAddress search(NodeAddress root, int val)
{
    if (root == NULL) 
    {return NULL;} //special case for null 
    if (val < root->val) 
    {return search(root->left, val);} //searches the left side of the tree
    else if (val > root->val) 
    {return search(root->right, val);} //searches the right side of the tree
    else {return root;} //returns the node if it is found
}

NodeAddress insert(NodeAddress root, int val)
{
    if (root == NULL)
    { return createNode(val);} //creates a new node if the tree is empty
    if (val < root->val) 
    { root->left = insert(root->left, val);} //inserts the value to the left of the tree
    else if (val > root->val) 
    {root->right = insert(root->right, val);} //inserts the value to the right of the tree
    return root;
}
NodeAddress arrayToBST(int *a, int n)
{
    NodeAddress root = NULL;
    root = insert(root, a[0]);
    for (int i = 1; i < n; i++) {
        root = insert(root, a[i]);
    }
    return root;
    /*if (root == NULL) 
    {return NULL;} //special case for null 
    NodeAddress temp = root->left; //creates a temporary node and sets the value of the left node to it.
    root->left = root->right; //swaps the left node with right node
    root->right = temp; //sets the right node to the temporary node which is the left node
    if(root->left!=NULL){arrayToReverseBST(root->left);} //recursively calls the function till the left node is not null
    if(root->right!=NULL){arrayToReverseBST(root->right);}//recursively calls the function till the right node is not null
    return root; */
}

void prefixPrint(NodeAddress root) {
    if(root) printf(" %d ", root->val);
	if(root->left) prefixPrint(root->left);       
	if(root->right) prefixPrint(root->right);
}


void printHorizontal(NodeAddress root, int dist)
{
 
    if (root == NULL) return; // if the current node is NULL then we just return.

    // Every time the function runs we add 5 to the 'dist' counter 
	// to increase the distance between the elements being printed
    dist += 10;

	// Recursing to the right branch, this reaches the last right branch and prints it
    printHorizontal(root->right, dist);

	// Actual printing happens here
    printf("\n");
    for (int i = 10; i < dist; i++) printf(" "); // Printing 'dist' number of spaces
    printf("%d\n", root->val); // then printing the value
 
    // Now we recurse to the left branch
    printHorizontal(root->left, dist);

}



int main(int argc, char **argv)
{
    int flag=0;
    printf("Enter the size of the Array you want to input: \n");
    int size; //size of the array
    scanf("%d", &size);
    do{
        if(size<=0){
            printf("Enter a valid size");
            scanf("%d", &size);
            flag=1;
        }
        else
        {
            flag=0;
        }
    }while(flag==1);
    int *a = UserInput(size);
    NodeAddress root = arrayToBST(a, size);
    
     printHorizontal(root,0);
     prefixPrint(root);
    
    return 0;
}