



def power10(b, k):
    """
    b * (10)^k 를 반환한다.
    :param b:
    :param k:
    :return: List[Integer]
    """
    ret = []
    for i in range(k):
        ret.append(0)
    ret.extend(b)

    return ret


def add(a, b):
    ret = []

    carry = [0]
    i = iter(a)
    j = iter(b)

    while i or j:
        tmp = 0
        a_one = next(i, None)
        b_one = next(j, None)
        tmp += a_one and a_one or 0
        tmp += b_one and b_one or 0
        tmp += carry[-1]
        if tmp > 9:
            carry.append(1)
            tmp -= 10
        else:
            carry.append(0)
        ret.append(tmp)

    if carry[-1] == 1:
        ret.append(1)

    return ret





def addTo(a, b, k):
    """
    a += b * (10)^k 를 구현한다.
    :param a: List[Integer]
    :param b: List[Integer]
    :param k:
    :return:
    """
    tmp = power10(b, k)



    pass

def subFrom(a, b, k):
    """
    a -= b 를 구현, a>= b를 가정
    :param a:
    :param b:
    :param k:
    :return:
    """


def karatsuba(A, B):
    """
    A, B에 대해 곱셈 연산을 divide-and-conquer로 한다.
    A와 B는 reverse되서 들어온다.
    :param A: List[Integer]
    :param B: List[Integer]
    :return: List[Integer]

    """
    pass


if __name__ == '__main__':
     A = [1,0,2,1]
     B = [3,4,5,7,6,8]
     print(add([1,2,3], [1,2]))
