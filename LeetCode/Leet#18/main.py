"""
개선 필요
1) 두 value값 병합할 때 중복 체크, time complexity 분석

"""
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        """
        solution 2
        
        1. 정렬 
        1) sum(nums[i], nums[j])를 key, [i,j]를 value로 하는 dict를 만든다. 
        2) dict를 iterating 하며, key k의 value들에 대해 target-k의 value들과 합쳐 답을 생성한다. 
        Time : O(N * n) + O( N * (v1, v2를 병합하는 비용)), 최대 병합 비용은 N/2 * n/2이다. amoritzed로 분석 다시 하기
        Space : dict의 space . O(N*n)
        """
        ret = []
        # nums.sort()
        # make sumtable 
        
        dictAux = {}        
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                v = nums[i]+nums[j]
                # key가 sum(i, j)이고 value가 (i, j)인 dict를 만든다. 
                if dictAux.get(v): dictAux[v].append([i,j])
                else: dictAux.setdefault(v, [[i,j]])
        
        def same(li1, li2):
            for i in range(len(li1)):
                if li1[i] != li2[i]:
                    return False
            return True
        
        # 이전에 고른 [i, j] 와 [k, l]에 대해 서로 중복되는게 있으면 안된다.  
        for k, v in dictAux.items():
            if k <= (int)(target/2):
                counter = dictAux.get(target-k)
                if not counter:continue
                else:
                    for itm in v:
                        for c in counter:
                            if itm[0] in c or itm[1] in c: continue
                            else:
                                flag = True
                                tmp = sorted([nums[i] for i in (itm+c)])
                                for r in ret:
                                    if same(r, tmp):
                                        flag = False
                                        break
                                if flag: ret.append(tmp)

        return ret
        
        
        
        


