import random

numbers = [random.randint(-10, 10) for _ in range(20)]
print("List of numbers:", numbers)

min_num = numbers[0]
max_num = numbers[0]

for num in numbers:
    if num < min_num:
        min_num = num
    if num > max_num:
        max_num = num

print("Minimum element:", min_num)
print("Maximum element:", max_num)
