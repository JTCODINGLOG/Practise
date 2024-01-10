def get_int(x):
    while True:
        try:
            return int(input(x))
        except ValueError:
            print()


def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)


main()

