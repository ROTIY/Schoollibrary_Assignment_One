
# School Library Assignment

## Overview

This project is a simple C++ console application for managing a school library. The main logic is implemented in `main.cpp` and provides basic features for handling books, users, and admin authentication.

## Features Explained

### Book Management
- The `Book` class (which inherits from `Library`) allows you to add new books and display the list of books.
- Book details include title, category, author, and book ID.
- Books are stored in arrays, with a maximum of 10 books supported.

### User Management
- The `users` class lets you add new users and display all users.
- User details include name, age, and user ID.
- Users are stored in arrays, with a maximum of 10 users supported.

### Admin Authentication
- The `admin_log` function allows an admin to log in using a username and password.
- The function provides up to 3 login attempts and gives feedback for success or failure.
- Admin credentials can be updated using the `add_New_Admin` function.

## How It Works
1. When the program starts, you can add books and users through console prompts.
2. Admins can log in to access restricted features.
3. All data is stored in memory (arrays) and is lost when the program exits.

## Note
- The code is for educational purposes and does not use advanced data structures or persistent storage.
- All input and output is handled via the console.



## How to Use

1. **Compile the Program**
	- Open a terminal or command prompt in the project directory.
	- Use a C++ compiler (e.g., g++, MinGW) to compile `main.cpp`:
	  ```
	  g++ main.cpp -o SchoolLibrary.exe
	  ```
	- Or use your IDE's build/run feature.

2. **Run the Program**
	- Execute the compiled program:
	  ```
	  SchoolLibrary.exe
	  ```


3. **Follow the Prompts**
	- **First, create a user account** by entering your details when prompted.
	- Add books and users by entering the requested information in the console.
	- To access admin features, you must first create an admin account (if one does not exist) using the provided function.
	- After creating an account, use the admin login prompt and enter the correct credentials to log in.

4. **View Data**
	- Use the display options to view all books and users currently stored in memory.

**Note:** All data is stored in memory and will be lost when the program exits.

5. ** Plans for future improvements **
	- Use dynamic data structures (like vectors or lists) instead of fixed-size arrays for scalability.
	- Implement persistent storage (e.g., file or database) so data is not lost when the program exits.
	- Add more user roles and permissions (e.g., librarian, student).
	- Improve input validation and error handling for robustness.
	- Enhance security for admin authentication (e.g., password hashing, hidden input).
	- Create a menu-driven interface for easier navigation.
	- Add features for borrowing/returning books and tracking book status.
	- Support searching and filtering books and users.
	- Refactor code for modularity and maintainability (separate files/classes).
