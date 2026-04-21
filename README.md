#  Cash Management System (C Project)

##  Overview

This project is a **Cash Management System** implemented in the C programming language.
It allows multiple users to manage their wallet, perform transactions, and handle cash efficiently using different denominations.

---

##  Features

*  Multi-user support (up to 100 users)
*  Password authentication for security
*  Add money (₹10, ₹20, ₹50, ₹100, ₹200, ₹500)
*  Display wallet balance
*  Check if exact change is possible
*  Give change (deduct notes from wallet)
*  Transfer money between users
*  Delete user
*  Reset wallet
*  Transaction history tracking
*  Save data to file
*  Load data from file

---

## 🛠 Technologies Used

* C Programming Language
* Structures
* Arrays
* File Handling
* Functions

---

##  Project Structure

```
project.c     → Main source code
wallet.txt    → Stored user data (generated after save)
```

---

##  How to Compile and Run

###  Compile:

```
gcc project.c
```

###  Run:

```
./a
```

*(or `a.exe` in Windows)*

---

##  Sample Workflow

1. Create a user
2. Add money to wallet
3. Display balance
4. Check or give change
5. Transfer money
6. Save and load data

---

##  Example Output

```
===== CASH MANAGEMENT SYSTEM =====
1. Add Money
2. Display Balance
3. Check Change
4. Give Change
...
```

---

##  Limitations

* Maximum 100 users
* Fixed denominations only
* No encryption for passwords (basic implementation)

---



##  Author

** Vasavi Priya**

---

##  Academic Use

This project is developed as part of a **C programming academic assignment**.

---

##  Note

This project demonstrates:

* Data Structures (arrays, structures)
* File handling
* Modular programming
* Real-world problem solving

---
