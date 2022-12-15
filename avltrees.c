 #include <stdlib.h>
#include <stdio.h>
//buidling AVL tree
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

