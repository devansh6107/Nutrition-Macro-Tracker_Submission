# MacroLog — Nutrition Macro Tracker

A console-based C++ application for tracking and comparing macronutrient intake across two meal plans.

Built as a case study for **Object Oriented Programming (BACSE105)** at VIT Vellore.

---

## What It Does

- Loads a database of **556 food items** from a plain text file (`foods.csv`)
- Lets the user add food items to two meal plans (e.g. Bulking Plan and Cutting Plan)
- Automatically updates total protein, carbs, and fat as items are added
- Supports exact and partial keyword food search
- Compares both plans using a **friend function** that directly accesses private class data

---

## Key OOP Concepts Demonstrated

| Concept | Where |
|---|---|
| Encapsulation | `FoodItem` and `MealPlan` — all data members are private |
| Friend Function | `ComparePlans()` reads private macro totals of two `MealPlan` objects |
| Constructors | Parameterized + default constructors in both classes |
| STL: `std::vector` | `MealPlan` stores food items; `FoodDatabase` stores all 556 foods |
| File I/O | `FoodDatabase` reads `foods.csv` at runtime using `std::ifstream` |

---

## File Structure

```
MacroLog_Submission/
├── 01_Source_Code/
│   ├── main.cpp
│   ├── FoodItem.h
│   ├── MealPlan.h
│   └── FoodDatabase.h
├── 02_Input_Files/
│   └── foods.csv
├── 03_Test_Report/
│   └── Example_Execution.txt
└── 04_Technical_README/
    └── README.pdf
```

---

## How to Compile and Run

```bash
# Compile
g++ main.cpp -o MacroLog

# Run on Linux / macOS
./MacroLog

# Run on Windows
MacroLog.exe
```

> **Important:** `foods.csv` must be in the same folder as the compiled executable.

---

## Food Database

`foods.csv` contains 556 unique food items with protein, carbs, and fat values per 100g.

Categories covered:
- Indian staples, dal, sabzi, non-veg, sweets
- Street food (pani puri, vada pav, bhel, puchka, bread pakora, etc.)
- Gym / fitness foods (chicken breast, oats, whey protein, etc.)
- Fast food (pizza, burger, KFC, shawarma, etc.)
- Fruits, vegetables, beverages, bakery items
- Regional Indian (Litti Chokha, Dal Baati, Haleem, etc.)

---

## Team

| Name | Reg. No. | Contribution |
|---|---|---|
| Devansh A Ghosh (Leader) | 25BCE0283 | Console interface, FoodDatabase, foods.csv, architecture, integration |
| Rudra Narayan Mishra | 25BCE0226 | OOP design — encapsulation, FoodItem & MealPlan classes, constructors |
| Vatsal Agrawal | 25BCE0275 | STL implementation — std::vector in MealPlan and FoodDatabase |
| Shuhul Tickoo | 25BCE0242 | Friend function — ComparePlans() declaration, definition, MealPlan design |

---

## Course

**BACSE105 — Object Oriented Programming**  
Vellore Institute of Technology, Vellore  
Academic Year: 2025–26
