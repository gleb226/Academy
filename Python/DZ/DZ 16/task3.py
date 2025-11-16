def draw_square(size, char, filled):
    for i in range(size):
        if filled or i == 0 or i == size - 1:
            print(char * size)
        else:
            print(char + ' ' * (size - 2) + char)


draw_square(5, '*', True)
print()
draw_square(5, '*', False)
