class Solution(object):
    def checkBoard(self, rows):
        for i in range(len(rows)-1):
            first_row = rows[i]
            if first_row is None:
                continue
            first_col = i
            for rad in range(self.n):
                bad_row_0 = first_row + rad 
                bad_col_0 = first_col + rad
                bad_row_1 = first_row - rad
                bad_col_1 = first_col - rad
                bad_row_2 = first_row + rad
                bad_col_2 = first_col - rad
                bad_row_3 = first_row - rad
                bad_col_3 = first_col + rad 
                for j in range(i+1, len(rows)):
                    second_row = rows[j]
                    second_col = j
                    if bad_row_0 == second_row and bad_col_0 == second_col:
                        return False
                    elif bad_row_1 == second_row and bad_col_1 == second_col:
                        return False
                    elif bad_row_2 == second_row and bad_col_2 == second_col:
                        return False
                    elif bad_row_3 == second_row and bad_col_3 == second_col:
                        return False
        return True                    

    def placeQueen(self, q, rows, rowtable):
        sols = list()
        for row in range(self.n):
            if rowtable[row]:
                continue
            rows[q] = row
            rowtable[row] = True
            if self.checkBoard(rows):
                if q == (self.n - 1):
                    sols = sols + [rows[:]]
                else:
                    sols = sols + self.placeQueen(q + 1, rows[:], rowtable[:])
            rows[q] = None
            rowtable[row] = False    
        return sols

    def toString(self, soln):
        str_soln = ['']*self.n
        for i in range(len(soln)):
            str_soln[soln[i]] = '.'*i + 'Q' + '.'*(self.n-i-1)
        return str_soln

    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.n = n
        # which row each col is
        rows = [None]*self.n
        # if a row is occupied
        rowtable = [False]*self.n
        solutions = self.placeQueen(0, rows, rowtable)
        str_solutions = [self.toString(soln) for soln in solutions]
        return str_solutions


def main():
    str_solns = Solution().solveNQueens(4)


if __name__ == '__main__':
    main()
