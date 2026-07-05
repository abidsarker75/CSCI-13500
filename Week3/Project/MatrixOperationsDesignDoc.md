# Program Design Document

## Program Name

Matrix Operations

## Purpose

This program will perform different operations on 2D arrays or matrices. It can print a matrix, add two matrices, transpose a matrix, find a determinant, search for a value, and multiply two matrices. The program uses functions to complete all of this and then print it out as the output.

---

## Outputs

The program displays:

- Start and finish messages for each function
- The original matrix values
- The result of matrix addition
- The transposed matrix
- The determinant of a 2x2 or 3x3 matrix
- The row and column indexes where a searched target value appears
- A message when a target value is not found
- The result of matrix multiplication
- Messages when matrix dimensions are invalid

---

## Key Design Choices

- I used separate `void` functions because each function completes one specific matrix operation. This makes the program easier to read, test, and reuse.

- I used nested `for` loops because a 2D array has rows and columns. The outer loop moves through rows, while the inner loop moves through columns.

- I created a separate `result` matrix for addition, transpose, and multiplication so the original input matrices are not modified.

- I used `if`, `else if`, and `else` statements to check valid dimensions before operations such as determinant and matrix multiplication.

- I used a `bool` variable named `found` in `SearchValue()` to remember whether the target appeared anywhere in the matrix.

- The provided function parameters use `[][3]`, so the program works with matrices that have 3 columns.

---

## Program Steps (Algorithm)

1. Declare two 3x3 integer matrices in `main()`.
2. Calculate the number of rows and columns using `sizeof`.
3. Call `Print2DArray()` to display a matrix.
4. Call `MatrixAddition()` to add matching values from two matrices into a new result matrix.
5. Call `TransposeMatrix()` to switch the rows and columns of a matrix.
6. Call `Determinant()` to calculate and print the determinant of a valid 2x2 or 3x3 matrix.
7. Call `SearchValue()` to check every matrix value for a target number.
8. Call `MatrixMultiplication()` to multiply two compatible matrices and print the result.
9. Display start and finish messages so it is clear when each function runs.

---

## Functions:

### Function: `Print2DArray()`

Prints every value in a 2D array. Each row is displayed inside square brackets, and columns are separated by vertical bars.

### Function: `MatrixAddition()`

Adds two matrices with matching dimensions. It stores the sums in a new result matrix and prints that matrix without changing either original matrix.

### Function: `TransposeMatrix()`

Switches a matrix's rows and columns. The value at `[row][column]` is placed at `[column][row]` in a new result matrix.

### Function: `Determinant()`

Calculates and prints the determinant of a 2x2 or 3x3 matrix. It prints an error message for invalid matrix sizes.

### Function: `SearchValue()`

Searches every position in the matrix for a target value. It prints all row and column indexes where the target is found, or prints a message if the target does not exist in the matrix.

### Function: `MatrixMultiplication()`

Multiplies two compatible matrices. It checks whether the matrix dimensions allow multiplication, stores the answer in a new result matrix, and prints the result.

---

## Sample Output

Matrix one:
Print2DArray started.
[1 | 2 | 3]
[4 | 5 | 6]
[7 | 8 | 9]
Print2DArray has completed.

MatrixAddition started.
Added matrix:
Print2DArray started.
[13 | 67 | 85]
[87 | 7 | 14]
[17 | 104 | 76]
Print2DArray has completed.
MatrixAddition has completed.

TransposeMatrix has started.
Transposed matrix:
[1 | 4 | 7]
[2 | 5 | 8]
[3 | 6 | 9]
TransposeMatrix has completed.

Determinant started.
Determinant: 0
Determinant has completed.

SearchValue started.
Found the96 at [2][1]
SearchValue has completed.

MatrixMultiplication started.
Multiplied matrix:
Print2DArray started.
[208 | 357 | 299]
[523 | 846 | 770]
[838 | 1335 | 1241]
Print2DArray has completed.
MatrixMultiplication has completed.

### AI Reflection:

In this program I used AI and I used ChatGBT. I was struggling with the transpose matrix and AI helped me with the steps
needed to do this.
