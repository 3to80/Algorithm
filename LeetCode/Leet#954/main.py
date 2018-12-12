"""
Time complexity : O(nlgn)
Space complexity : O(maxRange Of Integer)
A.length는 최대 30000 
A[i] 는 -10만 ~ 10만

sortedA := A.sorted()
zeroAux := zero값을 가지는 것들의 개수, 항상 짝수개이어야 한다. 
posAux := size가 1000001 인 것 하나  // 1 ~ 1000001 
negAux := size가 1000001 인 것  하나 // 1 ~ 1000001

for val in sortedA:
    if val > 0:
        fill posAux
    else if val == 0:
        fill zeroAux
    else:
        fill negAux

if negAux %2 != 0: 
    return False
    
for val in sortedA:
    if val == 0:
        continue
    else:
        targetAux := (val > 0)?posAux:negAux        
        aval = abs(val)
        cnt_smaller := targetAux[aval]
        cnt_bigger := targetAux[aval* 2]
        if cnt_smaller > cnt_bigger:
            return false
        else
            targetAux[val*2] -= targetAux[val]
            targetAux[val] = 0
    
return true    

"""




class Solution:
    
    def check(self, arr, arrAux):
        for val in arr:
            s_cnt = arrAux[abs(val)]
            b_cnt = arrAux[abs(val)*2]
            if s_cnt > b_cnt:
                return False
            else:
                arrAux[abs(val)*2] -= arrAux[abs(val)]
                arrAux[abs(val)] = 0

        return True

    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        MAXVAL = 100001
        
        zeroAux = 0
        posAux = [0 for x in range(MAXVAL)]
        posA = []
        negAux = [0 for x in range(MAXVAL)]
        negA = []
        for val in A:
            if val == 0:
                zeroAux+=1
            else:
                # 'true' if False else 'false'
                targetAux = posAux if val > 0 else negAux
                targetA = posA if val > 0  else negA
                aval = abs(val)
                targetAux[aval] += 1
                targetA.append(val)
        
        if zeroAux %2 != 0:
            return False        

        posA.sort()
        negA.sort(reverse=True)
        
        return self.check(posA, posAux) and self.check(negA, negAux)
        
        
