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


