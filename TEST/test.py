people = {
    "Javier": "0411251528",
    "David": "0402040184",
    "John": "0444444444",
}

name = input("Name: ")
if name in people:
    print(f"Found: {people[name]}")
else:
    print("Not found")
