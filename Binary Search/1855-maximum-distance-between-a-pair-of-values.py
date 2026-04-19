class Solution:
    def find_lower_bound(self, target: int, arr: List[int]) -> int:
        # We have to be careful here because the array is reversed
        L, R = len(arr) - 1, 0

        while R <= L:
            mid = (L + R) // 2

            if arr[mid] >= target:
                R = mid + 1
            else:
                L = mid - 1

        return L

    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        max_distance = 0
        for index, num in enumerate(nums1):
            lower_bound = self.find_lower_bound(num, nums2)
            # print(f"Lower bound of {num} in nums2 is {lower_bound}")
            max_distance = max(max_distance, lower_bound - index)

        return max_distance