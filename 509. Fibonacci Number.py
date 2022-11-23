history = {}


def fibonacci(n:int) -> int: 
    if n in history:
        return history[n]
    else:
        history[n] = fibonacci(n-1) + fibonacci(n-2)
        return history[n]
        
class Solution:
    def fib(self, n: int) -> int:
        history[0] = 0
        history[1] = 1
        history[2] = 1
        return fibonacci(n)