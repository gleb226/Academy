import random


def generate_number():
    return str(random.randint(1000, 9999))


def count_bulls_and_cows(secret, guess):
    bulls = sum(1 for s, g in zip(secret, guess) if s == g)
    cows = sum(1 for g in guess if g in secret) - bulls
    return bulls, cows


def play_game(secret, attempts=0):
    guess = input("Enter a 4-digit number: ")

    if not guess.isdigit() or len(guess) != 4:
        print("The number must be exactly 4 digits.")
        return play_game(secret, attempts)

    attempts += 1
    bulls, cows = count_bulls_and_cows(secret, guess)

    if bulls == 4:
        print("You guessed the number", secret, "in", attempts, "attempts!")
        return
    else:
        print("Bulls:", bulls, "Cows:", cows)
        return play_game(secret, attempts)


secret_number = generate_number()
play_game(secret_number)
