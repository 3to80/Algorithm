
# idea : reverse depth를 다르게 말하면, 일찍 더해지는 거는, 계속해서 더해진다는 것을 의미한다.
# 따라서, 곱하기가 아니라 계속해서 덧셈을 하면 답이 나옴.

def solve(nestedList):
    total_weight = 0
    weight = 0

    while nestedList:
        weight += sum([x.getInteger() for x in nestedList if x.isInteger()])
        total_weight += weight
        nestedList = sum([x.getList() for x in nestedList if not x.isInteger()], [])

    return total_weight
