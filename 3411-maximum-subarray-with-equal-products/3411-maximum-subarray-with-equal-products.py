class Solution:
    def maxLength(self, nums: List[int]) -> int:
        maxLen = 0
        n = len(nums)
        for i in range(n, 1, -1): 
            for j in range (n - i + 1):
                sub = nums[j: j + i]
                p = 1
                for val in sub: p *= val

                div = gcd(*sub)
                mul = lcm(*sub)
                if p == div*mul:
                    maxLen = max(maxLen, i)
        return maxLen