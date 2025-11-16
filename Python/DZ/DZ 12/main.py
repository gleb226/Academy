SYMBOL = " " + "*" + "  "
SPACE = "    "
while True:
    print(" 1. a;\n 2. б;\n 3. в;\n 4. г;\n 5. д;\n 6. е;\n 7. ж;\n 8. з;\n 9. и;\n 10. к")
    user_choose = int(input("Enter your choose:  "))

    if user_choose < 1 or user_choose > 10:
        print("Invalid choose")

    if user_choose == 1:
        first_factor = 0
        second_factor = 5
        for _ in range(5):
            print(SPACE * first_factor + SYMBOL * second_factor)
            first_factor += 1
            second_factor -= 1

    elif user_choose == 2:
        first_factor = 1
        second_factor = 5
        for _ in range(5):
            print(SYMBOL * first_factor + SPACE * second_factor)
            first_factor += 1
            second_factor -= 1

    elif user_choose == 3:
        first_factor = 0
        second_factor = 5
        for _ in range(5):
            print(SPACE * first_factor + SYMBOL * second_factor + SPACE * first_factor)
            first_factor += 1
            second_factor -= 2

    elif user_choose == 4:
        first_factor = 2
        second_factor = 1
        for _ in range(2):
            print()
        for _ in range(3):
            print(SPACE * first_factor + SYMBOL * second_factor + SPACE * first_factor)
            first_factor -= 1
            second_factor += 2

    elif user_choose == 5:
        first_factor = 0
        second_factor = 5
        first_factor1 = 1
        second_factor1 = 3
        for _ in range(3):
            print(SPACE * first_factor + SYMBOL * second_factor + SPACE * first_factor)
            first_factor += 1
            second_factor -= 2
        for _ in range(2):
            print(SPACE * first_factor1 + SYMBOL * second_factor1 + SPACE * first_factor1)
            first_factor1 -= 1
            second_factor1 += 2

    elif user_choose == 6:
        first_factor = 1
        second_factor = 3
        first_factor1 = 2
        second_factor1 = 1
        for _ in range(2):
            print(SYMBOL * first_factor + SPACE * second_factor + SYMBOL * first_factor)
            first_factor += 1
            second_factor -= 2
        print(SYMBOL * 5)
        for _ in range(2):
            print(SYMBOL * first_factor1 + SPACE * second_factor1 + SYMBOL * first_factor1)
            first_factor1 -= 1
            second_factor1 += 2

    elif user_choose == 7:
        first_factor = 1
        second_factor = 4
        first_factor1 = 2
        second_factor1 = 3
        for _ in range(3):
            print(SYMBOL * first_factor + SPACE * second_factor)
            first_factor += 1
            second_factor -= 1
        for _ in range(2):
            print(SYMBOL * first_factor1 + SPACE * second_factor1)
            first_factor1 -= 1
            second_factor1 += 1

    elif user_choose == 8:
        first_factor = 1
        second_factor = 4
        first_factor1 = 2
        second_factor1 = 3
        for _ in range(3):
            print(SPACE * second_factor + SYMBOL * first_factor)
            first_factor += 1
            second_factor -= 1
        for _ in range(2):
            print(SPACE * second_factor1 + SYMBOL * first_factor1)
            first_factor1 -= 1
            second_factor1 += 1

    elif user_choose == 9:
        first_factor = 5
        second_factor = 0
        for _ in range(5):
            print(SYMBOL * first_factor + SPACE * second_factor)
            first_factor -= 1
            second_factor += 1

    elif user_choose == 10:
        first_factor = 4
        second_factor = 1
        for _ in range(5):
            print(SPACE * first_factor + SYMBOL * second_factor)
            first_factor -= 1
            second_factor += 1
