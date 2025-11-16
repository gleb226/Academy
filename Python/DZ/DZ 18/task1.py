import random


def gcd_recursive(a: int, b: int):
    if b == 0:
        return a
    return gcd_recursive(b, a % b)


num1 = random.randint(1, 100)
num2 = random.randint(1, 100)

print("GCD(", num1, ",", num2, ") =", gcd_recursive(num1, num2))
