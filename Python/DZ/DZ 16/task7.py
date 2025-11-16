import random

def is_palindrome(number: int):
    num_str = str(number)
    return num_str == num_str[::-1]


number = random.randint(100000, 999999)

print("Number:", number)

result = is_palindrome(number)
print("Is palindrome:", result)
