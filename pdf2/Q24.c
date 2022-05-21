/*
Question:
Write a program to replace each array element by its corresponding rank. Given an
array of distinct integers, replace each array element by its corresponding rank in the
array. The minimum array element has the rank 1; the second minimum element has a
rank of 2, and so on...
E.g.: Input: {10, 8, 15, 12, 6, 20, 1}
Output: {4, 3, 6, 5, 2, 7, 1}
*/

#include <stdio.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                // swap(&barr[j], &barr[j+1]);
            }
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        else if (arr[mid] < x)
        {
            return binarySearch(arr, mid + 1, r, x);
        }
    }

    return -1;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n = 7;
    int A[] = {10, 8, 15, 12, 6, 20, 1};
    int  B[n];
    for (int i = 0; i < n; i++)
        B[i] = A[i];
    
    bubbleSort(A, n);

    int key, pos;
    for (int i = 0; i < n; i++)
    {
        key = B[i];
        pos = binarySearch(A, 0, n-1, key);
        printf("%d ", pos+1);
    }

    // printArray(B, n);

}
