/*
Question:
Write a program to find pairs with difference `k` in an array. Implement it in linear
time using hash table.
*/

#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int hash(int ele, int n)
{
    return ele % n;
}

void insert(int ht[], int n, int ele)
{
    int key = hash(ele, n);
    for (int i = 0; i < (n-key); i++)
    {
        if (ht[key+i] == -1)
        {
            ht[key+i] = ele;
            return;
        }
    }
    for (int i = 0; i < key; i++)
    {
        if (ht[i] == -1)
        {
            ht[i] = ele;
            return;
        }
    }
}

int Search(int ht[], int n, int ele)
{
    int key = hash(ele, n);
    for (int i = 0; i < (n-key); i++)
    {
        if (ht[key+i] == ele)
        {
            return 1;
        }
    }
    for (int i = 0; i < key; i++)
    {
        if (ht[i] == ele)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    printf("Enter the number of elements : ");
    int n;
    scanf("%d", &n);
    
    int ht[n];
    // initialize hash table with -1
    for (int i = 0; i < n; i++)
        ht[i] = -1;
    
    printf("Enter the elements : \n");
  

    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        insert(ht, n, temp);
    }

    printArray(ht, n);

    printf("Enter the value of k : ");
    int k;
    scanf("%d", &k);

    printf("The pairs with difference k : \n");
    int a,b;
    for (int i = 0; i < n; i++)
    {
        a = ht[i];
        b = a-k;
        if (Search(ht, n, b))
        {
            printf("(%d,%d)\n", a,b);
        }
    }
}
