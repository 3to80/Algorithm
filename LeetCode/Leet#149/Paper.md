####Problem

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4

#####Note

- - -
####Solution

1) 중복된 점들에 대해 compress를 해 nodup map을 만든다. 
 : {(1,2), 3} : (1,2)가 3개 있는 것을 뜻함

2) 
- 점이 2개 선택 되었을 떄, 직선은 slope, bias로 나타낼 수 있다.
- nodup에서 (p,q) (r,s) 2개의 점에 대해, 기울기 공식을 이용해 {(a, b, c, d), (총합, 종류수)} 로 하는 line map을 만든다.
- a : (s-q)/gcd(s-q, p-r) 
- b : (r-p)/gcd(s-q, p-r)
- c : (q * r - p * s) / gcd((q * r - p * s), r - p)) 
- d : (r - p) / gcd((q * r - p * s), r - p)

- a, b, c, d는 slope의 num, denum, bias의 num, denum 를 의미한다. 
    * 소수로 표현하면 정확도에서 문제가 생길 수도 있을 꺼 같아 표현
    * 주의 해야할 건, 부호가 (-, - , - , -) 이 (+, +, + ,+ ) 랑 같다는거 . 부호 처리에 신경을 써야한다. 

3)
- 2번의 방식대로면, 만약 하나의 직선에 p1, p2, p3가 있다고 하자. 그럼 (p1 + p2 + p3) * 3이 line map에서 개수와 같게 된다. 그래서 총 몇 번 더해지는지도 같이 저장한다.
- 마지막에 총합에서 종류수에 대한 이차 방정식을 풀면 (a,b,c,d)에 해당하는 직선에 몇개의 점이 있는지를 알 수 있다. 

4) line map에서 최대인 직선을 찾아 return 한다.

- - - 
####Analysis
Time complexity

- nodup table 생성 : python 내부 hash가 O(1)이라 가정하면 , O(n)
- line table 생성 : n에서 중복된 값을 뺏을 때 값을 nodup(n)이라 하자. python 내부 hash가 O(1)이라 가정하면, O(nodup(n) * nodup(n)) // O(n**2)까지 
- line table 의 각 요소 {(a, b, c, d), (총합, 종류수)} 에서 몇 개인지 유추하는건 O(1).

Therefore,  O(nodup(n) * nodup(n))

Space complexity

- nodup table 만드는데  O(n)
- line table 만드는데  O(nodup(n) * nodup(n))

Therefore,  O(nodup(n) * nodup(n))
- - -
####Discussion

한줄에 for 두번 하는거 : 아래 꺼 같은 방법이 있음

        # import itertools
        #
        # for elem1, elem2 in itertools.combinations(a, 2):
        #     do_whatever_with(elem1, elem2)

        
Python에서 n차원 배열 만들기

        # python에서 n차 배열 만드는 방법
        # matrix = [[0] * 10 for x in range(10)] , 그냥 []로 계속 만들어주면 된다 
        # import numpy as np                                              
        # matrix = np.zeros((10, 10)) 

Python에서 HashMap

- An object is hashable if it has a hash value which never changes during its lifetime (it needs a __hash__() method), and can be compared to other objects (it needs an __eq__() or __cmp__() method). Hashable objects which compare equal must have the same hash value.
Hashability makes an object usable as a dictionary key and a set member, because these data structures use the hash value internally.
All of Python’s immutable built-in objects are hashable, while no mutable containers (such as lists or dictionaries) are. Objects which are instances of user-defined classes are hashable by default; they all compare unequal, and their hash value is their id().

- hash 는 논리적 동일성, 
<pre><code>
    a = (1,2,3)
    b = (1,2,3)
    # a.__hash__() 랑 b.__hash__()는 같은 값 
    # 하지만 id(a) 랑 id(b)는 다른 값 
</code></pre>


Python에는 Java HashMap 같은게 없을까? put, get이 dict에 내장되어 있음, tuple과 dict를 이용하면 된다. 이 때 tuple은 assignment가 안되서 조금 번거롭다.  
        
        a = {}
        a[(1,3)] = 4
        a[(1,5)] = 3
        a.get((1,3))
        #result : 4
      
그 외에도 , python의 collection에서 Counter object 생각해볼 수 있음 이문제에서.

- - -


####Reference

https://docs.python.org/2/library/collections.html
https://stackoverflow.com/questions/14535730/what-do-you-mean-by-hashable-in-python
https://docs.python.org/2/library/collections.html