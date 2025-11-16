text = input("Enter the text: ")
sentences = text.count(".") + text.count("!") + text.count("?")
print("Number of sentences in the text:", sentences)
