from cs50 import get_string
import nltk
nltk.download('punkt')
from nltk.tokenize import sent_tokenize, word_tokenize


text = get_string("Text: ")
sentences = sent_tokenize(text)
words = word_tokenize(text)

num_sentences = len(sentences)
num_words = len(words)
num_letters = sum(len(word) for word in words)

L = num_letters / num_words * 100
S = num_sentences / num_words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before grade 1\n")
elif index > 16:
    print("Grade 16+\n")
else:
    print(f"Grade {index}")


