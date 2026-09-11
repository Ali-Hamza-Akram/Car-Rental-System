# 🚗 Car Rental System

A console-based **Car Rental System** developed in **C++** to simulate the basic operations of a car rental business. The project focuses on applying Object-Oriented Programming concepts to a practical, real-world system.

## 📌 Features

* Add and manage cars
* Add and manage customers
* Search available cars by type
* Search customers by CNIC
* Rent a car
* Return a car
* Automatic rental ID generation (`R101`, `R102`, ...)
* Generate rental slips
* Track car availability
* Input validation
* Duplicate Car ID, Number Plate, Customer ID, and CNIC validation
* Store car, customer, and rental records in files
* Load saved data automatically when the program starts
* Maintain data across program restarts

## 🛠️ Technologies & Concepts

* **C++**
* **Object-Oriented Programming (OOP)**
* Classes & Objects
* Encapsulation
* Constructors & Member Functions
* C++ Vectors
* Functions & Modular Programming
* File Handling using `fstream`
* Data Persistence
* Input Validation
* Searching & Data Management
* Debugging & Logical Problem Solving

## 🏗️ Main Classes

The system is organized around three main classes:

### `Car`

Stores and manages information about cars, including:

* Car ID
* Company
* Model
* Model Year
* Color
* Number Plate
* Type
* Rent Per Day
* Availability Status

### `Customer`

Stores customer information such as:

* Customer ID
* Name
* CNIC

### `Rental`

Manages rental information including:

* Rental ID
* Car ID
* Customer ID
* Rental Days
* Total Rent

### `RentalSystem`

Acts as the main system controller and manages:

* Cars
* Customers
* Rentals
* File operations
* Rental operations
* Searching and validation

## 💾 Data Persistence

The system uses text files to store data:

* `cars.txt` — stores car records and availability
* `customers.txt` — stores customer records
* `rentals.txt` — stores rental records

When the program starts, previously saved data is loaded automatically. Changes are saved back to the files so data remains available after restarting the application.

## 🔄 Rental Workflow

The basic rental process is:

1. Select a customer.
2. Select an available car.
3. Enter the number of rental days.
4. The system automatically generates a Rental ID.
5. Total rent is calculated based on the daily rental rate.
6. The rental record is saved.
7. The car's availability changes to **Rented**.
8. A rental slip can be displayed using the Rental ID.

When a car is returned, its availability is changed back to **Available** and the updated information is saved.

## 🎯 Learning Objectives

This project was developed to strengthen practical understanding of:

* Object-Oriented Programming
* Class design and relationships
* Data management using vectors
* File handling and data persistence
* Input validation
* Debugging logical errors
* Building a complete console-based application

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/your-username/car-rental-system.git
```

### 2. Open the project

Open the project in any C++ compatible IDE or code editor.

### 3. Compile the program

Using g++:

```bash
g++ main.cpp -o car-rental-system
```

### 4. Run

**Windows:**

```bash
car-rental-system.exe
```

**Linux/macOS:**

```bash
./car-rental-system
```

## 📂 Project Structure

```text
Car-Rental-System/
│
├── main.cpp
├── cars.txt
├── customers.txt
├── rentals.txt
└── README.md
```

> The `.txt` files are created/updated by the program to maintain persistent records.

## 🚀 Future Improvements

Possible improvements for future versions include:

* Rental status tracking (Active/Returned)
* Better case-insensitive searching
* More robust file-data validation
* Admin authentication
* Rental and return dates
* Improved user interface
* Database integration
* GUI version

## 👨‍💻 Author

**Ali Hamza Akram**

BS Computer Science Student
Interested in C++, Object-Oriented Programming, and Software Development.

---

⭐ If you find this project useful or interesting, feel free to star the repository!
