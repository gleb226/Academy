BOARD_SIZE = 6

MOVES = [
    (2, 1), (2, -1), (-2, 1), (-2, -1),
    (1, 2), (1, -2), (-1, 2), (-1, -2)
]


def is_valid_move(x, y, board):
    return 0 <= x < BOARD_SIZE and 0 <= y < BOARD_SIZE and board[x][y] == -1


def solve_knight_tour(x, y, move_count, board):
    if move_count == BOARD_SIZE * BOARD_SIZE:
        return True

    for dx, dy in MOVES:
        new_x, new_y = x + dx, y + dy
        if is_valid_move(new_x, new_y, board):
            board[new_x][new_y] = move_count
            if solve_knight_tour(new_x, new_y, move_count + 1, board):
                return True
            board[new_x][new_y] = -1  # Відкат ходу

    return False


def print_board(board):
    for row in board:
        print(" ".join(f"{cell:2}" for cell in row))
    print()


def main():
    x = int(input(f"Enter starting row (0-{BOARD_SIZE - 1}): "))
    y = int(input(f"Enter starting column (0-{BOARD_SIZE - 1}): "))

    board = [[-1] * BOARD_SIZE for _ in range(BOARD_SIZE)]
    board[x][y] = 0

    if solve_knight_tour(x, y, 1, board):
        print("Knight's tour found:")
        print_board(board)
    else:
        print("No solution found.")


main()
