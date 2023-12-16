import sys
import random
from pyfiglet import Figlet


le = len(sys.argv)
figlet = Figlet()
fonts = figlet.getFonts()
inp = input("Input: ")


if le == 1:
    rand = random.randint(le,len(fonts))
    figlet.setFont(font = fonts[rand])


elif le == 3:
    figlet.setFont(font = sys.argv[1])


else:
    print("Please input 0 or 2 command-line arguments")
    sys.exit(1)


print("Output")
print(figlet.renderText(inp))
sys.exit(0)





inp = input("Input: ")

print(figlet.renderText(inp))
