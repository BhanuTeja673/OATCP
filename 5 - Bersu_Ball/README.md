Dynamic Programming Function:

    Implement a recursive dynamic programming function countCompatiblePairs that computes the maximum number of compatible pairs starting from given indices of boys and girls.
    The function takes indices of the current boy and girl, vectors of boys' and girls' preferences, sizes of the boys and girls vectors, and a 2D dynamic programming table (dp) as arguments.
    Base cases:
        If either the current boy index (boyIndex) or the current girl index (girlIndex) exceeds the respective counts, return 0 (indicating no compatible pairs).
        If the value in the dynamic programming table at the current indices is not -1 (indicating it has been previously calculated), return the stored value.
    Recursive cases:
        Check if the current pair of boy and girl is compatible (based on the given conditions).
        If compatible, recursively call the function with incremented indices for both boy and girl, and increment the count by 1.
        Otherwise, recursively call the function by moving either to the next boy or the next girl, whichever gives the maximum count of compatible pairs.
    Store and return the maximum count of compatible pairs for the current indices in the dynamic programming table.s
