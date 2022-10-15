#include <stdio.h> 
 
int stackA[20],stackB[20],stackC[20]; 
 
int sizeA=0,sizeB=0,sizeC=0; 
 
void Push(int *stack,int item, int *size) 
{ 
		stack[*size] = item; 
		(*size)++; 
} 
 
int Pop(int *stack, int *size) 
{ 
	if( (*size) <= 0 ) 
	{ 
		return -1; 
	} 
	else 
	{ 
		int x = stack[(*size)-1]; 
		(*size)--; 
		return x; 
	} 
} 
 
void A_to_B() 
{ 
	int x; 
	while ( sizeA > 0 )   
	{ 
		x = Pop( stackA, &sizeA); 
		Push( stackB, x, &sizeB); 
	} 
	
} 
void B_to_C(){
    while ( sizeB > 0 ) 
	{   
	    int x;
		x = Pop( stackB, &sizeB); 
		Push( stackC, x, &sizeC); 
	} 
}
 
int main() 
{ 
	int size, iterI, item; 
	printf("Enter the size of the stack  ");
	scanf("%d",&size); 
    printf("Now enter the elements  ");
	for(iterI = 0; iterI<size; iterI++) 
	{ 
		scanf("%d",&item); 
		Push( stackA, item, &sizeA); 
	} 
	A_to_B();
	B_to_C();
	 
	for(int i=0;i<size;i++){
	    printf("%d  ",stackB[i]);
	}
}
