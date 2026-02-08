class Solution:
    def calc(self, nums, index):
        if(index>len(nums)):
            return 0
        total=0
        for i in range(index, len(nums)):
            total+=nums[i]
        count=len(nums)-index
        return total/count
    def dominantIndices(self, nums: List[int]) -> int:
        count=0
        n=len(nums)
        for i in range(n-1):
            if(nums[i]>self.calc(nums, i+1)):
                count+=1
        return count
