class Solution:
    def wordPattern(self, p: str, s: str) -> bool:
        words=s.split()
        wtop=dict()
        if(len(p))!=len(words):
            return False
        if(len(set(p))) !=len(set(words)):
            return False
        for i in range(len(words)):
            if(words[i]) not in wtop:
                wtop[words[i]]=p[i]
            elif wtop[words[i]] !=p[i]:
                return False
        return True