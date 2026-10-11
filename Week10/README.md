# MFMS Week 10 Project

## Overview
This project extends the modular Municipal Financial Management System (MFMS) from Week 9.  
Week 10 focuses on **data persistence, backup, search, and robustness**.  
All records (Employees, Suppliers, Budgets) can now be saved to text files, reloaded across program runs, and backed up for safety.

## Modules
- **main.c**  
  Controls the program menu and flow.
- **employees.c / employees.h**  
  Handles employee records (add, list, salaries, search).  
  Includes save/load functions for text and binary files.
- **budget.c / budget.h**  
  Manages budget items (add, list, average).  
  Includes save/load functions for text files.
- **suppliers.c / suppliers.h**  
  Manages supplier records (add, list).  
  Includes save/load functions for text files.
- **utilities.c / utilities.h**  
  Provides helper input functions and backup file utility.
- **reports.c / reports.h**  
  Generates summaries using employees and budget data.

## New Features (Week 10)
- **Save/Load Data (Text Files)**  
  Employees, Suppliers, Budgets saved to `data/*.txt`.  
  Confirmation message shows how many records were saved/loaded.
- **Binary Storage (Employees)**  
  Added binary save/load for employees to compare text vs binary formats.
- **Backup Data**  
  Added menu option to copy each data file into a backup file (`*_backup.txt`).
- **Search Employee**  
  Added menu option to search employees by ID or name.
- **Record Count Report**  
  After loading each file, program prints how many records were loaded.
- **Error Handling**  
  Handles missing files, empty files, malformed records, and duplicate IDs gracefully.

## Build Instructions
Compile all modules with GCC:
```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c suppliers.c budget.c reports.c utilities.c -o mfms_week10

./mfms_week10      # Linux/macOS
.\mfms_week10.exe  # Windows PowerShell

