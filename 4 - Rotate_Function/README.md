Calculate Maximum Rotation:

    Initialize two variables sum and totalSum to 0.
    Iterate through the array and calculate the sum of elements (sum) and the sum of i * array[i] for each index i (totalSum). This is done to compute the total sum before any rotation.
    Set maxRotation to the initial total sum.
    Iterate from i = 1 to n - 1:
        Update totalSum for each rotation by subtracting size * array[size - i] from the previous total sum and adding the new elements introduced due to rotation.
        Update maxRotation to keep track of the maximum sum obtained after each rotation.
