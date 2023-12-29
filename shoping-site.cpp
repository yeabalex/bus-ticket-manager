#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

#define COMMON_UI_STRING "(Your Balance is " << balance << " Birr)\n\n"
#define CHOICE_PROMPT "Enter your choice: ";

int main(){
   
   //Database
    string catagoryDb[] = {"Clothing", "Gaming", "Self-Care", "Electronics"};
    string clothingItemDb[8][2] = {{"Cargo Pants", "900"}, {"T-shirt", "500"}, {"Trouser", "1200"}, {"Ski mask", "400"}, {"Silk durag", "300"},{"Oversized pants", "1000"}, {"Tote bag", "700"}, {"Allstar", "3000"}};
    string gamingItemsDb[4][2] = {{"Playstation 4", "20000"},{"GTA V", "1000"},{"VR Headset", "3000"},{"VR Stick", "10000"}};
    string selfCareItemDb[4][2] = {{"Cerave", "3000"},{"Nivea", "600"},{"Face mask", "400"},{"Vibe Shampoo", "2000"}};
    string electronicsItemDb[4][2] = {{"Iphone XR", "21000"}, {"LG widescreen", "40000"}, {"Lenovo", "54000"}, {"Samsung s21", "60000"}};
    //

    string ussdCode;
    getline(cin, ussdCode);
    int catagorySize = sizeof(catagoryDb)/sizeof(catagoryDb[0]);
    int clothingItemSize = sizeof(clothingItemDb)/sizeof(clothingItemDb[0]);
    string cartStoreArray[][2] = {};
    string(*p)[2] = nullptr;

    if (ussdCode == "*910#") {
        double balance = 0;
        char choice;

       MainMenu: while (true)
        {
        cout <<"Welcome to QuickMart\t\t\t"<<COMMON_UI_STRING;
        cout << "1. Explore todays market\n";
        cout << "2. Cart\n";
        cout << "3. Recharge Balance\n";
        cout << "4. Help\n";
        cout << "X. Exit\n\n";
        cout<<CHOICE_PROMPT;
        cin>>choice;
        if(toupper(choice)=='X')break;
        switch (choice)
        {
        case '1':
            goto CatagorySelectah;
            break;
        case '3':
            goto BalanceRecharger;
            break; 
        default:
            break;
        }
        }

    CatagorySelectah: while(tolower(choice)=='1'){
            cout<<"Choose a catagory to buy from(* for back)\t\t\t"<<COMMON_UI_STRING<<endl;
            for(int i=0;i<catagorySize;i++){
                cout<<i+1<<".  "<<catagoryDb[i]<<endl;
            }
            cout<<CHOICE_PROMPT;
            cin>>choice;
            if(choice=='*')goto MainMenu;
            switch (choice)
            {
            case '1':
                goto ClothingSection;
                continue;
            }
            
     }
    ClothingSection: while (tolower(choice)=='1')
    {
        p=clothingItemDb;
        for(int i=0; i<clothingItemSize; i++){
            for(int j=0; j<2; j++){
                if(j==0)cout<<i+1<<".  ";
                cout<<*(*(p+i)+j)<<endl;
            }
        }
        cin>>choice;
        if(choice=='*'){
            choice='1';
            goto CatagorySelectah;
            }
    }
     
        
    BalanceRecharger: while(tolower(choice)=='3'){
          double amount;
             cout << "Enter the recharge amount: ";
             cin >> amount;
            
             balance += amount;
             cout << "Balance recharged successfully. Your new balance is: " << balance << " Birr\n";
             goto MainMenu;
             break;
    }








        
      
    }

    return 0;
}