#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//program to implement skip lists in C 
typedef struct node
{
    int val;
    struct node **forward;
} node;

//function to create a new node
struct node *createNode(int val, int level)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->val = val;
    new->forward = (struct node **)malloc((level + 1) * sizeof(struct node *));
    return new;
}

//function to create a new skip list

struct skipList *createSkipList(int maxLevel, float prob)
{
    struct skipList *new = (struct skipList *)malloc(sizeof(struct skipList));
    new->maxLevel = maxLevel;
    new->prob = prob;
    new->header = createNode(-1, maxLevel);
    return new;
}


//function to create a random level for the node

int randomLevel(struct skipList *sl)
{
    int lvl = 0;
    while (rand() < sl->prob * RAND_MAX && lvl < sl->maxLevel)
        lvl++;
    return lvl;
}

//function to insert a node in the skip list
