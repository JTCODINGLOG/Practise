from cs50 import get_string

text = get_string("Text: ")

L = c_letters(text) / c_words(text) * 100
S = c_sentences(text) / c_words(text) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)
