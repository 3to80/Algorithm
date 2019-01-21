pret = 0
cret = 0 

def print_base(picked):
    local = []
    for i in range(len(picked)):
        if not picked[i]:continue
        local.append(i)
    print(local)        

def permutation(n, picked, m):
    if m == 0:
        global pret
        pret +=1
        print_base(picked)
    else:
        for i in range(n):
            if not picked[i]: 
                picked[i] = True
                permutation(n, picked, m-1)
                picked[i] = False

def combination(n, picked, toPick):
    if toPick == 0:
        global cret
        cret += 1
        print(picked)
    else:
        # a if condition else b
        smallest = 0 if not picked else (picked[-1] + 1)
        for i in range(smallest, n):
            picked.append(i)
            combination(n, picked, toPick-1)
            picked.pop()
                                
n = 4
picked = [False for x in range(n)]
m = 2
permutation(n, picked, m)
print(pret)

combination(n, [], m)
print(cret)


