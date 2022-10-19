#include <stdio.h>
#include <stdlib.h>
#define MAXHT 50
struct MinNode {
  char item;
  unsigned freq;
  struct MinNode *left, *right;
};
struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinNode **array;
};
int main() 
{
char arr[] = {'A', 'B', 'C', 'D'};
int freq[] = {5, 1, 6, 3};
int size = sizeof(arr) / sizeof(arr[0]);
printf("Huffman code");
HuffmanCodes(arr, freq, size);
}
