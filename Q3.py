import sys
 
# Function to check if a cell (i, j) is valid or not
def isValid(mat, i, j):
    return 0 <= i < len(mat) and 0 <= j < len(mat)
 
# Find the longest path starting from cell (i, j) formed by adjacent
# numbers in a matrix
def findLongestPath(mat, i, j, lookup):
 
    # if the cell is invalid
    if not isValid(mat, i, j):
        return None
 
    # construct a unique dictionary key from dynamic elements of the input
    key = (i, j)
 
    # if the subproblem is seen for the first time, solve it and
    # store its result in a dictionary
    if key not in lookup:
 
        # string to store path starting (i, j)
        path = None
 
        # recur top cell if its value is +1 of value at (i, j)
        if i > 0 and mat[i - 1][j] - mat[i][j] == 1:
            path = findLongestPath(mat, i - 1, j, lookup)
 
        # recur right cell if its value is +1 of value at (i, j)
        if j + 1 < len(mat) and mat[i][j + 1] - mat[i][j] == 1:
            path = findLongestPath(mat, i, j + 1, lookup)
 
        # recur bottom cell if its value is +1 of value at (i, j)
        if i + 1 < len(mat) and mat[i + 1][j] - mat[i][j] == 1:
            path = findLongestPath(mat, i + 1, j, lookup)
 
        # recur left cell if its value is +1 of value at (i, j)
        if j > 0 and mat[i][j - 1] - mat[i][j] == 1:
            path = findLongestPath(mat, i, j - 1, lookup)
 
        # note that as the matrix contains all distinct elements,
        # there is only one path possible from the current cell
 
        lookup[key] = f'{mat[i][j]}, {path}' if path else str(mat[i][j])
 
    # return path starting from (i, j)
    return lookup[key]
 
 
def longestPath(mat):
 
    res_size = -sys.maxsize        # stores number of elements in `result`
 
    # create a dictionary to store solutions to subproblems
    lookup = {}
 
    # from each cell (i, j), find the longest path starting from it
    for i in range(len(mat)):
        for j in range(len(mat)):
            # store current path (`path` would be like `1, 2, 3, 4, 5, 6, 7`)
            path = findLongestPath(mat, i, j, lookup)
 
            # find the number of elements involved in the current path
            size = path.count(',')
 
            # update result if a longer path is found
            if size > res_size:
                result = path            # update the longest path found so far
                res_size = size
 
    # print the path
    return result
 
 
if __name__ == '__main__':
 
    mat = [
            [10, 13, 14, 21, 23],
            [11, 9, 22, 2, 3],
            [12, 8, 1, 5, 4],
            [15, 24, 7, 6, 20],
            [16, 17, 18, 19, 25]
        ]
 
    # find and print the longest path
    print(longestPath(mat))
