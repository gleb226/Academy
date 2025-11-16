import random


def is_prime(number):
    if number < 2:
        return False
    for i in range(2, int(number ** 0.5) + 1):
        if number % i == 0:
            return False
    return True


def count_primes(numbers):
    return sum(1 for num in numbers if is_prime(num))


random_numbers = [random.randint(1, 100) for _ in range(10)]

print("List of numbers:", random_numbers)
print("Number of primes:", count_primes(random_numbers))
