# Input:
# A: [1,2,3,2,1]
# B: [3,2,1,4,7]
# Output: 3
# Explanation:
# The repeated subarray with maximum length is [3, 2, 1].
# 1 <= len(A), len(B) <= 1000
# 0 <= A[i], B[i] < 100



#Brute force 1
# A에서 만들 수 있는 모든 숫자열에 대해, B에 들어가는 것중에 가장 큰 것을 고르기
# len(A) : N, len(B) : M
# A에서 만들 수있는 모든 문자열 : O(nC2) = O(n^2)
# A의 특정 subarray가 B에 들어가는지 test하기 : B의 문자 개수 당 A의 모든 문자열 개수 -> b의 문자는 m개 , a의 문자열은 최대 N개 O(M * n)
# Time compelexity : O(N^3 * M), SPACE : O(1)

# Optimizing sol #1
# Anaylsis
#   1. A 에서 만들 수 있는 모든 문자열을 비교해야되나 ?
#   2. B의 모든 위치의 문자열에 대해 비교를 해야 하나?
#
#  > A의 subarray가 B에 포함되는지 비교 -> O(N) 더이상 줄일 없음
#  > O(nC2) : 길이가 가장 긴거 부터 들어가서 찾으면, 정답 후보인 길이보다 작은 문자열은 검사 안해도 되기 때문에 pruning 가능
#  > O(M): 발견 된 길이만큼 은 줄 수 있음. O(M-K) , 1<= K <= N
#  > Space를 활용해서 줄일 수 있을지 생각 : 생각이 안남


# Optimizing sol #2
# A와 B의 부분합이 같은 부분열을 찾고, 부분열 안의 내용이 완전히 똑같은지 비교한다.
# A(i, j) , B(i, j)
# 각 부분합을 구할 수 있는 방법 : 부분 합 배열을 각각 만들기 . TIME : O(N), O(M) SPACE : O(N), O(M)
# 부분합이 같은 지점을 찾기 : 특정 i, j에 대해 부분합 구하는 거 : O(1)
# key는 부분합, value는 {i, j}인 hashTable을 하나 만든다.
# A의 모든 부분합을 다 저장, B의 모든 부분합을 다 저장 O(M+N)보다는 항상 작다. 최대 값은 1000*99 + 1  . Time : O(N^2) O(M^2)
# 이 때 collision이 발생하는 부분에 대해 서만 비교를 한다. (따로 저장을 한다.) O(N)
# SOL#1을 opt 시킨거랑 큰차이가 있을 거 같진 않음


#
# A에서 만들 수 있는 모든 숫자열에 대해, B에 들어가는 것중에 가장 큰 것을 고르기
# len(A) : N, len(B) : M
# A에서 만들 수있는 모든 문자열 : O(nC2) = O(n^2)
# A의 특정 subarray가 B에 들어가는지 test하기 : B의 문자 개수 당 A의 모든 문자열 개수 -> b의 문자는 m개 , a의 문자열은 최대 N개 O(M * n)
# Time compelexity : O(N^3 * M), SPACE : O(1)

# Optimizing sol #1
# Anaylsis
#   1. A 에서 만들 수 있는 모든 문자열을 비교해야되나 ?
#   2. B의 모든 위치의 문자열에 대해 비교를 해야 하나?
#
#  > A의 subarray가 B에 포함되는지 비교 -> O(N) 더이상 줄일 없음
#  > O(nC2) : 길이가 가장 긴거 부터 들어가서 찾으면, 정답 후보인 길이보다 작은 문자열은 검사 안해도 되기 때문에 pruning 가능
#  > O(M): 발견 된 길이만큼 은 줄 수 있음. O(M-K) , 1<= K <= N
#  > Space를 활용해서 줄일 수 있을지 생각 : 생각이 안남




class Solution:

    def compare(self, stringA, stringB):
        """

        :param stringA:
        :param stringB:
        :return: boolean
        """
        for i, j in stringA, stringB:
            if i != j:
                return False
        return True


    def check_subarray(self, source, target):
        """
        target이 source에 들어 있는지 확인
        :param source: read only,
        :param target: read only
        :return: boolean : 존재하면 true , 아니면 false
        """
        #init
        chk_start = source.index(target[0])

        while chk_start != -1 and chk_start < len(source)-len(target):
            #chk_start부터 (len)target만큼 비교를 다 해야 한다.
            chk = self.compare(source[chk_start:chk_start+len(target)], target)
            if chk:
                return True
            chk_start = source[chk_start:].index(target[0])

        return False

    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """

        if len(A) > len(B):
            longer, shorter = A, B
        else:
            longer, shorter = B, A

        max = -1
        for i in range(0, len(shorter)):
            for j in range(i+1, len(shorter)):
                subarray = shorter[i:j]
                #longer가 list 형임을 어떻게 ?
                ret = self.check_subarray(longer, subarray)
                if ret and max < len(subarray):
                    max = len(subarray)
        return max


if __name__ == '__main__':
    A = [1,2,3,2,1]
    B = [3,2,1,4,7]
    s = Solution()
    print(s.findLength(A, B))






A[i:j]

j< p

A[j:p]


B[k:l]

l < q

B[l:q]