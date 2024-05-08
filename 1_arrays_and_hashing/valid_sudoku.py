class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for x in range(9):
            curRow = []
            curCol = []

            for y in range(9):
                if (board[x][y] not in curRow and board[x][y] != "."):
                    curRow.append(board[x][y])
                elif (board[x][y] in curRow and board[x][y] != "."):
                    return False
                if (board[y][x] not in curCol and board[y][x] != "."):
                    curCol.append(board[y][x])
                elif (board[y][x] in curCol and board[y][x] != "."):
                    return False
        for i in range(0, 9, 3):
            for x in range(0, 9, 3):  # 0 3 6
                curMat = []
                for y in range(0, 3):  # 0 1 2
                    for z in range(0, 3):  # 0 1 2
                        if (board[y + i][z + x] not in curMat and board[y + i][z + x] != "."):
                            curMat.append(board[y + i][z + x])
                        elif (board[y + i][z + x] in curMat and board[y + i][z + x] != "."):
                            return False

        return True
