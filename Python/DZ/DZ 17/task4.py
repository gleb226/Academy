import random


def remove_number(numbers, target):
    count = numbers.count(target)
    numbers = [num for num in numbers if num != target]
    return count


random_numbers = [random.randint(1, 20) for _ in range(10)]
target_number = random.randint(1, 20)
removed_count = remove_number(random_numbers, target_number)

print("Original list:", random_numbers)
print("Target number:", target_number)
print("Number of removed elements:", removed_count)
