from collections import defaultdict
class Solution:
    def binary_search(self, target: int, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return -1 # Unlikely path, since we know that the element exists

    def distance(self, nums: List[int]) -> List[int]:
        indices = defaultdict(list)
        prefix = defaultdict(list)

        for index, num in enumerate(nums):
            indices[num].append(index)
            prefix_sum = prefix[num][-1] if prefix[num] else 0
            prefix[num].append(index + prefix_sum)

        result = []
        for index, num in enumerate(nums):
            if len(indices[num]) == 1:
                result.append(0)
            else:
                # Find the position of the index in the indices list
                # Then do prefix sum math
                pos = self.binary_search(index, indices[num])
                left_sum = 0
                right_sum = 0
                if pos > 0: # Because if pos == 0, no need to calculate left_sum
                    left_sum += (pos * index) - prefix[num][pos - 1]
                if pos < len(indices[num]) - 1: # Because if pos is at the right end, no need to compute the right_sum
                    right_sum = (prefix[num][-1] - prefix[num][pos]) - ((len(indices[num]) - pos - 1) * index)
                result.append(left_sum + right_sum) 
        return result