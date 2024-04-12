from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?")
