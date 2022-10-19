// C program to find adjoint and inverse of a matrix
#include <stdio.h>

#define N 3

// Function to get cofactor of A[p][q] in temp[][]. n is
// current dimension of A[][]
void getCofactor(int A[N][N], int temp[N][N], int p, int q,
				int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			// Copying into temporary matrix only those
			// element which are not in given row and
			// column
			if (row != p && col != q) {
				temp[i][j++] = A[row][col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

/* Recursive function for finding determinant of matrix.
n is current dimension of A[][]. */
int determinant(int A[N][N], int n)
{
	int D = 0; // Initialize result

	// Base case : if matrix contains single element
	if (n == 1)
		return A[0][0];

	int temp[N][N]; // To store cofactors

	int sign = 1; // To store sign multiplier

	// Iterate for each element of first row
	for (int f = 0; f < n; f++) {
		// Getting Cofactor of A[0][f]
		getCofactor(A, temp, 0, f, n);
		D += sign * A[0][f] * determinant(temp, n - 1);

		// terms are to be added with alternate sign
		sign = -sign;
	}

	return D;
}

// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(int A[N][N], int adj[N][N])
{
	if (N == 1) {
		adj[0][0] = 1;
		return;
	}

	// temp is used to store cofactors of A[][]
	int sign = 1, temp[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// Get cofactor of A[i][j]
			getCofactor(A, temp, i, j, N);

			// sign of adj[j][i] positive if sum of row
			// and column indexes is even.
			sign = ((i + j) % 2 == 0) ? 1 : -1;

			// Interchanging rows and columns to get the
			// transpose of the cofactor matrix
			adj[j][i] = (sign) * (determinant(temp, N - 1));
		}
	}
}



 void display(int A[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

// Driver program
int main()
{
	int A[N][N];
    printf("Enter element in 3 X 3 matrix \n");
    for (int i = 0; i < N; i++)
    {   
        for (int j = 0; j < N; j++)
        scanf("%d",&A[i][j]);
    }
    

	int adj[N][N]; // To store adjoint of A[][]

	float inv[N][N]; // To store inverse of A[][]

	printf("Input matrix is :\n");
	display(A);

	printf("\nThe Adjoint is :\n");
	adjoint(A, adj);
	display(adj);


	return 0;
}
