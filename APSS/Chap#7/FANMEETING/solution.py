import fileinput
from copy import deepcopy

def toInteger(s):
    return (int)(s)


def print_2dim(arr):
    for i in range(len(arr)):
        print(arr[i])



def plus_no_carry(li1, li2):

    if len(li2) > len(li1):
        bigger = deepcopy(li2)
        smaller = li1
    else:
        bigger = deepcopy(li1)
        smaller = li2

    print(li1, li2)

    for i in range(len(smaller)):
        bigger[i] += smaller[i]

    return bigger


def plus_no_carry_aug(li1, li2):
    bigger = li1
    smaller = li2

    for i in range(len(smaller)):
        bigger[i] += smaller[i]

    return bigger


def plus_no_carry_multi(*li):
    i = iter(li)
    ret = deepcopy(i)
    while i:
        target = next(i)
        plus_no_carry_aug(ret, target)

    return ret


def minus_no_carry(li1, li2):
    if len(li2) > len(li1):
        bigger = deepcopy(li2)
        smaller = li1
    else:
        bigger = deepcopy(li1)
        smaller = li2
    for i in range(len(smaller)):
        bigger[i] -= smaller[i]

    return bigger


def padding_zero_front(li, n):
    ret = [0 for x in range(n)]
    print(ret)
    ret.extend(li)
    return ret


def padding_zero_rear(li, n):
    ret = [0 for x in range(n)]
    li.extend(ret)
    return li

def product(mem, fan):
    # mem이 항상 사이즈가 작다.
    padded_mem = padding_zero_front(mem, len(fan) - len(mem) )
    return product_recur(padded_mem, fan, 0, len(fan))



def product_recur(padded_mem, fan, s, e):
    #(A * 10^n + B ) (C * 10^m + D) = AC * 10^2n + (AD + BC)* 10^n + BD
    # AD + BC = (A+B)(C*D) - (AC + BD)
    # Z1 = AC, Z2 = BD, Z3 = (A+B)(C+D)
    # 구하고자하는값 = Z1 * 10^2n + (Z3 - Z1- Z2) * 10^n + Z2

    print(padded_mem, fan, s, e)
    if e-s == 1:
        tmp = [padded_mem[s] * fan[s]]
        tmp = padding_zero_rear(tmp, len(padded_mem) - e)
        tmp = padding_zero_front(tmp, s)
        print("Qwer", tmp)
        return tmp

    mid = s + int((e-s)/2)
    Z1 = product_recur(padded_mem, fan, s, mid)
    Z2 = product_recur(padded_mem, fan, mid, e)

    T1 = plus_no_carry(padded_mem[:mid], fan[:mid])
    T2 = plus_no_carry(padded_mem[mid:], fan[mid:])
    Z3 = product_recur(T1, T2, 0, len(T1))

    t1 = padding_zero_rear(Z1, 2*mid)
    t2 = padding_zero_rear(minus_no_carry(Z3, plus_no_carry(Z1, Z2)), mid)

    return plus_no_carry(plus_no_carry(t1, t2), Z2)






if __name__ == '__main__':
    with fileinput.input(files=('./input')) as f:
        cnt = toInteger(f.readline())
        for i in range(cnt):

            s1 = f.readline().split()[0]
            s2 = f.readline().split()[0]
            num_member = [(int)(x == 'F') for x in s1]
            num_fan = [(int)(x == 'F') for x in s2]
            print(product(num_member, num_fan).count(len(s1)))



