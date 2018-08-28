####Problem
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1

#####Note

- - -
####Solution

1. brute

        # maxEnd <- findMax(intervals)
        # timeTable <- [0 : maxEnd]
        # for i in intervals, check time section [s: e] at timeTable
        # counting the most time val in timeTale
        # O(interval slit sum)
2. opt

        # max_room, curr_room <- 0, 0
        # init Counter(hashMap) using intervals
        # min_start, max_end  <- min start v, max end v
        # s_set, e_set = Counter(s_ord), Counter(e_ord)


        #for curr_time in range(min_start, max_end):
        #    if curr_time in e_set:
        #        curr_room -= e_set[curr_time]
        #    if curr_time in s_set:
        #        curr_room += s_set[curr_time]
        #        max_room = max(curr_room, max_room)
        
- - - 
####Analysis
Time complexity

Brute
1) O(sum of intervals)
2) O(max(end) - min(start)) 
    - curr_time으로 비교하는건, 매시간마다 빈방이 있는지를 계속 보는거.. 매우 비효율적
    - 미팅룸의 예약 시간만 보면 되는거잖아. 
Space complexity
- - -
####Discussion

    s = [[7, 30], [5, 10], [15, 20]]
    s.sort()
    이거 , 뒤에 값으로 정렬은 어떤식으로 하지? 


<pre><code>

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e
    
    intervals.sort(key=lambda x:x.start)

</code></pre>


Python
- 기본으로 list, tuple, set, dict 4개를 관리
- list, tule은 순서를 관리. set과 dict는 ㄴㄴ
- list는 mutable, tuple은 immutable이다. immutable은 즉, assignment 가 안된다는.
    - 예를 들어 a = (1) , a[0] = 3 이러면 에러 
    - a.append(2) 이런 append도 에러 , tuple은 수정 불가능이기 떄문 
    - namedtuple은 c의 구조체와 유사하다고 볼수있다. 구조체도 한번 만들고 거기에 새로운 속성을 넣는다는가 그런게 append 식으로 되지 않으니 
    <pre><code>
    from collections import namedtuple
    Station = namedtuple("Station", "id, city, state, lat, long")
    denver = Station(44, "Denver", "CO", 40, 105)
    </code></pre>
    - 튜플은 네임드튜플에서 이름이 없는 것이라고 할 수 있다.
    - 불변 값만 해시를 만들 수 있기 때문에 키에 불변 값만 사용 가능하다. tuple은 그래서 hash로 만들 수 있고 list는 안된다. list를 쓸 꺼면 tuple로 변경 해줘야됨 
Counter에 push 하는 법 

<pre><code>

a = Counter()
a.update(1)  # 이렇게 사용할 수 없음
a.update[1] # 이렇게 iterable 형태로 사용 


###output ### 
Counter({'a': 3, 'b': 1, 'c': 1})
a.update("c")
a
Counter({'a': 3, 'c': 2, 'b': 1})
a.update([1])
a
Counter({'a': 3, 'c': 2, 'b': 1, 1: 1})

>>> c = Counter(a=3, b=1)
>>> d = Counter(a=1, b=2)
>>> c + d                       # add two counters together:  c[x] + d[x]
Counter({'a': 4, 'b': 3})
>>> c - d                       # subtract (keeping only positive counts)
Counter({'a': 2})
>>> c & d                       # intersection:  min(c[x], d[x])
Counter({'a': 1, 'b': 1})
>>> c | d                       # union:  max(c[x], d[x])
Counter({'a': 3, 'b': 2})
</code></pre>

#####DefaultDict()

Collection 에서 defaultdict() 모듈을 사용하는법입니다.

defaultdict()는 말그대로 dictionary 에 기본값을 정의하고 키값이 없더라도 에러를 출력하지않고 기본값을 출력합니다.

일반 diconary는 존재하지 않는 키값을 입력하면 에러를 호출합니다.

<pre><code>

from collections import defaultdict

d = defaultdict(object)
d['one'] # 이전 dict는 에러가 나지만 에러가 안난다. 단순 키만 생성하는거 
d = defaultdict(lambda : 0) 
d['two'] # two라는 키는 없으니 two라는 키를 만들고, 그 default값으로 0을 넣는다. labda를 이용한 초기값 설
output : 0

</code></pre>
#####NamedTUple
- - -
####Reference


https://www.haruair.com/blog/3725

https://www.slideshare.net/dahlmoon/collections-20160313