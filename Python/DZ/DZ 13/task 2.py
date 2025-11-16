text = input("Enter the text: ")
reserved_words = input("Enter reserved words separated by spaces: ").split()

for word in reserved_words:
    text = text.replace(word, word.upper())

print("Modified text:", text)
