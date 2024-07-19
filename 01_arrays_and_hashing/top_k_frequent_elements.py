class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        result = []

        newNums = [str(x) for x in nums]
        listOfNum = set(newNums)
        numDict = dict.fromkeys(listOfNum, 0)

        for num in listOfNum:
            numDict[num] = newNums.count(num)

        newNumDict = sorted(numDict.items(), key=lambda x: x[1], reverse=True)

        topKKeys = [int(x[0]) for x in newNumDict][:k]
        result = topKKeys

        print(numDict)
        return result
