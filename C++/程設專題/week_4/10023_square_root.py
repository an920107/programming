t = int(input())
for i in range(t):
    input()
    n_str = input()
    dig = len(n_str)
    n = int(n_str)

    lower = int(n_str[: dig // 2]) if dig > 1 else 0
    upper = int(n_str[: dig // 2 + 1]) + 1
    while lower < upper - 1:
        mid = (lower + upper) >> 1
        mid_square = mid ** 2
        if mid_square <= n:
            lower = mid
        elif mid_square > n:
            upper = mid

    print(lower)
    if (i < t - 1):
        print()
