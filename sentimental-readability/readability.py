from cs50 import get_string
import nltk
nltk.download('punkt')
from nltk.tokenize import sent_tokenize, word_tokenize

def main():
    text = get_string("Text: ")

    L = c_letters(text) / c_words(text) * 100
    S = c_sentences(text) / c_words(text) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        return print("Before grade 1\n")
    elif index > 16:
        return print("Grade 16+\n")
    else:
        return print(f"Grade {index}")

def c_letters(txt):
    


def c_words(txt):



def c_sentences(txt):



if __name__ == "__main__":
    main()

