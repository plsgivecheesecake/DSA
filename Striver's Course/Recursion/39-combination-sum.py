class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        
        def dfs(index: int, buffer: List[int], target: int) -> None:
            if index >= len(candidates) or target < 0:
                return
            if target == 0:
                # Understand why it's important to use list(buffer)
                # or buffer[:], and appending buffer as-is won't work
                result.append(list(buffer))
                return
            # Pick element and dfs from same index
            buffer.append(candidates[index])
            dfs(index, buffer, target - candidates[index])
            # Don't pick element and dfs from next index
            buffer.pop()
            dfs(index + 1, buffer, target)

        dfs(0, [], target)
        return result
