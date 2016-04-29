class Solution(object):
    def subsetsWithDup(self, nums):
        def dfs(index, lst, ans):
            ans.append(lst + [nums[index]])
            print(index, lst + [nums[index]])
            if index == len(nums) - 1:
                return
            for i in range(index + 1, len(nums)):
                if i > index +1 and nums[i] == nums[i - 1]:
                    continue
                dfs(i, lst + [nums[index]], ans)

        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            dfs(i, [], ans)
        print(ans)
        ans.append([])
        return ans


solution = Solution()
solution.subsetsWithDup([1, 2, 2])
