#
# @lc app=leetcode id=1116 lang=python3
#
# [1116] Print Zero Even Odd
#

# @lc code=start
from threading import Lock

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.i = 0
        self.zero_lock = Lock()
        self.even_lock = Lock()
        self.odd_lock = Lock()
        self.even_lock.acquire()
        self.odd_lock.acquire()

    # printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.n):
            self.zero_lock.acquire()
            printNumber(0)
            self.i += 1
            if self.i % 2:
                self.odd_lock.release()
            else:
                self.even_lock.release()

    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.n//2):
            self.even_lock.acquire()
            printNumber(self.i)
            self.zero_lock.release()

    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range((self.n+1)//2):
            self.odd_lock.acquire()
            printNumber(self.i)
            self.zero_lock.release()

# @lc code=end

