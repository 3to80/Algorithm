####Problem

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#####Note

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)  
Output: 7 -> 0 -> 8  
Explanation: 342 + 465 = 807.  

- - -
####Solution
 
두 list를 돌며 carry랑 같이 다 더한다.  
마지막에 carry가 남아 있으면 carry를 또 append 해준다. 

- - - 
####Analysis
Time complexity
 - O(max(li, l2)) : 비록 l2가 None이라 해도 결국에 copy 때문에 다 봐야 한다.  추가 cost 하면 a, b를 만드는 조건연산
 - 깔끔한 코드를 윟 이렇게 
Space complexity
 - O(max(li, l2)) : 정답을 listNode로 return 해야 되기 때문 
- - -
####Discussion

<pre><code>
    # l1에 l2 for 중복 
    for a, b in [(x,y) for x in l1 for y in l2]:
        print(a, b)
    
    # l1, l2 중 더 짧은거에 맞춰 리스트 출력
    for a, b in zip(l1, l2):
        print(a, b)
        
    # l1, l2 중 더 긴 것에 맞춰 리스트 출력, 짧은 쪽은 None이 출력    
    for a, b in zip_longest(l1, l2):
        print(a, b)

    # 이거 더 간단하게 쓸 수 있는 방법
    if not a:
        a = 0
    # python의 3항 연산자는 and, or로 구현 가능 
    a = a and a or 0
    # if else로도 가능
    b = b if b else 0
    
    # iterable 구현 되어 있으면 
    
    ret, carry = [], 0
    for a, b in zip_longest(l1, l2):
        a, b = a and a or 0, b if b else 0
        ret.append((a + b + carry)%10)
        carry = (int)((a + b + carry) / 10)
    return ret
</code></pre>





- - -
####Reference