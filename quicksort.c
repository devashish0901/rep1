#include <stdlib.h>
#include <stdio.h>
#include<time.h>


void swap(int *arrA, int *arrB)
{
    int temp;
    temp = *arrA;
    *arrA = *arrB;
    *arrB = temp;
}
int* GenerateRandom(int s)
{
    int* tempArr = (int*)malloc(s*sizeof(int));
    for(int i=0; i<s; i++)
    {
        tempArr[i] = rand()%2000; //assigning random values to the array up to 2000 values
    }
    return tempArr;
}

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


// partition function takes a random element, makes two partitions and sticks the pivot element in the correct position (rank) which is returned and stored as p
int partition(int *a, int start, int stop) 
{
    int r = start + rand() % (start - stop);
  
    int temp = a[r];
    a[r] = a[start];
    a[start] = temp;
    int pivot = a[start];
    int i = start+1;
    int j = stop;
    while(i<=j)
    {
        if(a[i] > pivot)
        {
         swap(&a[i], &a[j]);
         j--;
        }
        else
        {
            i++;
        }
        
    
}
swap(&a[start], &a[j]);
return j;
}
   
void quicksort(int *a, int start, int stop) {
    // boundary conditions to ensure validity of function call
	if (!a || start >= stop) return;
    if (start<stop)
    {
        int p = partition(a, start, stop);
        quicksort(a, start, p-1);
        quicksort(a, p+1, stop);

    }
}




void print(int *arrU, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d", arrU[i]);
        printf(" ");
    }

}


int main(int argc, char** argv)
{
    srand(time(NULL));
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
    printf("\nEnter 1 for random array or 2 for user input array: \n");
    int choice; //choice of the user    
    scanf("%d", &choice);
    do{
        if(choice!=1 && choice!=2)
        {
            printf("Enter a valid choice");
            scanf("%d", &choice);
            flag=1;
        }
        else
        {
            flag=0;
        }
    }while(flag==1);
    int *arrU; //array Unsorted

    if(choice==1)
    {
        arrU = GenerateRandom(size);
    }
    else
    {
        arrU = UserInput(size);
    }

    printf("\nYour array is:\n ");
    print(arrU, size);
    quicksort(arrU, 0, size-1);
    printf("\nYour sorted array is:\n ");
    print(arrU, size);
    return 0;


}
