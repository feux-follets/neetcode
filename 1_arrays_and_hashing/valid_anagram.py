class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        if len(set(s)) != len(set(t)):
            return False
        else:
            for char in set(s):
                if (s.count(char) != t.count(char)):
                    return False
            return True
