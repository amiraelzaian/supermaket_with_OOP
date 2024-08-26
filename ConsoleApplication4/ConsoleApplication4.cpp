#include <vector>
#include <iostream>
using namespace std;

/// class Product
class Product {
protected:
    vector<string> names;
    vector<float> prices;
    vector<int> productionDates;
    vector<int> expiryDates;

public:
    // the constructor
    Product(vector<string> names = {}, vector<float> prices = {}, vector<int> prodDates = {}, vector<int> expDates = {})
        : names(names), prices(prices), productionDates(prodDates), expiryDates(expDates) {}
    // getters
    vector<string> getproductName() { return names; }
    vector<float> getPrices() { return prices; }
    vector<int> getProductionDates() { return productionDates; }
    vector<int> getExpiryDates() { return expiryDates; }
    void printMenu();
    float getPrice(int index);
    string getName(int index);
    // function to add new items
    void addItems(string name, float price, int prodcdate, int expdate)
    {
        names.emplace_back(name);
        prices.emplace_back(price);
        productionDates.emplace_back(prodcdate);
        expiryDates.emplace_back(expdate);
    }


};

/// member fucntion
void Product::printMenu() {
    cout << "\n--------- The Menu ---------\n";
    for (size_t i = 0; i < names.size(); ++i) {
        cout << i + 1 << ". " << names[i] << " - $" << prices[i]
            << " || Production date: " << productionDates[i]
            << " _ Expiry date: " << expiryDates[i] << endl;
    }
    cout << "----------------------------\n";
}

float Product::getPrice(int index) {
    if (index >= 0 && index < prices.size()) {
        return prices[index];
    }
    return 0.0f;
}

string Product::getName(int index) {
    if (index >= 0 && index < names.size()) {
        return names[index];
    }
    return "Unknown";
}

/// fucntions uses Product class
void select_product(Product& product, vector<int>& cart)
{
    int choice;
    while (true)
    {
        cout << " => Please, Enter your choice number (0 to finish shopping ):" << endl;
        cin >> choice;
        if (choice == 0) break;

        if (choice > 0 && choice <= product.getproductName().size())
        {
            cart.push_back(choice - 1);
        }
        else {
            cout << "Invalid choice. Please try again ^ ^\n";
        }
    }
}

void print_bill(Product& product, vector<int>& cart) {
    cout << "\n'''''''''' YOUR CART ''''''''''\n";
    for (int p : cart) {
        cout << product.getName(p) << " - " << product.getPrice(p) << " L.E" << endl;
    }
    cout << "'''''''''''''''''''''''''''''''\n";
}

void count_bill(Product& product, vector<int>& cart) {
    float bill = 0;
    for (int item : cart) {
        bill += product.getPrice(item);
    }
    if (bill < 500)
    {
        cout << " => Your discount is: 0%" << endl;
        cout << " => The money required to be paid: " << bill << endl;
    }
    else
    {
        cout << " => Your discount is: 7%" << endl;
        cout << " => The money required to be paid: " << (0.93 * bill) << endl;
    }
    cout << "'''''''''''''''''''''''''''''''\n";
}

/// //////////////////////////////////////////////////////////////////////////////////////////////
 
/// the parent
class Person
{
protected:
    string name, gender;
    int id;
public:
    Person(string name = "unknown", string gender = "unknown", int id = 0)
        : name(name), gender(gender), id(id) {}

    // Getters
    string getName() { return name; }
    string getGender() { return gender; }
    int getId() { return id; }
    // setters
    void set_name()
    {
        cout << "enter your name :" << endl;
        string Name;
        cin >> Name;  
    }
    void set_gender()
    {
        cout << "enter your gender :" << endl;
        string Gender; cin >> Gender;
    }
    void set_id()
    {
        cout << "enter your id :" << endl;
        int ID; cin >> ID;
    }

};
/// Manager class
class Manager : public Person
{
private:
    string email, password;
    int age;
public:
    // Parameterized constructor
    Manager(string n = "unknown", string g = "unknown", int ID = 0,
        int a = 0, string em = "unknown", string pass = "unknown")
        : Person(n, g, ID), email(em), password(pass), age(a) {}

    // Getters
    string getEmail() { return email; }
    string getPassword() { return password; }
    int getAge() { return age; }
    
    // setters
    void set_password()
    {
        cout << " Enter the new password : " << endl;
        string pass;
        cin >> pass;
    }
    void set_email()
    {
        cout << " Enter the new email : " << endl;
        string em; 
        cin >> em;
    }
    void set_age()
    {
        cout << "enter your age :" << endl;
        int Age; 
        cin >> Age;
    }
};
/// Consumer class
class Consumer : public Person
{
private:
    string phoneNumber;
public:
    // Parameterized constructor
    Consumer(string n = "unknown", string g = "unknown", int ID = 0, string phone = "unknown")
        : Person(n, g, ID), phoneNumber(phone) {}

    // Getters
    string getPhoneNumber()  { return phoneNumber; }
   // setters
    void set_phonenumber()
    {
        cout << "Enter your phonenumber:";
        string ph;
        cin >> ph;
    }


};


void main_func()
{
    vector<string> products{ "apple", "banana", "mango", "potato", "beef", "fish", "rice", "pasta", "salt", "water", "milk" };
    vector<float> prices{ 45.5, 25.99, 25.99, 30.99, 400.99, 66.78, 30.99, 30.99, 10.5, 15.00, 40.99 };
    vector<int> productionYear{ 2023, 2022, 2023, 2024, 2024, 2024, 2024, 2024, 2024, 2023, 2024 };
    vector<int> expiryYear{ 2025, 2025, 2026, 2025, 2026, 2025, 2026, 2025, 2026, 2025, 2024 };

    Product myProduct(products, prices, productionYear, expiryYear);
    vector<int> cart;
    Consumer consumer;
    Manager manager;
    int entry_choice;
    string old_username = "amira", old_email = "amira23204@gmail.com", old_pass = "232045";
    string new_pass, new_email, new_username;
    int menu_choice;

    cout << "\n\n\t\t\t'''''''''''''''''''''''''''''''''''''''''''''''''''\n";
    cout << "\t\t\t'''''''''''''''' AMIRA SUPERMARKET ''''''''''''''''\n";
    cout << "\t\t\t'''''''''''''''''''''''''''''''''''''''''''''''''''\n";
    there:
    cout << " Hello, How can I help you?" << endl;
    cout<<" Are you a -1- manager or a -2- consumer, enter your choice number!!"<< endl;
    int choice;
    
    
        cin >> choice;
        switch(choice)
        {
        case 2:
            newpurchase:
            cout << "\n => Dear Consumer, if you can fill some details enter to( 1 ) key" << endl;
            cout << "IF you don't wnat enter any other number (don't enter any character! ) ^ ^" << endl;
            int choosen_num;
            cin >> choosen_num;
            if (choosen_num == 1)
            {
                consumer.set_name();
                consumer.set_id();
                consumer.set_gender();
                consumer.set_phonenumber();
                goto consumerPart;
            }
            else
            {    consumerPart:
                myProduct.printMenu();
                select_product(myProduct, cart);
                thisplace:
                cout << " => Are you want to complete the purchase process" << endl;
                cout << " => enter ( 1 ) to cmplete:" << endl;
                cout << " => enter ( 2 ) to print the bill: " << endl;
                // to enter a choice to complete the choice
                int purchase_choice;
                cin >> purchase_choice;
                if (purchase_choice == 1)
                {   
                    select_product(myProduct, cart);
                    print_bill(myProduct, cart);
                    count_bill(myProduct, cart);
                }
                else if (purchase_choice == 2)
                {
                    print_bill(myProduct, cart);
                    count_bill(myProduct, cart);
                }
                else
                {
                    cout << " => alert!!!! enter a valid number " << endl;
                    goto thisplace;
                }
            }
            ////////////////////////////////
            refillTHEchoice:
            cout << "\n Enter ( 1 ) to new purchase prosses ^ ^ :" << endl
                << " Enter ( 2 ) to go to the main page ^ ^ :" << endl
                << " Enter ( 3 ) to exit '(" << endl;
            int choose;
            cin >> choose;
            if (choose == 1)
            {
                cart.clear();
                goto newpurchase;
            }
            else if (choose == 2)
            {
                main_func();
            }
            else if (choose == 3)
            {
                cout << "\n => SEE YOU SOON, SIR ^ ^" << endl;
                cout << " with my bestwishes: amira ^ ^" << endl;
                cout << "\n''''''''''''''''''''''''''''''''" << endl;
                break;
            }
            else
            {
                cout << " => alert!!! , Invalid choice !!" << endl;
                goto refillTHEchoice;
            }



            break;
        case 1:
          // the manager part:
            cout << "\n''''''''''''''''''''''''" << endl;
            cout << " enter (-1-) to sign in, enter (-2-) to sign up :" << endl;
            cin >> entry_choice;
            // validation about account information
            if (entry_choice == 1)
            {
                cout << "enter user name :"; cin >> new_username; 
                cout << "\n enter password :"; cin >> new_pass;
                cout << "\n enter email: "; cin >> new_email;
                if (new_username == old_username && new_email == old_email && new_pass == old_pass)
                    cout << "\n ^ ^ OK, HELLO MANAGER, CAN I HELP YOU ?\n " << endl;
                else
                {
                    cout << " Invalid information, Please sign up:";
                      manager.set_name();
                      manager.set_id();
                      manager.set_gender();
                      manager.set_email();
                      manager.set_password();
                      manager.set_age();
                }
            }
            else
            {
                manager.set_name();
                manager.set_id();
                manager.set_gender();
                manager.set_email();
                manager.set_password();
                manager.set_age();
            }
            cout << "''''''''''''''''''''''''''''''" << endl;
            cout << " =>  Enter (-1-) to edit the Menue ( add items ):" << endl;
            cout << " =>  Enter (-2-) to veiw the menu :" << endl;
            cout << "''''''''''''''''''''''''''''''" << endl;
            cin >> menu_choice;
            if (menu_choice == 1)
            {
                cout << "enter number of items, you want to add" << endl;
                int elements_added;  cin >> elements_added;
                for (int i = 0; i < elements_added; i++)
                {
                    cout << " - enter the " << i + 1 << "th item  name :" << endl;
                    string name;  
                    cin >> name;
                    cout << " - enter the " << i + 1 << "th item  price :" << endl;
                    float price; 
                    cin >> price;
                    cout << " - enter the " << i + 1 << "th item  production date :" << endl;
                    int prod; 
                    cin >> prod;
                    cout << " - enter the " << i + 1 << "th item  exp date :" << endl;
                    int exp;
                    cin >> exp;
                    myProduct.addItems(name, price, prod, exp);
                }
                cout << "\n''''''''''''''''''''''''''''''''''";
                myProduct.printMenu();
            }
            else
            {
                myProduct.printMenu();
            }
            here:
            cout << "\n''''''''''''''''''''''''''''''''''" << endl;
            cout << " Enter -1- to exit: " << endl;
            cout << " Enter -2- to go to the main page: " << endl;
            int exit_choice;
            cin >> exit_choice;
            if (exit_choice == 1)
            {
                cout << "\n => SEE YOU SOON, SIR ^ ^" << endl;
                cout << " with my bestwishes: amira ^ ^" << endl;
                cout << "\n''''''''''''''''''''''''''''''''" << endl;
                break;
            }
            else if (exit_choice == 2)
            {
                goto there;
            }
            else
            {
                cout << " => alert !!! Invalid number" << endl;
                goto here;
            }
            
            break;
        default:
            cout << "Invalid choice! Please enter 1 for Manager or 2 for Consumer." << endl;
            goto there;
        }
}

int main() 
{
    main_func();
    return 0;
}
