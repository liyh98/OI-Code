import random
from typing import Callable

deltas = [(0, 10), (0, -10), (10, 0), (-10, 0)]
N = 1000000


def f(pos: tuple[float, float]) -> bool:
    x, y = pos
    return (((x - 2.5) / 30) ** 2) + (((y - 2.5) / 40) ** 2) >= 1


def add(x: tuple[float, float], y: tuple[float, float]) -> tuple[float, float]:
    return (x[0] + y[0], x[1] + y[1])


def mul(k: float, x: tuple[float, float]) -> tuple[float, float]:
    return (k * x[0], k * x[1])


def expected_time(food: Callable[[tuple[float, float]], bool]) -> float:
    random.seed()
    total_time = 0
    for i in range(N):
        pos = (0, 0)
        time = 0
        while True:
            # print(pos)
            # input()
            direction = random.randint(0, 3)
            pos_next = add(pos, deltas[direction])
            if food(pos_next):
                l = 0
                r = 1
                while (r - l > 1e-6):
                    mid = (l + r) / 2
                    pos_temp = add(pos, mul(mid, deltas[direction]))
                    if food(pos_temp):
                        r = mid
                    else:
                        l = mid
                time += r
                break
            else:
                pos = pos_next
                time += 1
        total_time += time
    return total_time / N


print(expected_time(f))
