// saquif_abdullah :: _DhumketU_ :: Date : 15-11-24 :: Time : 10:07 AM
// Base code(Python : Without OOP) : Lukman Hossain (instructor Ostad)

#include <bits/stdc++.h>
using namespace std;

class FavoriteFoodManager{
private:
    vector<string> food_list;
    ifstream inputFile;
    ofstream outputFile;
    string filename;

public:
    FavoriteFoodManager(const string &filename){
        cout << "\nWelcome to you in Favorite Food Manager" << endl;
        this->filename = filename;
        readData();
    }

    ~FavoriteFoodManager(){
        if(inputFile.is_open()){
            inputFile.close();
        }
        if(outputFile.is_open()){
            outputFile.close();
        }
    }

    void readData(){
        inputFile.open(filename);
        if(inputFile.is_open()){
            string str;
            while(getline(inputFile, str)){
                food_list.push_back(str);
            }
            inputFile.close();
        }else{
            cout << "Can't Open File" << endl;
        }
    }

    void writeData(){
        outputFile.open(filename);
        if(outputFile.is_open()){
            for(auto food: food_list){
                outputFile << food << endl;
            }
            outputFile.close();
        }else{
            cout << "Can't Open File" << endl;
        }

    }

    void display(){
        food_list.clear();
        readData();
        for(auto food: food_list){
            cout << food << endl;
        }
    }

    void addFood(string food){
        food_list.push_back(food);
        writeData();
        cout << food << " added Succuessfully" << endl;
    }

    void removeFood(string food){
        food_list.clear();
        readData();
        auto it = find(food_list.begin(), food_list.end(), food);
        if(it != food_list.end()){
            food_list.erase(it);
            cout << food << " removed successfully" << endl;
            writeData();
        }else{
            cout << food << " is not in the list." << endl;
        }

    }



};


void print_menu(map<int, string> &menu){
    cout << endl;
    for(auto m: menu){
        cout << m.first << " : " << m.second << endl;
    }
    cout << endl;
}

int main(){

    FavoriteFoodManager foodManagerObj("food_list.txt");

    map<int, string> menu;
    menu[1] = "to see your favorite food : ";
    menu[2] = "to add a new food : ";
    menu[3] = "to remove a food : ";
    menu[4] = "to Terminate the program : ";


    cout << "\nType M or m for Main Menu : ";
    string str;
    cin >> str;
    if(str != "M" && str != "m"){
        return 0;
    }

    while(true){

        print_menu(menu);
        int key; cin >> key;

        if(key == 1){
            foodManagerObj.display();
        }else if(key == 2){
            cout << "Enter food name : ";
            string food; cin >> food;
            foodManagerObj.addFood(food);
        }else if(key == 3){
            cout << "Enter food name : ";
            string food; cin >> food;
            foodManagerObj.removeFood(food);
        }else if(key == 4){
            return 0;
        }else{
            cout << "Invalid Input" << endl;
        }
    }


    return 0;
}
