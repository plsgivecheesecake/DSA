class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        
        n = len(s)
        cycle = 2 * (numRows - 1)
        result = []
        
        for row in range(numRows):
            for j in range(row, n, cycle):
                result.append(s[j])
                diag = j + cycle - 2 * row
                if row != 0 and row != numRows - 1 and diag < n:
                    result.append(s[diag])
                    
        return "".join(result)