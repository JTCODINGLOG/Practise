greeting = input("Greeting: ")
greeting.lower()
if "hello" == greeting.split()[0]:
    print("$0")
elif greeting[0] == "h":
    print("$20")
else:
    print("$100")

