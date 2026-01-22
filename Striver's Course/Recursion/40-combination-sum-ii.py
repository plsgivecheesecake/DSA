class Solution:
    def dfs(self, index: int, target: int, candidates: List[int], buffer: List[int], result: List[List[int]]) -> None:
        # Base cases: index > candidates length, 
        # target is negative, or target is zero
        if index >= len(candidates):
            if target == 0:
                result.append(list(buffer))
            return
        if target < 0:
            return
        if target == 0:
            result.append(list(buffer))
            return
        buffer.append(candidates[index])
        self.dfs(index + 1, target - candidates[index], candidates, buffer, result)
        buffer.pop()
        index += 1
        while index < len(candidates) and candidates[index] == candidates[index - 1]: index += 1
        self.dfs(index, target, candidates, buffer, result)
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        candidates = sorted(candidates)
        self.dfs(0, target, candidates, [], result)
        return result