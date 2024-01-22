from cs50 import get_string
import string


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
    letters = 0
    for char in txt:
        if char.isalpha():
            letters += 1
    return letters


def c_words(txt):
    words = 0
    for i in range(len(txt)-1):
        if (txt[i].isalpha() and txt[i + 1].isspace()) or txt[i + 1] in string.punctuation:
            if txt[i + 1] == '-':
                continue
            words += 1
    return words


def c_sentences(txt):
    sentences = 0
    for char in txt:
        if char == '.' or '!' or '?':
            sentences += 1
    return sentences


# str.isdigit(), str.isalpha(), str.islower(), str.isupper(), and str.isspace()

if __name__ == "__main__":
    main()
