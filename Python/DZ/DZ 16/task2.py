import random


def show_odd_numbers(start, end):
    if start > end:
        start, end = end, start
    for i in range(start, end + 1):
        if i % 2 != 0:
            print(i)


a = random.randint(1, 50)
b = random.randint(1, 50)

print(f"Numbers: from {a}, to {b}")

show_odd_numbers(a, b)
