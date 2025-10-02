#include <iostream>

using namespace std;

string BookitemsList[50];
string BookCategoryList[50];
string BookAuthorList[50];
bool BookisBorrowedList[50];
int BookIdList[50];
string UsersList[10];
int UserIdList[10];
int UserAgeList[10];
int Indexing = 0;
int UserIndexing = 0;
    string borrowedBooks[50];
string lendedusers[50];
int browed_ID = 0;
string admin_password = "admin123";
bool admin_logged_in = false;
string admin_username = "abcde";




class Library
{
public:
    string Title, Category, Author;
    signed int Book_ID;
    bool isBorrowed = false;
    int browed_count = 0;


    void input()
    {
        cout << "Enter the Book ID: ";
        cin >> Book_ID;
        cin.ignore();
        cout << "Enter the Book Title: ";
        getline(cin, Title);
        cout << "Enter the Book Category: ";
        getline(cin, Category);
        cout << "Enter the Book Author: ";
        getline(cin, Author);
    }
    void adding_book()
    {
        input();
        if (Indexing < 10) {
            BookitemsList[Indexing] = Title;
            BookIdList[Indexing] = Book_ID;
            BookCategoryList[Indexing] = Category;
            BookAuthorList[Indexing] = Author;
            BookisBorrowedList[Indexing] = isBorrowed;
            Indexing++;
        } else {
            cout << "Book list is full!" << endl;
            cout<<"\n";
        }
    }
    void remove_book()
    {
        int remove_id;
        cout << "Enter the Book ID to remove: ";
        cin >> remove_id;
        for (int x = 0; x < Indexing; x++)
        {
            if (BookIdList[x] == remove_id)
            {
                for (int y = x; y < Indexing - 1; y++)
                {
                    BookitemsList[y] = BookitemsList[y + 1];
                    BookIdList[y] = BookIdList[y + 1];
                    BookCategoryList[y] = BookCategoryList[y + 1];
                    BookAuthorList[y] = BookAuthorList[y + 1];
                    BookisBorrowedList[y] = BookisBorrowedList[y + 1];
                }
                Indexing--;
                cout << "Book with ID " << remove_id << " has been removed." << endl;
                cout<<"\n";
                return;
            }
        }
        cout << "Book ID not found." << endl;
        cout<<"\n";
    }
    void Display_Book()
    {
        for (int x = 0; x < Indexing; x++)
        {
            cout << "Name: " << BookitemsList[x] << " Category: " << BookCategoryList[x] << " Id: " << BookIdList[x] << " Aurthor: " << BookAuthorList[x] << endl;
        }
    }

}Bor_Book;
class users
{
public:
    string Name;
    int age, User_ID;

    void Add_User()
    {
        cout << "Enter UserName: ";
        cin.ignore();
        getline(cin, Name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter User Id: ";
        cin >> User_ID;

        if (UserIndexing < 10) {
            UserIdList[UserIndexing] = User_ID;
            UsersList[UserIndexing] = Name;
            UserAgeList[UserIndexing] = age;
            UserIndexing++;
        } else {
            cout << "User list is full!" << endl;
            cout<<"\n";
        }
    }
    void Remove_User()
    {
        int remove_id;
        cout << "Enter the User ID to remove: ";
        cin >> remove_id;
        for (int x = 0; x < UserIndexing; x++)
        {
            if (UserIdList[x] == remove_id)
            {
                for (int y = x; y < UserIndexing - 1; y++)
                {
                    UsersList[y] = UsersList[y + 1];
                    UserIdList[y] = UserIdList[y + 1];
                    UserAgeList[y] = UserAgeList[y + 1];
                }
                UserIndexing--;
                cout << "User with ID " << remove_id << " has been removed." << endl;
                cout<<"\n";
            }
        }
        cout << "User ID not found." << endl;
    }
    void Display_user()
    {
        for (int x = 0; x < UserIndexing; x++)
        {
            cout << "Name: " << UsersList[x] << " Age: " << UserAgeList[x] << " Id: " << UserIdList[x] << endl;
            cout<<"\n";
        }
    }
    void admin_log()
    {
        string UserName;
        string password;
        cout<<"Enter UserName: ";
        cin>>UserName;
        cout<<"Enter Password: ";
        cin>>password;

        if((UserName == admin_username) && (password == admin_password)){
            cout<<"Login Successful! \n";
            cout<<"\n";
            admin_logged_in = true;
        }else
        {
            cout<<"Login Failed! \n";
            cout<<"\n";
            admin_logged_in = false;
        }
    }
    void add_New_Admin()
    {
        string new_admin_username;
        string new_admin_password;
        cout << "Enter new admin username: ";
        cin >> new_admin_username;
        cout << "Enter new admin password: ";
        cin >> new_admin_password;
        admin_username = new_admin_username;
        admin_password = new_admin_password;
        cout << "New admin created successfully!" << endl;
        cout<<"\n";
    }


}client;

class Book : public Library
{
public:
    int NumberOfBooks, NumberOfBorrowedBooks;
    bool isBorrowed;

     void borrow_Book()
    {
        int borrow_id;
        cout << "Enter the Book ID to borrow: ";
        cin >> borrow_id;
        for (int x = 0; x < Indexing; x++)
        {
            if (BookIdList[x] == borrow_id)
            {
                if (!isBorrowed)
                {
                    isBorrowed = true;
                    browed_count++;
                    cout << "You have borrowed: " << BookitemsList[x] << endl;
                    borrowedBooks[browed_ID] = BookitemsList[x];
                    lendedusers[browed_ID] = client.Name;
                    browed_ID++;
                }
                else
                {
                    cout << "Sorry, this book is already borrowed." << endl;
                    cout<<"\n";
                }
                return;
            }
        }
        cout << "Book ID not found." << endl;
        cout<<"\n";
    }
    void return_Book()
    {
        int return_id;
        cout << "Enter the Book ID to return: ";
        cin >> return_id;
        for (int x = 0; x < Indexing; x++)
        {
            if (BookIdList[x] == return_id)
            {
                if (isBorrowed)
                {
                    isBorrowed = false;
                    cout << "You have returned: " << BookitemsList[x] << endl;
                    cout<<"\n";
                }
                else
                {
                    cout << "This book was not borrowed." << endl;
                    cout<<"\n";
                }
                return;
            }
        }
        cout << "Book ID not found." << endl;
        cout<<"\n";
    }
    void Book_Status()
    {
        cout << "Total books borrowed: " << browed_count << endl;
    }
    void Book_Availability()
    {
        for (int x = 0; x < Indexing; x++)
        {
            cout << "Book: " << BookitemsList[x] << " is " << (isBorrowed ? "not available" : "available") << endl;
            cout<<"\n";
        }
    }
    void Search_Book()
    {
        string search_title;
        cout << "Enter the Book Title to search: ";
        cin.ignore();
        getline(cin, search_title);
        for (int x = 0; x < Indexing; x++)
        {
            if (BookitemsList[x] == search_title)
            {
                cout << "Book found: " << BookitemsList[x] << " Category: " << BookCategoryList[x] << " Id: " << BookIdList[x] << " Aurthor: " << BookAuthorList[x] << endl;
                cout <<"\n";
            }
        }
        cout << "Book not found." << endl;
        cout <<"\n";
    }
    void User_Borrowed_Books()
    {
        cout << "Books borrowed by users:" << endl;
        for (int i = 0; i < browed_ID; i++)
        {
            cout << lendedusers[i] << " borrowed " << borrowedBooks[i] << endl;
            cout<<"\n";
        }
    }



}stat_Book;


int main()
{
    cout<<"########################################### \n";
    cout<<"######### Welcome To the Library ########## \n";
    cout<<"########################################### \n";
    cout<<"######### 1: Login as Admin      ########## \n";
    cout<<"######### 2: Create New Admin    ########## \n";
    cout<<"######### 3: Quit                ########## \n";
    cout<<"########################################### \n";
    cout<<"########################################### \n";

    int option_one = 0;
    cout<<">>> ";
    cin>>option_one;

    switch (option_one)
    {
    case 1:
        client.admin_log();
        break;
    case 2:
        client.add_New_Admin();
        client.admin_log();
        break;


    case 3:
        exit(0);
        break;

    default:
        cout<<"Enter valid number! \n";
        break;
    }

    while(admin_logged_in)
    {
        cout<<"########################################### \n";
        cout<<"######### Welcome To the Library ########## \n";
        cout<<"########################################### \n";
        cout<<"######### 1: Add Book            ########## \n";
        cout<<"######### 2: Search a Book       ########## \n";
        cout<<"######### 3: Borrow Book         ########## \n";
        cout<<"######### 4: Return Book         ########## \n";
        cout<<"######### 5: Show All Books      ########## \n";
        cout<<"######### 6: Add Users           ########## \n";
        cout<<"######### 7: Show Users          ########## \n";
        cout<<"######### 8: Remove Users        ########## \n";
        cout<<"######### 9: Remove Book         ########## \n";
        cout<<"######### 0: Quit                ########## \n";
        cout<<"########################################### \n";
        cout<<"########################################### \n";


        int option_two = 0;
        cout<<">>>> ";
        cin>>option_two;

        switch (option_two)
        {
        case 1:
            Bor_Book.adding_book();
            break;
        case 2:
            stat_Book.Search_Book();
            break;
        case 3:
            stat_Book.borrow_Book();
            break;
        case 4:
            stat_Book.return_Book();
            break;
        case 5:
            cout<<"All Books Stats \n";
            stat_Book.Book_Availability();
            stat_Book.Book_Status();
            stat_Book.User_Borrowed_Books();
            break;
        case 6:
            client.Add_User();
            break;
        case 7:
            client.Display_user();
                break;
        case 8:
            client.Remove_User();
            break;
        case 9:
            Bor_Book.remove_book();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<"Enter valid number! \n";
            break;
        }
        cout<<"\n";
    }



}
