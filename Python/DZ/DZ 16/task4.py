import random


def min_of_five(a, b, c, d, e):
    minimum = a
    numbers = [a, b, c, d, e]
    for num in numbers:
        if num < minimum:
            minimum = num
    return minimum


a = random.randint(1, 100)
b = random.randint(1, 100)
c = random.randint(1, 100)
d = random.randint(1, 100)
e = random.randint(1, 100)

print("Numbers:", a, b, c, d, e)

result = min_of_five(a, b, c, d, e)
print("Result is:", result)
