#!/usr/local/bin/python3

import math
import os
import random
import re
import sys


def get_index(a, x, lo, hi):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if a[mid] > x: lo = mid+1
        else: hi = mid
    return lo


# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    result = []
    board = list(set(scores))
    board.sort(reverse=True)
    high = len(board)
    for _s in alice:
        i = get_index(board, _s, 0, high)
        board.insert(i, _s)
        rank = i + 1
        result.append(rank)
        # board.remove(_s)
        del board[i]
        high = rank - 1
    return result


if __name__ == '__main__':
   
    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    print('\n'.join(map(str, result)))
