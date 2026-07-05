#include <iostream>

// Prints a 2D array with rows in brackets and columns separated by bars.
// The time complexity is O(n) because it loops through the values of the matrix.
void Print2DArray(const int matrix_local[][3],
                  const int matrix_local_rows_total)
{
    std::cout << "Print2DArray started." << std::endl;

    // Goes through the rows.
    for (int row = 0; row < matrix_local_rows_total; row++)
    {
        std::cout << "[";

        // Goes through the columns
        for (int column = 0; column < 3; column++)
        {
            std::cout << matrix_local[row][column];
            if (column < 2)
            {
                std::cout << " | ";
            }
        }

        std::cout << "]" << std::endl;
    }
    std::cout << "Print2DArray has completed." << std::endl;
}

// This will add two matrices without changing any of the original matrix.
// The time complexity of this is O(n) because it will loop to add each matching value.
void MatrixAddition(const int matrix_one[][3],
                    const int matrix_one_rows_total,
                    const int matrix_two[][3],
                    const int matrix_two_rows_total)
{
    std::cout << "MatrixAddition started." << std::endl;

    // Will check if both matrices have the same number of rows
    if (matrix_one_rows_total != matrix_two_rows_total)
    {
        std::cout << "The matrices don't have the same dimensions." <<std::endl;
        std::cout << "MatrixAddition has completed." << std::endl;
        return;
    }

    // Will stores the sum without changing both input matrix
    int result[3][3] = {};

    for (int row = 0; row < matrix_one_rows_total; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            result[row][column] =
                matrix_one[row][column] + matrix_two[row][column];
        }
    }

    std::cout << "Added matrix:" << std::endl;
    Print2DArray(result, matrix_one_rows_total);
    std::cout << "MatrixAddition has completed." << std::endl;
}

// This will switch rows and columns of a matrix
// The time complexity is O(n) to find and move each value once.
void TransposeMatrix(const int matrix_local[][3],
                     const int matrix_local_rows_total)
{
    std::cout << "TransposeMatrix has started." << std::endl;

    int completed[3][3] = {};

    // This stores each value in the switched row and column.
    for (int row = 0; row < matrix_local_rows_total; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            completed[column][row] = matrix_local[row][column];
        }
    }


    std::cout<< "Transposed matrix:" << std::endl;
    for (int row = 0; row < 3; row++)
    {
        std::cout << "[";

        for (int column = 0; column < matrix_local_rows_total; column++)
        {
            std::cout << completed[row][column];

            if (column < matrix_local_rows_total - 1)
            {
                std::cout << " | ";
            }
        }

        std::cout << "]" << std::endl;
    }
    std::cout << "TransposeMatrix has completed." << std::endl;
}

// Finds the determinant of a 3x3 or 2x2 matrix.
// The time complexity is O(1) because it has a fix amount because its only 3x3 or 2x2 matrix.
void Determinant(const int matrix_local[][3], const int size)
{
    std::cout << "Determinant started." << std::endl;

    if (size == 2)
    {
        // Formula: ad - bc
        int determinant =
            (matrix_local[0][0] * matrix_local[1][1]) - (matrix_local[0][1] * matrix_local[1][0]);

        std::cout << "Determinant: " << determinant << std::endl;
    }
    else if (size == 3)
    {
        // 3x3 determinant formula.
        int determinant =
            matrix_local[0][0] * (matrix_local[1][1] * matrix_local[2][2] - matrix_local[1][2] * matrix_local[2][1])
            -
            matrix_local[0][1] * (matrix_local[1][0] * matrix_local[2][2] - matrix_local[1][2] * matrix_local[2][0])
            +
            matrix_local[0][2] * (matrix_local[1][0] * matrix_local[2][1] - matrix_local[1][1] * matrix_local[2][0]);

        std::cout << "Determinant: " <<determinant <<std::endl;
    }
    else
    {
        std::cout << "Invalid matrix size. Only 2x2 and 3x3 are allowed."<< std::endl;
    }
    std::cout << "Determinant has completed." << std::endl;
}

// Searches for a target number in the matrix.
// The time complexity is O(n) because it may check every value of the matrix.
void SearchValue(const int matrix_local[][3],
                 const int rows,
                 const int target)
{
    std::cout << "SearchValue started." << std::endl;

    bool found = false;

    // Checks every value in the matrix
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (matrix_local[row][column] == target)
            {
                std::cout << "Found the" << target << " at [" << row << "][" << column << "]"<< std::endl;
                found = true;
            }
        }
    }

    if (found == false)
    {
        std::cout << target << " was not found in the matrix."
                  << std::endl;
    }

    std::cout << "SearchValue has completed." << std::endl;
}

// This multiplies two square matrices.
// The time complexity is O(n^3) because three nested loops depending on matrix size.
void MatrixMultiplication(const int matrix_a[][3],
                          const int matrix_b[][3],
                          const int rows_a,
                          const int cols_a,
                          const int rows_b,
                          const int cols_b)
{
    std::cout<< "MatrixMultiplication started." <<std::endl;

    // Checks if columns of A are equal rows of B. This is necessary for the multiplication to happen.
    if (cols_a != rows_b)
    {
        std::cout << "Matrices cannot be multiplied." << std::endl;
        std::cout << "MatrixMultiplication finished." << std::endl;
        return;
    }

    // This project only supports matrices up to 3x3.
    if (rows_a > 3 || cols_a > 3 || rows_b > 3 || cols_b > 3)
    {
        std::cout << "Matrix size is too big, cannot be bigger than 3x3."<< std::endl;
        std::cout << "MatrixMultiplication has completed." << std::endl;
        return;
    }

    int result[3][3] = {};

    // Multiplies the rows of matrix A by the columns of matrix B.
    for (int row = 0; row < rows_a; row++)
    {
        for (int column = 0; column < cols_b; column++)
        {
            for (int position = 0; position < cols_a; position++)
            {
                result[row][column] += matrix_a[row][position] * matrix_b[position][column];
            }
        }
    }

    std::cout << "Multiplied matrix:" << std::endl;
    Print2DArray(result, rows_a);
    std::cout << "MatrixMultiplication has completed." << std::endl;
}

int main()
{
    int testing_matrix_one[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int testing_matrix_two[3][3] = {
        {12, 65, 82},
        {83, 2, 8},
        {10, 96, 67}
    };

    // Calculates the dimensions of the first matrix.
    int size_row_one = sizeof(testing_matrix_one) / sizeof(testing_matrix_one[0]);
    int size_col_one = sizeof(testing_matrix_one[0]) / sizeof(testing_matrix_one[0][0]);

    // Calculates the dimensions of the second matrix.
    int size_row_two = sizeof(testing_matrix_two) / sizeof(testing_matrix_two[0]);
    int size_col_two = sizeof(testing_matrix_two[0]) /sizeof(testing_matrix_two[0][0]);

    std::cout << "Matrix one:" << std::endl;
    Print2DArray(testing_matrix_one, size_row_one);
    std::cout << std::endl;

    MatrixAddition(testing_matrix_one, size_row_one, testing_matrix_two, size_row_two);
    std::cout << std::endl;

    TransposeMatrix(testing_matrix_one, size_row_one);
    std::cout << std::endl;

    Determinant(testing_matrix_one, size_row_one);
    std::cout << std::endl;

    SearchValue(testing_matrix_two, size_row_two, 96);
    std::cout << std::endl;

    MatrixMultiplication(testing_matrix_one,testing_matrix_two,size_row_one,size_col_one,size_row_two,size_col_two);

    return 0;
}