# Matrix Operations

This program reads a matrix from a text file, allocates dynamic memory for it, and performs various operations. The matrix is stored in the file in the following format:

N
a_0_0 a_0_1 ... a_0_N
a_1_0 a_1_1 ... a_1_N
...
a_N_0 a_N_1 ... a_N_N

## Features

1. **Read Matrix**: Reads the matrix from the input file.

2. **Dynamic Memory Allocation**: Allocates dynamic memory for the matrix.

3. **Element Validation**: Verifies that matrix elements are positive numbers between 65 and 90 (inclusive) or 0.

4. **Sum of Penultimate Column**: Calculates and displays the sum of elements in the penultimate column.

5. **Check for Null Rows or Columns**: Displays a message if the matrix has null rows or columns (all elements on that row or column are 0).

6. **Replace Secondary Diagonal Elements**: Writes to another file the matrix obtained from the initial matrix where the elements on the secondary diagonal are replaced with the character '*'.


## How to Use

1. Create a text file with the matrix data in the specified format.
2. Compile the program using a C compiler.
3. Run the executable, providing the input file as an argument.
4. Check the console for the results and messages.


