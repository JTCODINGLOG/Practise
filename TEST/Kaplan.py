age = int(input("Enter your age:"))

if age < 18:
    print("Sorry under 18s are not allowed")
elif age == 18:
    print("We will invite you to your first drink, chuck it!")
elif age == 19:
    print("We will give you drinks")
else:
    print("Welcome and drink!")
