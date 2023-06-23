class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        DictList = []
        MaxValue = 1
        CurrentMax = 1



        length = len(nums)

        for i in range(length):
            CurElement = nums[i]
            DictList.append({})
            for j in range(i):
                difference = CurElement - nums[j]
                DictList[i][difference] = 1

                if(difference in DictList[j].keys()):
                    DictList[i][difference] += DictList[j][difference]
    
                MaxValue = max(MaxValue, DictList[i][difference])

        