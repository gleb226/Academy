import random


def power_elements(numbers, exponent):
    return [num ** exponent for num in numbers]


my_list = [random.randint(1, 10) for _ in range(5)]
exponent = random.randint(1, 3)
powered_list = power_elements(my_list, exponent)

print("Original list:", my_list)
print("List with elements raised to the power of", exponent, ":", powered_list)
