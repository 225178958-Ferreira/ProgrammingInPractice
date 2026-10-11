# MFMS Week 9 Project

## Overview
This project is a modular Municipal Financial Management System (MFMS) written in C.  
It demonstrates splitting functionality across multiple source files and headers, then compiling and linking them into one executable.

## Modules
- **main.c**  
  Controls the program menu and flow.
- **employees.c / employees.h**  
  Handles employee records (add, list, salaries).
- **budget.c / budget.h**  
  Manages budget items (add, list, average).
- **utilities.c / utilities.h**  
  Provides helper input functions.
- **reports.c / reports.h**  
  Generates summaries using employees and budget data.
- **suppliers.c / suppliers.h** *(extension)*  
  Manages supplier records (add, list).

## Build Instructions
Compile all modules with GCC:
```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c utilities.c reports.c suppliers.c -o mfms

./mfms      # Linux/macOS
.\mfms.exe  # Windows PowerShell
