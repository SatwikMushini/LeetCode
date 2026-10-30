class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(words) != len(pattern):
            return False
            
        mapi = {}
        mapi2 = {}

        for i, c in enumerate(pattern):
            if c in mapi and mapi[c] != words[i]:
                    return False
            elif words[i] in mapi2 and mapi2[words[i]] != c:
                return False
            mapi[c] = words[i]
            mapi2[words[i]] = c


        return True

