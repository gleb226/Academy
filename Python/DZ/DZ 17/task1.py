import random


def multiply_elements(numbers):
    result = 1
    for num in numbers:
        result *= num
    return result


nums = [random.randint(1, 10) for _ in range(5)]
product = multiply_elements(nums)
print("List:", nums)
print("Product:", product)
