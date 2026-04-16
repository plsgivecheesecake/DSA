from collections import defaultdict
class Solution:
    def get_lower_bound(self, query: int, nums: List[int]) -> int:
        L, R = 0, len(nums) - 1
        while L <= R:
            mid = (L + R) // 2
            if nums[mid] >= query:
                R = mid - 1
            else:
                L = mid + 1
        return L

    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        index_map = defaultdict(list)
        for index, num in enumerate(nums):
            index_map[num].append(index)
        result = []
        for query in queries:
            key = nums[query]
            if len(index_map[key]) == 1:
                result.append(-1)
            else:
                lower_bound = self.get_lower_bound(query, index_map[key])
                prev_index = lower_bound - 1
                next_index = (lower_bound + 1) % len(index_map[key])

                l1 = index_map[key][prev_index]
                r1 = index_map[key][lower_bound]
                l2 = index_map[key][lower_bound]
                r2 = index_map[key][next_index]

                if l1 > r1:
                    r1 += len(nums)

                if l2 > r2:
                    r2 += len(nums)

                result.append(min(r1 - l1, r2 - l2))

        return result