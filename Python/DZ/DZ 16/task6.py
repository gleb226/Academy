import random

def count_digits(number: int):
    return len(str(number))


number = random.randint(1, 10000)

print("Number:", number)

result = count_digits(number)
print("Number of digits:", result)
