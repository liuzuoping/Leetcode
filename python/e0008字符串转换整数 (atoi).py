import re
class Solution:
    def myAtoi(self,s:str)->int:
        if(not s or s==''or s.strip()==''):return 0
        s=s.strip()
        pattern=re.compile(u'^[-,+]?\d+')
        ret=pattern.findall(s)
        if (len(ret)==0): return 0
        if (len(ret)==1):
            if (int(ret[0])<-2**31):
                return -2**31
            if (int(ret[0])>2**31-1):
                return 2**31-1;
            return int(ret[0])
