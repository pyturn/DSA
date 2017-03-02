#include <stdio.h>
#include <stdlib.h>

struct MaxHeap
{
    int size;
    int* array;
};

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b;  
    *b = t; 
} 


void maxHeapify(struct MaxHeap* maxHeap, int index)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;


    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
    {
	    largest = left;
    }
		
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
    {
	    largest = right;
    }	

    if (largest != index)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[index]);
        maxHeapify(maxHeap, largest);
    }
}

struct MaxHeap* createHeap(int *array, int size)
{
    int i;
    struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;   
    maxHeap->array = array; 

    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
    {
        maxHeapify(maxHeap, i);
    }
	    
    return maxHeap;
}

void heapSort(int* array, int size)
{

    struct MaxHeap* maxHeap = createHeap(array, size);

    while (maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;  
        maxHeapify(maxHeap, 0);
    }
}

void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {16, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array is \n");
    printArray(arr, size);
    printf("\n");

    heapSort(arr, size);

    printf("Sorted array is \n");
    printArray(arr, size);
    printf("\n");
    return 0;
}


