import random as rnd
import math
import copy


# 문제 : 정렬된 정수 리스트와 어떤 값 A가 주어졌다. 리스트의 값들을 골라서 더해 A를 만들 수 있으면 True, 만들 수 없으면 False를 나타내는 함수를 구현해라

# brute force 1
# n개의 리스트에서 1개, 2개, 3개 ... 총 n개 를 골랐을 때 나오는 합의 값들을 모두 저장
# A와 비교한다.
# Space : O(n * max(list)) Time : O(2**n)

# brute force 2
# 제일 큰 값 부터, 조회를 시작.



def binarySearch(li, start, end, target):
    """

    :param li: read only
    :param start: start index in step
    :param end: end index in step
    :param target: read only
    :return: int
    """
    if end - start < 1:  # 더이상 영역이 없음
        return -1
    mid = start + (int)((end- start) / 2)
    if li[mid] == target:
        return mid
    elif li[mid] < target:
        return binarySearch(li, mid + 1, end, target)
    else:
        return binarySearch(li, start, mid - 1, target)

def binarySearch_nearest(li, start, end, target):
    """
    # 이하인 수중 가장 큰 곳의 index를 반환 한다.

    :param li: read only
    :param start: start index in step
    :param end: end index in step
    :param target: read only
    :return: int
    """
    if target > li[-1]:
        return len(li)-1
    if end - start < 1:  # 더이상 영역이 없음
        return -1
    mid = start + (int)((end- start) / 2)
    if li[mid] == target:
        return mid
    elif li[mid] < target:
        if mid+1 < len(li) and li[mid+1] > target:
            return mid
        return binarySearch_nearest(li, mid + 1, end, target)
    else:
        if mid - 1 >= 0 and li[mid - 1] <= target:
            return mid - 1
        return binarySearch_nearest(li, start, mid - 1, target)



class Solution:




    def find_EndIdx(self, li, target):
        #li에서 선택할 수 있는 가장 큰 idx보다 하나 큰 것을 반환한다. 밖에서는 [start, end) 로 쓰기 때문
        if li[0] > target: # 전부 다 큰 경우 -1을 return 한다
            return -9999
        if li[-1] < target: # 전부 다 작 다면 제일 마지막 indx를 return 한다.
            return len(li) -1
        t= binarySearch_nearest(li, 0, len(li), target)
        if target == li[t]:
            return -7777
        else:
            return t




    def check(self, li , target, num):
        #리스트 A에서 num만큼 선택해 더한 값이 target과 같을 수 있으면 true, 아니면 false
        """
        list에ㅓ num만큼 골라 target을 만들 수 있는지 check 하는 함수
        :param li: list unsigned int
        :param target: unsigned int
        :param num: unsigned int
        :return: boolean // 만들수 있으면True, 아니면 False
        """

        # [:endIdx]
        #init
        Queue = []
        endIdx = self.find_EndIdx(li, target)
        Queue.append({"target": target, "endIdx": endIdx, "num": num})

        #iteration
        while Queue:
            # 계속 확인을 해봐야 되는 상황: target > 0  and endIdx > 0 and num > 0
            # True 리턴해야 되는 상황 : target == 0, num == 0, endIdx >0
            #{li, endidx, target, num} -> {li, endidx-1, target, num} {li, updated_endidx, target- li[endidx-1], num-1}
            current = Queue.pop()
            if current["target"] == 0 and current["endIdx"] == -7777 and current["num"] ==0:
                print("check")
                return True
            if current["target"] > 0 and current["endIdx"] >= 0 and current["num"] > 0:
                #1 넣을 있는 제일 큰 것을 안 넣을 때
                Queue.append({"target": current["target"], "endIdx": current["endIdx"]-1, "num": current["num"]})
                #2 넣을 수 있는 제일 큰 것을 넣을 떄
                update_target = current["target"]- li[current["endIdx"]]
                update_endIdx = self.find_EndIdx(li, update_target)
                if update_target == 0 and current["num"] == 1:
                    pass
                else:
                    Queue.append({"target": update_target, "endIdx": update_endIdx , "num": current["num"]-1})

        return False




    def splitArraySameAverage(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        # S = S_B + S_C
        # N = N_B + N_C
        list.sort(A)

        S = sum(A)
        N = len(A)
        for numB in range(1, (int)(N/2)+1):
            if (S*numB) % N == 0:
                #리스트에서 numB만큼 골라 target을 만들 수 있으면 평균이 같다.
                target = S*numB/N
                ret =  self.check(A, target, numB)
                if ret == True:
                    a, b = target, numB
                    print(a)
                    print(b)
                    return True

        return False

if __name__ == '__main__':
    # solve()
    arr = [2,12,18,16,19,3]

    s = Solution()
    print(s.splitArraySameAverage(arr))











