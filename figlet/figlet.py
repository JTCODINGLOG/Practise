pip install pyfiglet

from sys import argv
from figlet import Figlet

if len(argv) != 0:
    print("Please input 0 or 2 command-line arguments")
    sys.exit(1)



inp = input("Input: ")

print(figlet.renderText(inp))
