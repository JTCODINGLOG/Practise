import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for d in reader:
        favorite = row[1]
        print(favorite)


