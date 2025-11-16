import random

SIZE = 4
EMPTY = 0


def create_board():
    numbers = list(range(1, SIZE * SIZE)) + [EMPTY]
    random.shuffle(numbers)
    board = [numbers[i * SIZE:(i + 1) * SIZE] for i in range(SIZE)]
    return board


def find_empty(board):
    for i in range(SIZE):
        for j in range(SIZE):
            if board[i][j] == EMPTY:
                return i, j


def is_solvable(board):
    flat_list = [num for row in board for num in row if num != EMPTY]
    inversions = sum(
        1 for i in range(len(flat_list)) for j in range(i + 1, len(flat_list)) if flat_list[i] > flat_list[j])
    empty_row = find_empty(board)[0]
    return (inversions + empty_row) % 2 == 0


def print_board(board):
    for row in board:
        print(" ".join(f"{num:2}" if num != EMPTY else " ." for num in row))
    print()


def move_tile(board, direction):
    x, y = find_empty(board)
    moves = {"w": (x + 1, y), "s": (x - 1, y), "a": (x, y + 1), "d": (x, y - 1)}

    if direction in moves:
        nx, ny = moves[direction]
        if 0 <= nx < SIZE and 0 <= ny < SIZE:
            board[x][y], board[nx][ny] = board[nx][ny], board[x][y]
            return True
    return False


def is_solved(board):
    goal = list(range(1, SIZE * SIZE)) + [EMPTY]
    return [num for row in board for num in row] == goal


def main():
    board = create_board()

    while not is_solvable(board):
        board = create_board()

    while True:
        print_board(board)
        if is_solved(board):
            print("Congratulations! You solved the puzzle!")
            break

        move = input("Enter move (w/a/s/d): ").lower()
        if move in "wasd":
            move_tile(board, move)


main()
