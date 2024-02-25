class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # 檢查行
        for row in board:
            if not self.is_valid(row):
                return False
        
        # 檢查列
        for col in range(9):
            column = [board[row][col] for row in range(9)]
            if not self.is_valid(column):
                return False
        
        # 檢查 3x3 
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                square = [board[x][y] for x in range(i, i + 3) for y in range(j, j + 3)]
                if not self.is_valid(square):
                    return False
        
        return True
    
    def is_valid(self, nums: List[str]) -> bool:
        seen = set()
        for num in nums:
            if num != '.':
                if num in seen:
                    return False
                seen.add(num)
        return True      