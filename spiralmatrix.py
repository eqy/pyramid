class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        visited = set()
        i = 0
        j = 0
        rows = len(matrix)
        if not rows:
            return []
        if rows == 1:
            return matrix[0]
        cols = len(matrix[0])
        if not cols:
            return []
        if cols == 1:
            return [row[0] for row in matrix]
        output = []
        state = 0 # right
        while (i*cols + j) not in visited:
            output.append(matrix[i][j])
            visited.add(i*cols + j)
            if state == 0:
                j = j + 1
                if j >= cols or (i*cols + j) in visited:
                    i = i + 1
                    j = j - 1;
                    state = 1 # down
            elif state == 1:
                i = i + 1
                if i >= rows or (i*cols + j) in visited:
                    j = j - 1
                    i = i - 1
                    state = 2 # left
            elif state == 2:
                j = j - 1
                if j < 0 or (i*cols + j) in visited:
                    i = i - 1
                    j = j + 1
                    state = 3 # up
            else:
                i = i - 1
                if i < 0 or (i*cols + j) in visited:
                    j = j + 1
                    i = i + 1
                    state = 0 # right
        return output     
