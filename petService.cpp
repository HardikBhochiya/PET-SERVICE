#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
using namespace std;

string valid_password()
{
    string password;
    while (true)
    {
        cin >> password;
        int size = password.size();
        if (size < 8)
        {
            cout << endl
                 << "Password must contain minimum 8 digits with atleast one lowercase, one uppercase and one digit." << endl
                 << endl
                 << "Enter valid password : " << endl;
            continue;
        }
        bool flag = false;
        for (char c : password)
            if (islower(c))
            {
                flag = true;
                break;
            }
        if (!flag)
        {
            cout << endl
                 << "Password must contain minimum 8 digits with atleast one lowercase, one uppercase and one digit." << endl
                 << endl
                 << "Enter valid password : " << endl;
            continue;
        }
        flag = false;
        for (char c : password)
            if (isupper(c))
            {
                flag = true;
                break;
            }
        if (!flag)
        {
            cout << endl
                 << "Password must contain minimum 8 digits with atleast one lowercase, one uppercase and one digit." << endl
                 << endl
                 << "Enter valid password : " << endl;
            continue;
        }
        flag = false;
        for (char c : password)
            if (isdigit(c))
            {
                flag = true;
                break;
            }
        if (!flag)
        {
            cout << endl
                 << "Password must contain minimum 8 digits with atleast one lowercase, one uppercase and one digit." << endl
                 << endl
                 << "Enter valid password : " << endl;
            continue;
        }
        break;
    }
    return password;
}
string valid_phonenumber()
{
    string phonenumber;
    while (true)
    {
        cin >> phonenumber;
        int size = phonenumber.size();
        if (size != 10)
        {
            cout << endl
                 << "Enter valid 10 digit phone number : ";
            continue;
        }
        bool flag = false;
        for (char c : phonenumber)
            if (!isdigit(c))
            {
                flag = true;
                break;
            }
        if (flag)
        {
            cout << endl
                 << "Enter valid 10 digit phone number : ";
            continue;
        }
        return phonenumber;
    }
}
string valid_email()
{
    string email;
    while (true)
    {
        cin.ignore();
        getline(cin, email);

        int count = 0;
        int index = -1;
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@')
            {
                count++;
                index = i;
            }
        }
        if (count != 1 || email[0] == '@')
        {
            cout << endl
                 << "Enter valid Email : ";
            continue;
        }

        bool flag = false;
        for (int i = 0; i < index; i++)
        {
            if (!(isalpha(email[i]) || isdigit(email[i]) || email[i] == '.' || email[i] == '+' || email[i] == '_' || email[i] == '-'))
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << endl
                 << "Enter valid Email : ";
            continue;
        }

        for (int i = index + 1; i < email.length(); i++)
        {
            if (email[i] == '.')
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << endl
                 << "Enter valid Email : ";
            continue;
        }
        return email;
    }
}

class Item
{
    const string name;
    const int price;
    int quantity;

public:
    Item(string name, int price) : name(name), price(price), quantity(0) {}

    string get_name() const { return name; }
    int get_price() const { return price; }
    int get_quantity() const { return quantity; }

    void add_quantity(int n) { quantity += n; }
    void reset_quantity() { quantity = 0; }
};

class Customer
{
    string name;
    const string username;
    string password;
    string phonenumber;
    string email;
    const int customer_id;

    vector<Item> pet_store_items = {
        Item("Dog", 2000),
        Item("Cow", 50000),
        Item("Buffalo", 70000),
        Item("Hen", 900),
        Item("Goat", 8000)};
    vector<Item> pet_service_items = {
        Item("Cleaning", 500),
        Item("Medical", 1000),
        Item("Food", 500),
        Item("Training", 2000)};

    static int customer_no;

public:
    Customer(string name, string username, string password, string phonenumber, string email) : username(username), customer_id(customer_no + 2111)
    {
        this->name = name;
        this->password = password;
        this->phonenumber = phonenumber;
        this->email = email;
        customer_no++;
    }

    string get_username() const { return username; }
    string get_name() const { return name; }
    string get_password() const { return password; }
    string get_phonenumber() const { return phonenumber; }
    string get_email() const { return email; }
    int get_id() const { return customer_id; }

    void set_name(string name) { this->name = name; }
    void set_password(string password) { this->password = password; }
    void set_phonenumber(string phonenumber) { this->phonenumber = phonenumber; }
    void set_email(string email) { this->email = email; }

    string get_pet_store_item_name(int n) const { return pet_store_items[n].get_name(); }
    int get_pet_store_item_price(int n) const { return pet_store_items[n].get_price(); }
    int get_pet_store_item_quantity(int n) const { return pet_store_items[n].get_quantity(); }
    void set_pet_store_item_quantity(int index, int n) { pet_store_items[index].add_quantity(n); }
    void set_pet_store_item_quantity(int index) { pet_store_items[index].reset_quantity(); }

    string get_pet_service_item_name(int n) const { return pet_service_items[n].get_name(); }
    int get_pet_service_item_price(int n) const { return pet_service_items[n].get_price(); }
    int get_pet_service_item_quantity(int n) const { return pet_service_items[n].get_quantity(); }
    void set_pet_service_item_quantity(int index, int n) { pet_service_items[index].add_quantity(n); }
    void set_pet_service_item_quantity(int index) { pet_service_items[index].reset_quantity(); }
};
int Customer ::customer_no = 1;

vector<Customer> v;

inline void message(const string &s)
{
    cout << endl
         << s << endl;
}

int login_page()
{
    string choice;
    cout << "1. Sign Up" << endl
         << "2. Sign in" << endl
         << "3. Exit" << endl;
    while (true)
    {
        cout << endl
             << "Please select an option (1-3) : ";
        cin >> choice;
        if (choice == "1")
        {
            system("CLS");
            return 1;
        }
        else if (choice == "2")
        {
            system("CLS");
            return 2;
        }
        else if (choice == "3")
        {
            system("CLS");
            return 3;
        }
        else
        {
            message("Invalid input. Please select a valid option.");
        }
    }
    system("CLS");
}

void new_customer()
{
    system("CLS");
    string name;
    string username;
    string password;
    string re_password;
    string phonenumber;
    string email;

    cout << endl
         << "Enter your name : ";
    cin.ignore();
    getline(cin, name);

    bool check = false;
    do
    {
        cout << endl
             << "Enter username : ";
        cin >> username;
        for (Customer &t : v)
        {
            if (username == t.get_username())
            {
                message("This username already exists. Please try a different one.");
                check = true;
                break;
            }
            else
            {
                check = false;
            }
        }
    } while (check);

    while (true)
    {
        cout << endl
             << "Enter password : ";
        password = valid_password();
        cout << "Confirm password : ";
        cin >> re_password;
        if (password != re_password)
        {
            message("Passwords do not match. Please try again.");
            continue;
        }
        else
        {
            break;
        }
    }

    cout << endl
         << "Enter phonenumber : ";
    phonenumber = valid_phonenumber();

    cout << endl
         << "Enter email : ";
    email = valid_email();

    v.push_back(Customer(name, username, password, phonenumber, email));

    system("CLS");

    message("Registration successful! You can now sign in.");
    cout << endl;
}

Customer *login()
{
    string username, password;
    string choice;
    while (true)
    {
        system("CLS");
        cout << endl
             << "Enter username : ";
        cin >> username;
        bool check = true;
        for (Customer &t : v)
        {
            if (t.get_username() == username)
            {
                cout << endl
                     << "Enter password : ";
                cin >> password;
                if (t.get_password() == password)
                {
                    system("CLS");
                    message("Login successful! Welcome back.");
                    return &t;
                }
                check = false;
                break;
            }
        }
        if (check)
        {
            message("Username not found. Please sign up or try again.");
        }
        else
        {
            message("Incorrect password. Please try again.");
        }
        cout << endl
             << "1. Sign in" << endl
             << "2. Back" << endl;
        while (true)
        {
            cout << endl
                 << "Select an option (1-2): ";
            cin >> choice;
            if (choice == "1")
            {
                break;
            }
            else if (choice == "2")
            {
                system("CLS");
                return nullptr;
            }
            else if (choice != "1")
            {
                message("Invalid input. Please select a valid option.");
            }
        }
    }
}

bool positiveInterger(string str)
{
    if (str.empty())
        return false;
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    if (str.length() > 1 && str[0] == '0')
        return false;
    if (str == "0")
        return false;
    return true;
}

void view_cart(Customer *p)
{
    system("CLS");
    cout << left << setw(20) << "Item" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Total" << endl
         << endl;
    int total = 0;
    bool empty = true;

    for (int i = 0; i < 5; i++)
    {
        int qty = p->get_pet_store_item_quantity(i);
        if (qty)
        {
            empty = false;
            int price = p->get_pet_store_item_price(i);
            int t = qty * price;
            total += t;
            cout << setw(20) << p->get_pet_store_item_name(i) << setw(10) << price << setw(10) << qty << setw(10) << t << endl;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int qty = p->get_pet_service_item_quantity(i);
        if (qty)
        {
            empty = false;
            int price = p->get_pet_service_item_price(i);
            int t = qty * price;
            total += t;
            cout << setw(20) << p->get_pet_service_item_name(i) << setw(10) << price << setw(10) << qty << setw(10) << t << endl;
        }
    }
    if (empty)
    {
        message("Your cart is empty.");
    }
    else
    {
        message("Grand Total: Rs. " + to_string(total));
    }

    message("1. Back");
    string choice;
    while (true)
    {
        cout << endl
             << "Select an option (1): ";
        cin >> choice;
        if (choice == "1")
        {
            system("CLS");
            return;
        }
        else
        {
            message("Invalid input. Please select a valid option.");
        }
    }
}

void pet_store(Customer *p)
{
    system("CLS");
    string n;

    cout << endl
         << left << setw(5) << "No." << setw(20) << "Pet Name" << setw(10) << "Price" << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(5) << (i + 1)
             << setw(20) << p->get_pet_store_item_name(i)
             << "Rs. " << p->get_pet_store_item_price(i) << endl;
    }
    cout << setw(5) << 6 << "Back" << endl;
    string choice;
    while (true)
    {
        cout << endl
             << "Select an option (1-6): ";
        cin >> choice;

        int index;
        if (positiveInterger(choice))
        {
            index = stoi(choice) - 1;
            if (index > 5 || index < 0)
            {
                message("Invalid input. Please select a valid option.");
                continue;
            }
        }
        else
        {
            message("Invalid input. Please select a valid option.");
            continue;
        }
        if (index == 5)
        {
            system("CLS");
            return;
        }

        string pet_name = p->get_pet_store_item_name(index);

        cout << "How many " << pet_name << " would you like to buy? : ";
        cin >> n;
        if (positiveInterger(n))
        {
            int num = stoi(n);
            p->set_pet_store_item_quantity(index, num);
            if (num > 1)
            {
                pet_name += "s";
            }
            message(n + " " + pet_name + " has been added to your cart.");
        }
        else
        {
            message("Invalid input. Please enter a valid positive number.");
        }
    }
}

void pet_service(Customer *p)
{
    system("CLS");
    string choice;
    string n;

    cout << endl
         << left << setw(5) << "No." << setw(20) << "Service" << setw(10) << "Price" << endl
         << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << left << setw(5) << (i + 1)
             << setw(20) << p->get_pet_service_item_name(i)
             << "Rs. " << p->get_pet_service_item_price(i) << endl;
    }
    cout << setw(5) << 5 << "Back" << endl;

    while (true)
    {
        cout << endl
             << "Select an option (1-5): ";
        cin >> choice;

        int index;
        if (positiveInterger(choice))
        {
            index = stoi(choice) - 1;
            if (index > 4 || index < 0)
            {
                message("Invalid input. Please select a valid option.");
                continue;
            }
        }
        else
        {
            message("Invalid input. Please select a valid option.");
            continue;
        }
        if (index == 4)
        {
            system("CLS");
            return;
        }

        string pet_service = p->get_pet_service_item_name(index);

        cout << "How many " << pet_service << " would you like to buy? : ";
        cin >> n;
        if (positiveInterger(n))
        {
            int num = stoi(n);
            p->set_pet_service_item_quantity(index, num);
            string verb = (num == 1) ? "has" : "have";
            if (num > 1)
            {
                pet_service += "s";
            }
            message(n + " " + pet_service + " " + verb + " been added to your cart.");
        }
        else
        {
            message("Invalid input. Please enter a valid positive number.");
        }
    }
}

void password_change(Customer *p)
{
    string p1, p2;
    while (true)
    {
        system("CLS");
        cout << endl
             << "Enter current password : ";
        cin >> p1;
        if (p1 == p->get_password())
        {
            cout << endl
                 << "Enter new password : ";
            p1 = valid_password();
            cout << "Confirm new password : ";
            cin >> p2;
            if (p1 == p2)
            {
                p->set_password(p1);
                system("CLS");
                message("Your password has been updated successfully.");
                return;
            }
            else
            {
                message("New password and confirm password not match.");
                cout << endl
                     << "1. Change password" << endl
                     << "2. Back" << endl;
                while (true)
                {
                    cout << endl
                         << "Select an option (1-2): ";
                    string choice;
                    cin >> choice;
                    if (choice == "1")
                    {
                        break;
                    }
                    else if (choice == "2")
                    {
                        system("CLS");
                        return;
                    }
                    else
                    {
                        message("Invalid input. Please select a valid option.");
                    }
                }
            }
        }
        else
        {
            message("The current password you entered is incorrect.");
            cout << endl
                 << "1. Change password" << endl
                 << "2. Back" << endl;
            while (true)
            {
                cout << endl
                     << "Select an option (1-2): ";
                string choice;
                cin >> choice;
                if (choice == "1")
                {
                    break;
                }
                else if (choice == "2")
                {
                    system("CLS");
                    return;
                }
                else
                {
                    message("Invalid input. Please select a valid option.");
                }
            }
        }
    }
}

void edit_profile(Customer *p)
{
    system("CLS");
    string choice;
    while (true)
    {
        cout << endl
             << "1. Change name" << endl
             << "2. Change password" << endl
             << "3. Change phonenumber" << endl
             << "4. Change email" << endl
             << "5. Back" << endl;
        while (true)
        {
            cout << endl
                 << "Select an option (1-5) : ";
            cin >> choice;
            if (choice == "1")
            {
                system("CLS");
                cout << endl
                     << "Enter new name : ";
                string name;
                cin.ignore();
                getline(cin, name);
                p->set_name(name);
                system("CLS");
                message("Your name has been updated successfully.");
                break;
            }
            else if (choice == "2")
            {
                system("CLS");
                password_change(p);
                break;
            }
            else if (choice == "3")
            {
                system("CLS");
                cout << endl
                     << "Enter new phone number : ";
                p->set_phonenumber(valid_phonenumber());
                system("CLS");
                message("Your phone number has been updated successfully.");
                break;
            }
            else if (choice == "4")
            {
                system("CLS");
                cout << endl
                     << "Enter new email: ";
                p->set_email(valid_email());
                system("CLS");
                message("Your email address has been updated successfully.");
                break;
            }
            else if (choice == "5")
            {
                system("CLS");
                return;
            }
            else
            {
                message("Invalid input. Please select a valid option.");
            }
        }
    }
}

void edit_profile_check(Customer *p)
{
    string temp;
    while (true)
    {
        system("CLS");
        cout << endl
             << "Enter password : ";
        cin >> temp;
        if (temp == p->get_password())
        {
            edit_profile(p);
            return;
        }
        string choice;
        message("The password you entered is incorrect.");
        cout << endl
             << "1. Edit profile" << endl
             << "2. Back" << endl;
        while (true)
        {
            cout << endl
                 << "Select an option (1-2): ";
            cin >> choice;
            if (choice == "1")
            {
                break;
            }
            else if (choice == "2")
            {
                system("CLS");
                return;
            }
            else if (choice != "1")
            {
                message("Invalid input. Please select a valid option.");
            }
        }
    }
}

void bill(Customer *p)
{
    system("CLS");
    cin.ignore();
    cout << left;
    cout << "Name          : " << p->get_name() << endl;
    cout << "Username      : " << p->get_username() << endl;
    cout << "Phone number  : " << p->get_phonenumber() << endl;
    cout << "Email         : " << p->get_email() << endl;
    cout << "Customer id   : " << p->get_id() << endl
         << endl;

    int total = 0;
    cout << setw(20) << "Item" << setw(20) << "Price" << setw(20) << "Quantity" << setw(20) << "Total" << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        int n = p->get_pet_store_item_quantity(i);
        if (n)
        {
            int price = p->get_pet_store_item_price(i);
            int item_total = n * price;
            total += item_total;
            cout << setw(20) << p->get_pet_store_item_name(i) << setw(20) << price << setw(20) << n << setw(20) << item_total << endl
                 << endl;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int n = p->get_pet_service_item_quantity(i);
        if (n)
        {
            int price = p->get_pet_service_item_price(i);
            int item_total = n * price;
            total += item_total;
            cout << setw(20) << p->get_pet_service_item_name(i) << setw(20) << price << setw(20) << n << setw(20) << item_total << endl
                 << endl;
        }
    }
    string choice;
    cout << endl
         << "Grand Total : " << total << endl
         << endl;
    if (total)
    {
        cout << "Would you like to proceed with payment?" << endl
             << "1. Yes and back" << endl
             << "2. No and back" << endl;
        while (true)
        {
            cout << endl
                 << "Select an option (1-2): ";
            cin >> choice;
            if (choice == "1")
            {
                for (int i = 0; i < 5; i++)
                    p->set_pet_store_item_quantity(i);
                for (int i = 0; i < 4; i++)
                    p->set_pet_service_item_quantity(i);
                system("CLS");
                message("Payment completed successfully. Thank you!");
                return;
            }
            else if (choice == "2")
            {
                system("CLS");
                if (total)
                    message("You still have rupees " + to_string(total) + " pending. Please complete your payment later.");
                return;
            }
            else
            {
                message("Invalid input. Please select a valid option.");
            }
        }
    }
    else
    {
        cout << "1. Back" << endl;
        while (true)
        {
            cout << endl
                 << "Select an option (1): ";
            cin >> choice;
            if (choice == "1")
            {
                system("CLS");
                return;
            }
            else
            {
                message("Invalid input. Please select a valid option.");
            }
        }
    }
}

void menu(Customer *p)
{
    string choice;
    while (true)
    {
        cout << endl
             << "1. Pet store" << endl
             << "2. Pet service" << endl
             << "3. Bill" << endl
             << "4. Edit profile" << endl
             << "5. View cart" << endl
             << "6. Logout" << endl;
        while (true)
        {
            cout << endl
                 << "Select an option (1-6): ";
            cin >> choice;
            if (choice == "1")
            {
                pet_store(p);
                break;
            }
            else if (choice == "2")
            {
                pet_service(p);
                break;
            }
            else if (choice == "3")
            {
                bill(p);
                break;
            }
            else if (choice == "4")
            {
                edit_profile_check(p);
                break;
            }
            else if (choice == "5")
            {
                view_cart(p);
                break;
            }
            else if (choice == "6")
            {
                system("CLS");
                message("Logout Successfully...!");
                cout << endl;
                return;
            }
            else
            {
                message("Invalid input. Please select a valid option.");
            }
        }
    }
}

int main()
{
    message("Welcome to Pet Management Service...!");
    cout << endl;
    while (true)
    {
        switch (login_page())
        {
        case 1:
        {
            new_customer();
            break;
        }
        case 2:
        {
            Customer *ptr = login();
            if (ptr)
            {
                menu(ptr);
            }
            break;
        }
        case 3:
        {
            return 0;
        }
        }
    }
}
