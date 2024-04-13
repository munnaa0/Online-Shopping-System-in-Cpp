///Program written by Md. Sultan Mahmud Munna
///Bangladesh Army University Of Science and Technology
#include<iostream>
using namespace std;
int totalproducts = 0;///Tracks how many product user bought
double totalPrice = 0;///tracks Total price of products

class shop
{
public:
    string CartedItems[100]; /// Array to store carted items
    int CartedQuantity[100]; /// Array to store carted items Quantity
    double CartedPrice[100]; /// Array to store carted items Price
    int cartIndex = 0;

    void Carted(string item, int quantity, double price)
    {
        CartedItems[cartIndex] = item;
        CartedQuantity[cartIndex] = quantity;
        CartedPrice[cartIndex] = price;
        cout << item << " " << "Added to the cart!!!";
        cartIndex+=1;
    }

    void displayCart()
    {
        cout << "\n\nItems in the cart:\n" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Quantity      Name                               Price" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < cartIndex; ++i)
        {
            cout << "  " << CartedQuantity[i];
            cout << "\t     " << CartedItems[i] ;
            cout << "\t     \t\t" << CartedPrice[i] << " Taka "<< endl;
        }
        cout << endl << "-----------------------------------------------------------" << endl;
        cout << "\tTotal price is: \t\t\t" << totalPrice << " Taka" << endl;
    }
};
///*************************************User Class******************************************************
class user
{
    string nickname;
    string password;
    double balance = 0;
    string attempt;
public:
    string username;
    bool returns = true;
    user()
    {
        cout << "\n\t\t\tWelcome to EazyMart!!!" << endl;
        cout << "\t\tPlease create an Account to continue Shopping" << endl;
        cout << "Enter Your username : ";
        getline(cin,username);
        cout << "Enter Your Password: ";
        getline(cin,password);
        cout << "Enter a nickname(This will be used to reset password) : ";
        getline(cin,nickname);
        cout << "Add some balance to buy products:  ";
        cin >> balance;
    }

    void checkout()
    {
        string checkpass;
trypassagain:
        cout << endl <<"Enter your password to confirm Checkout or (Type 0 to return Main Menu): ";
        getline(cin,checkpass);
        if(checkpass == "0")
            returns = false;
        else if(checkpass == password)
        {
            if(balance < totalPrice)
            {
                cout << "\nInsufficient Balance!!" << endl;
                cout << "Please add balance from (My Account and balance)" << endl << endl;
                returns = false;
            }
            else
            {
                balance -= totalPrice;
                cout << "\n\n\t\t-------------------------------------------" << endl ;
                cout << "\t\t\t    Purchase Successful !!! " << endl;
                cout << "\t\t     Your current balance is " << balance << " Taka"<< endl;
                cout << "\t\t-------------------------------------------\n\n\n" << endl ;
                cout << "\t\t******************************************* ";
                cout << endl << "\t\t* Thank You For shopping with EazyMart!!! *" << endl;
                cout << "\t\t*      Hope you Have a lovely day!!!      *" << endl;
                cout << "\t\t*******************************************\n\n\n" << endl;
                returns = true;
            }
        }
        else
        {
            cout << endl << "Wrong Password!!! " << endl;
            cout << "If forgot password Please go My Account and Balance to Reset Password " << endl;
            goto trypassagain;
        }
    }

    void showbalance()
    {
        cout << "\n\t\t\t  Your balance is " << balance << " Taka" << endl;
        cout << "\t\t-----------------------------------------" << endl;
    }
    void addbalance()
    {
        int extrabalance;
        cout << "Enter amount to add: ";
        cin >> extrabalance;
        balance += extrabalance;
        cout << "\t\t\t " << extrabalance << " Taka added successfully " << endl;
        cout << "\t\t\tCurrent Balance is " << balance << " Taka"<< endl;
        cout << "\t\t-----------------------------------------" << endl;
        extrabalance = 0;
    }
    void displayuserdata()
    {
attemptagain:
        cout << "Enter Your password: ";
        getline(cin,attempt);
        if(attempt == password)
        {
            cout << "\n\t\t\tYour UserName is " << username << endl;
            cout << "\t\t\tYour nickname is " << nickname << endl;
            cout << "\t\t\tYour Balance is " << balance << " Taka" << endl;
            cout << "\t\t-----------------------------------------" << endl;

        }
        else
        {
            cout << "Wrong password!!! Try Again!!!" << endl;
            goto attemptagain;
        }

    }
    void forgetpass()
    {
        string forgetnick;
forgetnickname:
        cout << "Enter your nickname: ";
        getline(cin,forgetnick);
        if(forgetnick == nickname)
        {
            cout << "Enter your new Password: ";
            getline(cin,password);
            cout << "Password reset Successful....." <<endl;
        }
        else
        {
            cout << "Wrong Nickname!!! Try Again!!!" << endl;
            goto forgetnickname;
        }
    }
};
///***************************************Grocery Class************************************************
class Grocery
{
    int GroceryIndex = 15;
    int GroceryID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int GroceryPrice[15] = {120,80,110,95,40,91,113,235,45,39,159,230,795,122,148};
    string GroceryItems[100] = { "Eggs       ",
                                 "Sugar       ",
                                 "Oil        ",
                                 "Milk       ",
                                 "Bread       ",
                                 "Rice        ",
                                 "Rice(basmati)",
                                 "Chicken      ",
                                 "Salt         ",
                                 "Chili Powder ",
                                 "Peanut Butter ",
                                 "Fish Mixed   ",
                                 "Beef        ",
                                 "Cheese      ",
                                 "Yogurt       ",
                               };
    string GroceryQuantity[100] = { "4 pcs",
                                    "1 kg",
                                    "1 litre",
                                    "1 litre",
                                    "1 pcs",
                                    "1 kg",
                                    "1 kg",
                                    "1 kg",
                                    "1 kg",
                                    "1 kg",
                                    "1 kg",
                                    "1 kg",
                                    "1 kg",
                                    "1 kg",
                                    "1 kg ",
                                  };
public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "ProductID     Name               Price        Quantity" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < GroceryIndex; ++i)
        {
            cout << "  " << GroceryID[i];
            cout << "\t     " << GroceryItems[i] ;
            cout << "\t" << GroceryPrice[i] << " Taka ";
            cout << "\t" << GroceryQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};
///****************************************Medicine Class********************************************
class Medicine
{
    int MedicineIndex = 15;
    string MedicineItems[100] = {"Napa        ",
                                 "Flexi        ",
                                 "Tylace       ",
                                 "Colimex      ",
                                 "Riscord      ",
                                 "Esgipyrin    ",
                                 "Vancomycin    ",
                                 "Histacin     ",
                                 "Alvin        ",
                                 "Filmet       ",
                                 "Antacid      ",
                                 "Xorel        ",
                                 "Omidon       ",
                                 "Diapro       ",
                                 "Sinamin      "
                                };

    int MedicineID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int MedicinePrice[15] = {30,13,45,15,14,10,10,11,13,12,17,13,14,12,15};

    string MedicineQuantity[15] = {"4 pcs",
                                   "4 pcs",
                                   "1 pcs ",
                                   "4 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "2 pcs ",
                                   "1 pcs",
                                   "1 pcs ",
                                   "3 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",

                                  };

public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "ProductID     Name               Price        Quantity" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < MedicineIndex; ++i)
        {
            cout << "  " << MedicineID[i];
            cout << "\t     " << MedicineItems[i] ;
            cout << "\t" << MedicinePrice[i] << " Taka ";
            cout << "\t" << MedicineQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};
///***************************************Toys Class************************************************
class Toys
{
    int KidsToysIndex = 15;
    string KidsToysItems[100] = { "Teddy Bear         ",
                                  "Rocking dog       ",
                                  "Toy Car          ",
                                  "Tennis Ball      ",
                                  "Toy Train        ",
                                  "Basketball       ",
                                  "Kite             ",
                                  "Rubik'sCube      ",
                                  "Tricycle         ",
                                  "Crayons         ",
                                  "Dice           ",
                                  "Dominoes       ",
                                  "Airplane         ",
                                  "Robot           ",
                                  "Bicycle         "
                                };
    int KidsToysID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int KidsToysPrice[15] = {1330,2113,2345,254,2314,1410,1630,1011,1033,1050,1715,1313,1452,1953,10000};
    string KidsToysQuantity[15] = {"1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs",
                                   "1 pcs"
                                  };
public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "ProductID     Name               Price        Quantity" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < KidsToysIndex; ++i)
        {
            cout << "  " << KidsToysID[i];
            cout << "\t    " << KidsToysItems[i] ;
            cout << "\t" << KidsToysPrice[i] << " Taka ";
            cout << "\t" << KidsToysQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};
///******************************************Jewelry class*************************************************
class Jewelry
{
    int JewelryItemsIndex = 15;
    string JewelryItems[15] = {"Brooches      ",
                               "Rings        ",
                               "Necklaces    ",
                               "Earrings    ",
                               "Pendants    ",
                               "Cuff-links    ",
                               "Nose pin     ",
                               "Bracelet     ",
                               "Chain       ",
                               "Hairpin     ",
                               "Beads       ",
                               "Anklet      ",
                               "Watch         ",
                               "Crown         ",
                               "Choker        "
                              };

    int JewelryItemsID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int JewelryItemsPrice[15] = {330,300,1000,900,515,100,910,573,733,850,754,356,1458,1521,522};
    string JewelryItemsQuantity[15] = {"1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs",
                                       "1 pcs"
                                      };

public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "ProductID     Name               Price        Quantity" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < JewelryItemsIndex; ++i)
        {
            cout << "  " << JewelryItemsID[i];
            cout << "\t    " << JewelryItems[i] ;
            cout << "\t" << JewelryItemsPrice[i] << " Taka ";
            cout << "\t" << JewelryItemsQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};
///*******************************************Cloths Class***************************************************
class Cloths
{
    int ClothsIndex = 15;
    string ClothsItems[100] = {"Saree        ",
                               "Shirt        ",
                               "Pant        ",
                               "Abaya       ",
                               "Hijab       ",
                               "Three-piece   ",
                               "Panjabi    ",
                               "Skirt and tops ",
                               "Nikab         ",
                               "Gown        ",
                               "Sweater      ",
                               "Scarf (Muffler) ",
                               "Coat        ",
                               "Orna        ",
                               "Socks      "
                              };

    int ClothsID[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int ClothsPrice[15] = {1500,1000,1700,2100,600,1400,1800,1200,400,2500,2600,200,2700,900,150};

    string ClothsQuantity[15] = {"1 pcs",
                                 "1 pcs",
                                 "1 pcs ",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs ",
                                 "1 pcs",
                                 "1 pcs ",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",
                                 "1 pcs",

                                };
public:
    void displayProducts()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "ProductID     Name               Price        Quantity" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for(int i = 0; i < ClothsIndex; ++i)
        {
            cout << "  " << ClothsID[i];
            cout << "\t     " << ClothsItems[i] ;
            cout << "\t" << ClothsPrice[i] << " Taka ";
            cout << "\t" << ClothsQuantity[i] << endl;
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};
///********************************************Cart Class****************************************************
class cart
{
    int id;
    string name;
    double price;
    int quantity;

public:
    void addcart(double c, int d)
    {
        /// No need to store id and name here
        price = c * d;
        quantity = d;
        calculateTotal();
    }

    void calculateTotal()
    {
        totalPrice += price;
        cout <<"\nCurrent total is " << totalPrice << " " << "taka" << endl;
        cout << "***************************"<< endl;
    }
};
///********************Program written by Md. Sultan Mahmud Munna************************************
///Main Function starts hereeeeeeee So many lines that I can't fine sometimes haha.So I wrote this big sentence
int main()
{
    ///Object Create
    user User;
    cart product;
    shop Shop;
    Grocery gro;
    Medicine medi;
    Toys toy;
    Jewelry jew;
    Cloths cloth;
    ///Some Variable Declaration
    int i = totalproducts;
    int choice2;
    double ProPrice = 0;
    int option = 0, choice, quantity;
    ///*********************************MAIN MENU***************************************************
mainmenu:
    cout << "\n\t\t\t     Welcome to EazyMart!!!" << endl;
    cout << "\t\t\t  What would you like to buy?" << endl << endl;
    cout << "1. Grocery Items" << endl;
    cout << "2. Medicine Items" << endl;
    cout << "3. Toy Items" << endl;
    cout << "4. Jewelry Items" << endl;
    cout << "5. Cloths Items" << endl;
    cout << "6. My Account and Balance" << endl;
    cout << "7. Show All Products" << endl;
    cout << "8. Show my carted Products and Checkout" << endl << endl;

    cout << "Enter an option: ";
    cin >> option;
    cin.ignore();
///*******************************************Product Choice***************************************
    switch (option)
    {
    case 1:
    {
groc:
        cout << "\n\n\t\t\tChoose Your Grocery Item" << endl;
        gro.displayProducts();
        for(i = totalproducts; i< 100; i++)
        {
choiceGrocery:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (choice)
            {
///*******************************************Grocery choice***************************************
            case 1:
            {
                ProPrice = 120;
                Shop.Carted("Eggs       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 2:
            {
                ProPrice = 80;
                Shop.Carted("Sugar       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 3:
            {
                ProPrice = 110;
                Shop.Carted("Oil        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 4:
            {
                ProPrice = 95;
                Shop.Carted("Milk       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 5:
            {
                ProPrice = 40;
                Shop.Carted("Bread       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 6:
            {
                ProPrice = 91;
                Shop.Carted("Rice        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 7:
            {
                ProPrice = 113;
                Shop.Carted("Rice(basmati) ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 8:
            {
                ProPrice = 235;
                Shop.Carted("Chicken      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 9:
            {
                ProPrice = 45;
                Shop.Carted("Salt         ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 10:
            {
                ProPrice = 39;
                Shop.Carted("Chili Powder ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 11:
            {
                ProPrice = 159;
                Shop.Carted("Peanut Butter ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 12:
            {
                ProPrice = 230;
                Shop.Carted("Fish Mixed   ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 13:
            {
                ProPrice = 795;
                Shop.Carted("Beef        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 14:
            {
                ProPrice = 122;
                Shop.Carted("Cheese      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 15:
            {
                ProPrice = 148;
                Shop.Carted("Yogurt       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
            }
            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Grocery store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto groc;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choiceGrocery;
            }
        }
    }
    break;
///**************************************Medicine Choice********************************************
    case 2:
    {
medic:
        cout << "\n\n\t\t\tChoose Your Medicine Item" << endl;
        medi.displayProducts();
        for(i = 0; i< 100; i++)
        {
choicemedi:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (choice)
            {
            case 1:
            {
                ProPrice = 30;
                Shop.Carted("Napa       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 2:
            {
                ProPrice = 13;
                Shop.Carted("Fexo       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 3:
            {
                ProPrice = 45;
                Shop.Carted("Tylace        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 4:
            {
                ProPrice = 15;
                Shop.Carted("Colimex       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 5:
            {
                ProPrice = 14;
                Shop.Carted("Riscord       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 6:
            {
                ProPrice = 10;
                Shop.Carted("Esgipyrin        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 7:
            {
                ProPrice = 10;
                Shop.Carted("Vancomycin ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 8:
            {
                ProPrice = 11;
                Shop.Carted("Histacin      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 9:
            {
                ProPrice = 13;
                Shop.Carted("Alvin         ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 10:
            {
                ProPrice = 12;
                Shop.Carted("Filmet        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 11:
            {
                ProPrice = 17;
                Shop.Carted("Antacid     ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 12:
            {
                ProPrice = 13;
                Shop.Carted("Xorel        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 13:
            {
                ProPrice = 14;
                Shop.Carted("Omidon          ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 14:
            {
                ProPrice = 12;
                Shop.Carted("Diapro       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 15:
            {
                ProPrice = 15;
                Shop.Carted("Sinamin       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
            }
            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Medicine store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto medic;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choicemedi;
            }
        }


    }
    break;
///**************************************Toys Choice***************************************************
    case 3:
    {
toyss:
        cout << "\n\n\t\t\tChoose Your Toys Item" << endl;
        toy.displayProducts();
        for(i = 0; i< 100; i++)
        {
choicetoys:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (choice)
            {
            case 1:
            {
                ProPrice = 1330;
                Shop.Carted("Teddy Bear     ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 2:
            {
                ProPrice = 2113;
                Shop.Carted("Rocking dog      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 3:
            {
                ProPrice = 2345;
                Shop.Carted("Toy Car      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 4:
            {
                ProPrice = 254;
                Shop.Carted("Tennis Ball     ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 5:
            {
                ProPrice = 2314;
                Shop.Carted("Toy Train      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 6:
            {
                ProPrice = 1410;
                Shop.Carted("Basketball        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 7:
            {
                ProPrice = 1630;
                Shop.Carted("Kite        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 8:
            {
                ProPrice = 1011;
                Shop.Carted("Rubik'sCube      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 9:
            {
                ProPrice = 1033;
                Shop.Carted("Tricycle       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 10:
            {
                ProPrice = 1050;
                Shop.Carted("Crayons        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 11:
            {
                ProPrice = 1715;
                Shop.Carted("Dice          ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 12:
            {
                ProPrice = 1313;
                Shop.Carted("Dominoes        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 13:
            {
                ProPrice = 1452;
                Shop.Carted("Airplane        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 14:
            {
                ProPrice = 1953;
                Shop.Carted("Robot       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 15:
            {
                ProPrice = 10000;
                Shop.Carted("Bicycle       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
            }
            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Toys store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto toyss;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choicetoys;
            }
        }


    }
    break;
///****************************************Jewelry Choice********************************************
    case 4:
    {

Jewelrys:
        cout << "\n\n\t\t\tChoose Your Jewelry Item" << endl;
        jew.displayProducts();
        for(i = 0; i< 100; i++)
        {
choiceJewelry:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (choice)
            {
            case 1:
            {
                ProPrice = 330;
                Shop.Carted("Brooches       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 2:
            {
                ProPrice = 300;
                Shop.Carted("Rings       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 3:
            {
                ProPrice = 1000;
                Shop.Carted("Necklaces       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 4:
            {
                ProPrice = 900;
                Shop.Carted("Earrings      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 5:
            {
                ProPrice = 515;
                Shop.Carted("Pendants       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 6:
            {
                ProPrice = 100;
                Shop.Carted("Cuff-links        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 7:
            {
                ProPrice = 910;
                Shop.Carted("Nose pin        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 8:
            {
                ProPrice = 573;
                Shop.Carted("Bracelet       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 9:
            {
                ProPrice = 733;
                Shop.Carted("Chain        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 10:
            {
                ProPrice = 850;
                Shop.Carted("Hairpin        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 11:
            {
                ProPrice = 754;
                Shop.Carted("Beads       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 12:
            {
                ProPrice = 356;
                Shop.Carted("Anklet         ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 13:
            {
                ProPrice = 1458;
                Shop.Carted("Watch          ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 14:
            {
                ProPrice = 1521;
                Shop.Carted("Crown         ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 15:
            {
                ProPrice = 522;
                Shop.Carted("Choker         ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
            }
            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Jewelry store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto Jewelrys;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choiceJewelry;
            }
        }

    }
    break;
///*********************************************Cloths Selection*********************************************
    case 5:
    {

Clothsc:
        cout << "\n\n\t\t\tChoose Your Cloths Item" << endl;
        cloth.displayProducts();
        for(i = 0; i< 100; i++)
        {
choiceCloths:
            cout << "Enter a Product ID: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

            switch (choice)
            {
            case 1:
            {
                ProPrice = 1500;
                Shop.Carted("Saree       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 2:
            {
                ProPrice = 1000;
                Shop.Carted("Shirt       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 3:
            {
                ProPrice = 1700;
                Shop.Carted("Pant       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 4:
            {
                ProPrice = 2100;
                Shop.Carted("Abaya      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 5:
            {
                ProPrice = 600;
                Shop.Carted("Hijab       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 6:
            {
                ProPrice = 1400;
                Shop.Carted("Three-piece    ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 7:
            {
                ProPrice = 1800;
                Shop.Carted("Panjabi      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 8:
            {
                ProPrice = 1200;
                Shop.Carted("Skirt and tops ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 9:
            {
                ProPrice = 400;
                Shop.Carted("Nikab         ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 10:
            {
                ProPrice = 2500;
                Shop.Carted("Gown        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 11:
            {
                ProPrice = 2600;
                Shop.Carted("Sweater      ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 12:
            {
                ProPrice = 200;
                Shop.Carted("Scarf (Muffler) ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 13:
            {
                ProPrice = 2700;
                Shop.Carted("Coat        ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 14:
            {
                ProPrice = 900;
                Shop.Carted("Orna         ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            case 15:
            {
                ProPrice = 150;
                Shop.Carted("Socks       ", quantity, ProPrice * quantity);
                product.addcart(ProPrice, quantity);
                totalproducts += 1;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
            }
            cout << "\nDo you want to buy more ?" <<endl;
            cout << "Press 1 to return to Cloths store , (0 to return to Main Menu)" << endl;
            cin >> choice2;
            if(choice2 == 1)
                goto Clothsc;
            else if(choice2 == 0)
                goto mainmenu;
            else
            {
                cout << "Invalid Option!!!" << endl << endl;
                goto choiceCloths;
            }
        }




    }
    break;
    ///For user menu
    case 6:
    {
        int userchoice;
userchoiced:
        cout << endl << "1. Check Balance " << endl;
        cout << "2. Add More Balance " << endl;
        cout << "3. Show my all data " << endl;
        cout << "4. Reset password " << endl;
        cout << "5. Return to Main Menu " << endl;
        cin >> userchoice;
        cin.ignore();
        if(userchoice == 1)
            User.showbalance();
        else if(userchoice == 2)
            User.addbalance();
        else if(userchoice == 3)
            User.displayuserdata();
        else if(userchoice == 4)
            User.forgetpass();
        else if(userchoice == 5)
            goto mainmenu;
        else
        {
            cout << "Invalid Choice!!!" << endl;
            goto userchoiced;
        }
        goto mainmenu;
    }
    break;
    ///For showing all products
    case 7:
    {
        cout << "\n\n\t\tGrocery Items" << endl;
        gro.displayProducts();
        cout << "\n\n\t\tMedicine Items" << endl;
        medi.displayProducts();
        cout << "\n\n\t\tToys Items" << endl;
        toy.displayProducts();
        cout << "\n\n\t\tJewelry Items" << endl;
        jew.displayProducts();
        cout << "\n\n\t\tCloths Items" << endl;
        cloth.displayProducts();
        goto mainmenu;
    }
    break;
    case 8:
    {
        ///For checkout and display cart
        Shop.displayCart();
        User.checkout();
        if(User.returns == false)
            goto mainmenu;
        else
            exit(0);
    }
    break;
    }

    ///End Of Program

    return 0;
}






