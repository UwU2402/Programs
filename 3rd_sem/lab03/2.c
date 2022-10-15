//Q2
//Given two sorted arrays A and B. 
///Array A is full and array B is partially full and the number of empty slots are just enough to accommodate all elements of array A. 
//Write one C program to merge the two sorted arrays to fill the array B without using the third array.

#include <stdio.h>

void merge(int array1[], int array2[], int m, int n)
{
    for (int i = n - 1; i >= 0; i--) 
    {
     
        int j, last = array1[m - 1];
        for (j = m - 2; j >= 0 
             && array1[j] > array2[i]; j--)
            array1[j + 1] = array1[j];

        if (j != m - 2 || last > array2[i]) 
        {
            array1[j + 1] = array2[i];
            array2[i] = last;
        }
    }
}

int main()
{

   int m,n;
  scanf("%d%d",&m,&n);
  int array1[m],array2[n];
  for(int i=0;i<m;i++){
    scanf("%d",&array1[i]);
  }
 for(int i=0;i<n;i++){
    scanf("%d",&array2[i]);
  } 
    merge(array1, array2, m, n);

    for (int i = 0; i < m; i++)
        printf("%d ",array1[i]);
 
    for (int i = 0; i < n; i++)
        printf("%d ",array2[i]);
    return 0;
}
