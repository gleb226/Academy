import random


def find_min(numbers):
    min_value = numbers[0]
    for number in numbers:
        if number < min_value:
            min_value = number
    return min_value


random_numbers = [random.randint(1, 100) for _ in range(10)]

print("List of numbers:", random_numbers)
print("Minimum value in the list:", find_min(random_numbers))
