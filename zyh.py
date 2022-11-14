from numpy import number


def solution(A):
    n = len(A)
    if A[0] != A[-1]:
        return n - 1
    index = 0
    while index < n and A[index] == A[0]:
        index += 1
    ans = 0
    ans = max(ans, n - 1 - index)
    index = n - 1
    while index >= 0 and A[index]
