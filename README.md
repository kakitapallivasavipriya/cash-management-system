#  Cash Management System

## 📌 Project Description

This project is a **Cash Management System** developed in C.
It allows multiple users to manage their wallet with different currency denominations.

The system supports adding money, checking exact change, giving change, and saving/loading data from files.

---

## 🚀 Features

* 👤 Multiple Users Support
* 🔐 Password Protection for secure operations
* 💵 Add Money (accumulates values)
* 📊 Display Wallet Balance
* ✅ Check Exact Change (Greedy Algorithm)
* 💸 Give Change (with deduction)
* 🗑️ Delete User
* 💾 Save Data to File
* 📂 Load Data from File

---

## 🧠 Concepts Used

* Structures
* Arrays
* Functions
* File Handling (`fopen`, `fprintf`, `fscanf`)
* String Handling (`strcmp`)
* Greedy Algorithm

---

## 🛠️ How to Run

1. Compile the code:

```
gcc proj.c
```

2. Run the program:

```
./a.exe
```

---

## 🧪 Sample Workflow

1. Create a user
2. Add money to wallet
3. Display balance
4. Check if exact change is possible
5. Give change
6. Save and load data

---

## 🎯 Example

Input:

```
Add Money → Rs.100: 2
```

Then again:

```
Add Money → Rs.100: 3
```

Output:

```
Total Rs.100 notes = 5
```

---

## 🔒 Security

* Each user has a password
* Required for adding or deducting money

---

## 📁 File Storage

* Data is stored in `wallet.txt`
* Supports saving and loading multiple users

---

## 👨‍💻 Author

* Name: Your Name
* Course: Your Course Name

---

## 📌 Notes

This project was developed as part of a lab assignment to demonstrate practical usage of C programming concepts.

---
