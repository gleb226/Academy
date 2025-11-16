expression = input("Enter an arithmetic expression (e.g., 23+12): ")

if '+' in expression:
    num1, num2 = expression.split('+')
    result = int(num1) + int(num2)
elif '-' in expression:
    num1, num2 = expression.split('-')
    result = int(num1) - int(num2)
elif '*' in expression:
    num1, num2 = expression.split('*')
    result = int(num1) * int(num2)
elif '/' in expression:
    num1, num2 = expression.split('/')
    if int(num2) == 0:
        result = "Error: Division by zero"
    else:
        result = int(num1) / int(num2)
else:
    result = "Invalid expression format"

print("Result:", result)
