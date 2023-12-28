#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

#define COMMON_UI_STRING "Welcome to QuirkyMart\t\t\t\t(Your Balance is " << balance << " Birr)\n\n"

int main(){
   
   //Database
    string catagoryDb[] = {"Clothing", "Gaming", "Self-Care", "Electronics"};
    string clothingMaleItemDb[5][2] = {{"Cargo Pants", "900"}, {"T-shirt", "500"}, {"Trouser", "1200"}, {"Ski mask", "400"}, {"Silk durag", "300"}};
    string clothingFemaleItemDb[3][2] = {{"Oversized pants", "1000"}, {"Tote bag", "700"}, {"Allstar", "3000"}};
    string gamingItemsDb[4][2] = {{"Playstation 4", "20000"},{"GTA V", "1000"},{"VR Headset", "3000"},{"VR Stick", "10000"}};
    string selfCareItemDb[4][2] = {{"Cerave", "3000"},{"Nivea", "600"},{"Face mask", "400"},{"Vibe Shampoo", "2000"}};
    string electronicsItemDb[4][2] = {{"Iphone XR", "21000"}, {"LG widescreen", "40000"}, {"Lenovo", "54000"}, {"Samsung s21", "60000"}};
    //

    string ussdCode;
    getline(cin, ussdCode);
    int catagorySize = sizeof(catagoryDb)/sizeof(catagoryDb[0]);
    string cartStoreArray[][2] = {};
    if (ussdCode == "*910#") {
        double balance = 0;
        char choice;
        while (true)
        {
        cout <<COMMON_UI_STRING;
        cout << "1. Explore todays market\n";
        cout << "2. Cart\n";
        cout << "3. Recharge Balance\n";
        cout << "4. Help\n";
        cout << "X. Exit\n\n";
        cout << "Enter your choice: ";
        cin>>choice;
        if(toupper(choice)=='X')break;
        switch (tolower(choice))
        {
        case '1':
              cout<<COMMON_UI_STRING;
              cout<<"Choose category you want to buy(* to exit)\n";
              for(int i=0; i<catagorySize; i++){
                 cout<<i+1<<".  "<<catagoryDb[i]<<endl;
              }
              cout<<"Enter your choice: ";
              cin>>choice;
                  if(choice=='*')break;    
        case '3':
             double amount;
             cout << "Enter the recharge amount: ";
             cin >> amount;
             balance += amount;
             cout << "Balance recharged successfully. Your new balance is: " << balance << " Birr\n";
             break;
        
        default:
        cout<<"\nInvalid Choice! Please enter again.\n\n";
            break;
        }
        }
      
    }

    return 0;
}