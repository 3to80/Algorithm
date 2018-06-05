####Problem

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

#####Note
 The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 You could assume no leading zero bit in the integer’s binary representation.


#####Example

5  : 101 -> 010, 2  
1 : 1  -> 0, 0

- - -
####Solution

XOR(^)의 성질

1) A ^ 0 = A  
2) A ^ A = 0
3) A ^ B = B ^ A
4) (A ^ B) ^ C = A ^ (B ^ C)

**참고**   
교환 법칙이 성립하는 군을 아벨 군(Abelian group) 이라 한다.  
아벨군의 정의는, 교환법칙, 결합법칙, 항등원의 존재, 각 원소에 대한 유일한 역원의 존재 이 4가지

A, B, C 가 될 수 있는 모든 경우를 생각해 증명할 수 있다.
- (0, 0, 0) ~ (1, 1, 1)을 (A, B, C)에 대입

위 성질을 이용하면,   

A ^ 11111...1`2`  = complement(A)
 
A가 2진법으로 했을 때 몇 자리 수인지 확인 (log2, truncate)
2진법인 그 수를 구함 : 이하, helepr 
A와 helepr를 xor 한다
- - -
####Analysis
Time complexity 
 - 1111...1`2` 만드는데 O(logN)
 - helper 값 구하는데 O(log(logN))
 - helepr와 xor 하는데 O(logN)  
 
 => O(logN)
 
Space complexity
 - O(1) 
- - -
####Discussion

<pre><code>
void swap(int *x, int *y)
{
 // if (*x != *y) *x ^= *y ^= *x ^= *y; 이랑 동일 
    if (x != y) {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}


</code></pre>

A랑 B를 swap 하는 걸 xor의 성질을 이용해 구현할 수 있음. (추가 메모리 필요 x )

A메모리 <= A ^ B  
B메모리 <= B ^ (A ^ B) = A ^ B ^ B = A ^ 0 = A
A메모리 <= (A ^ B) ^ A = B ^ A ^ A = B ^ 0 = B

실제 상황에서 xor 교체 알고리즘은 임시 변수를 사용하는거 보다 느림.  
임시변수를 사용하는 방법은 여러 명령어를 동시에 실행할 수 있게 최적화가 더 쉽기 때문.  
xor 알고리즘은 모두 데이터의 의존성( 저 순서를 반드시 지켜야됨)이 필요함.
따라서 현대 비순차 프로세서나 vlow 컴파일러가 xor 교체 알고리즘을 최적화할 방법은 거의 없음

비록 속도는 느리지만, 메모리 사용을 최소화해야 하는 임베디드 등의 환경에서는 유용하게 사용될 수 있다. 
- - -
####Reference

https://ko.wikipedia.org/wiki/XOR_%EA%B5%90%EC%B2%B4_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98