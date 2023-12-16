import sys
import random
from pyfiglet import Figlet


le = len(sys.argv)
figlet = Figlet()
fonts = figlet.getFonts()
inp = input("Input: ")


if le == 1:
    rand = random.randint(0,len(fonts)-1)
    figlet.setFont(font = fonts[rand])


elif le == 3:
    if sys.argv[1] != ("-f" or "--font"):
        print("Write the write to print in a specific font")
        sys.exit(1)
    figlet.setFont(font = sys.argv[2])


else:
    print("Please input 0 or 2 command-line arguments")
    sys.exit(1)


print("Output")
print(figlet.renderText(inp))
sys.exit(0)





inp = input("Input: ")

print(figlet.renderText(inp))
