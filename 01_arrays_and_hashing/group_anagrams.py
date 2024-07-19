class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        result = {}

        for word in strs:
            currentSortedWord = ''.join(sorted(word))
            if (currentSortedWord in result):
                result[currentSortedWord].append(word)
            else:
                result[currentSortedWord] = [word]

        return list(result.values())
