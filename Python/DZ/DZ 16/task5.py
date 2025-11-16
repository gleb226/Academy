import random

def product_in_range(start, end):
    if start > end:
        start, end = end, start
    product = 1
    for i in range(start, end + 1):
        product *= i
    return product

a = random.randint(1, 50)
b = random.randint(1, 50)

print("Numbers:", a, b)

result = product_in_range(a, b)
print("Result is:", result)
