# a5 : 11 22 13
# a6 : 12 22 11 31


def num_cnt_array(n):
    ret = [1]
    while n:
        next= []
        next.append(ret[0])
        prev = ret[0]
        cnt = 1
        for i in range(1, len(ret)):
            if prev == ret[i]:
                cnt += 1
                continue
            else:
                next.append(cnt)
                prev = ret[i]
                next.append(ret[i])
                cnt = 1
        next.append(cnt)
        ret = next
        n -= 1

    return ret

def num_cnt_array2(n):
    if n == 0:
        return [1]
    else:
        tmp = num_cnt_array2(n-1)
        ret = []
        prev = 0
        for i in tmp:
            if prev != i:
                ret.append(i)
            else:
                pass
    return ret



if __name__ == '__main__':
    print(num_cnt_array(4))


