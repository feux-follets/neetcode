class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        newSet = set(nums)
        return (len(newSet) != len(nums))
