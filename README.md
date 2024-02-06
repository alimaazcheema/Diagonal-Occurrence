Diagonal-Occurrence
C++ code for the most optimised algorithm to the find the diagonal occurences in nxn matrix.

Suppose you are given a text T of length n x n and a pattern P of length m x m; the T is given in 2D format. Find the “diagonal occurrence” of the pattern in the given text.

The trick in this scenario involves traversing through the grid in a diagonal manner to extract the symbols. Instead of going row by row or column by column, you start from the top-left corner and move diagonally, retrieving each symbol one by one.

Specifications:

The pattern can vary in dimensions, such as 1 x 1, 2 x 2, 3 x 3, and so on, up to n x n.

There must be a minimum of two blocks (occurrences) of the pattern in the diagonal positions. More than two blocks are also permissible. Otherwise, the diagonal pattern is considered non-existent.

The diagonal position starts immediately after the last occurrence of the pattern in the previous row.

The diagonal pattern might overlap some columns of the upper pattern, excluding the first column. Refer to the table for a visual demonstration.

Task: You are required to provide a C++ implementation of an algorithm that adheres to the above-mentioned conditions. Additionally, analyze the time complexity of your algorithm. The efficiency of the algorithm will be compared with the best-known solution. Ensure your logic uses no more than a constant amount of extra space. It is advisable to generate all possible combinations before attempting implementation.
