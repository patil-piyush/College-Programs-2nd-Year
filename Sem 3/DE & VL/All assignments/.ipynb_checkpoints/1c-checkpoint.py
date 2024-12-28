import numpy as np

# Define Matrix 1 and Matrix 2 using numpy arrays
matrix1 = np.array([[3, 5, 7], 
                    [2, 4, 6], 
                    [1, 8, 9]])

matrix2 = np.array([[1, 0, 2], 
                    [4, 5, 6], 
                    [7, 8, 9]])

# Display the matrices
print("Matrix 1:\n", matrix1,"\n")
print("Matrix 2:\n", matrix2)

# Matrix Addition
add = matrix1 + matrix2
print("\nMatrix Addition:\n", add)

# Matrix Subtraction
subtract = matrix1 - matrix2
print("\nMatrix Subtraction:\n", subtract)

# Element-wise Matrix Multiplication
multiply = matrix1 * matrix2
print("\nElement-wise Matrix Multiplication:\n", multiply)

# Matrix Multiplication (Dot Product)
multiply_dot = np.dot(matrix1, matrix2)
print("\nMatrix Multiplication (Dot Product):\n", multiply_dot)

# Matrix 1:
#  [[3 5 7]
#  [2 4 6]
#  [1 8 9]] 

# Matrix 2:
#  [[1 0 2]
#  [4 5 6]
#  [7 8 9]]

# Matrix Addition:
#  [[ 4  5  9]
#  [ 6  9 12]
#  [ 8 16 18]]

# Matrix Subtraction:
#  [[ 2  5  5]
#  [-2 -1  0]
#  [-6  0  0]]

# Element-wise Matrix Multiplication:
#  [[ 3  0 14]
#  [ 8 20 36]
#  [ 7 64 81]]

# Matrix Multiplication (Dot Product):
#  [[ 72  81  99]
#  [ 60  68  82]
#  [ 96 112 131]]