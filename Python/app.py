
### saquif_abdullah :: _DhumketU_ :: Date : 14-11-24 :: Time : 09:01 PM
### Base code(Without OOP) : Lukman Hossain (instructor Ostad)
### handling JSON File : I took support from online

# Note : Why JSON ? :: so that data won't be deleted when program will be terminated.

import json

class FavoriteFoodManager:

    def __init__(self):
        print("\nWelcome to you in Favorite Food Manager")
        with open('food_list.json', 'r') as file:
            self.food_list = json.load(file)


    def display_foods(self):
        if self.food_list:
            print("Favorite foods in your list :", ", ".join(self.food_list))
        else:
            print("No food is added yet, It's still empty (:")


    def add_food(self, food):
        if food in self.food_list:
            print(f"{food} is already in the list")
            return

        self.food_list.append(food)
        with open('food_list.json', 'w') as file:
            json.dump(self.food_list, file)
        print(f"{food} added successfully")

    def remove_food(self, food):
        if food in self.food_list:
            self.food_list.remove(food)
        else:
            print(f"{food} is not in the list")



    

managerObj = FavoriteFoodManager()

while True:
    str = input("\nType M/m for Main Menu : ")
    if str != 'M' and str != 'm':
        exit()
    print("\nMain Menu : ")
    print("1 to see your favorite food : ")
    print("2 to add a new food : ")
    print("3 to remove a food : ")
    print("4 to Terminate the program : ")

    key = input()
    if key == '1':
        managerObj.display_foods()
    elif key == '2':
        food = input("Food name please : ")
        managerObj.add_food(food)
    elif key == '3':
        food = input("Type the name of which food you want to remove : ")
        managerObj.remove_food(food)
    elif key == '4':
        print("Thank you for using Favorite Food Manager")
        exit()
    else:
        print("Please enter a valid input")