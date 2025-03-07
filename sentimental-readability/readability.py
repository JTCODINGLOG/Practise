from cs50 import get_string
import string


def main():
    text = get_string("Text: ")

    L = c_letters(text) / c_words(text) * 100
    S = c_sentences(text) / c_words(text) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        return print("Before Grade 1\n")
    elif index > 16:
        return print("Grade 16+\n")
    else:
        return print(f"Grade {index}")


def c_letters(txt):
    letters = 0
    for char in txt:
        if char.isalpha():
            letters += 1
    return letters


def c_words(txt):
    spaces = 0
    for char in txt:
        if (char.isspace()):
            spaces += 1
    words = spaces + 1
    return words


def c_sentences(txt):
    sentences = 0
    for i in range(len(txt) - 1):
        if (txt[i].isspace() and txt[i-1] in ".!?"):
            sentences += 1
    sentences += 1
    return sentences


if __name__ == "__main__":
    main()
