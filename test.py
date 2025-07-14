def sum_to_n(n):
    if (n <= 0):
        return 0
    
    return n + sum_to_n(n - 1)

def fib(n):
    if (n == 0 or n == 1):
        return n;
    return fib(n - 1) + fib(n - 2)

def factorial(n):
    if n <= 0 :
        return 1
    return n * factorial(n - 1)

def reverse_str(s, n):
    if n < 0 :
        return ""
    return s[n] + reverse_str(s, n - 1)

def count(n):
    if n <= 0:
        return 1;
    return count(n - 1)

#print(reverse_str("hello", 4))
#print(factorial(3))
#count(3)