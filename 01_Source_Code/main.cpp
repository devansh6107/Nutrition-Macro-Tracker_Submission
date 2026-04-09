#include <iostream>
#include <string>
#include "FoodDatabase.h"
#include "MealPlan.h"
using namespace std;

void addFoodToPlan(MealPlan &plan, FoodDatabase &db) {
    string query;
    cout << "\nEnter food name (or keyword to search): ";
    cin.ignore();
    getline(cin, query);

    FoodItem found("temp", 0, 0, 0);
    bool inDB = db.search(query, found);

    if (inDB) {
        cout << "\nFound in database!" << endl;
        cout << "  " << found.getName()
             << "  [Protein: " << found.getProtein() << "g"
             << "  Carbs: " << found.getCarbs() << "g"
             << "  Fat: " << found.getFat() << "g]" << endl;

        char useIt;
        cout << "Use these values? (y/n): ";
        cin >> useIt;

        if (useIt == 'y' || useIt == 'Y') {
            plan.addItem(found);
            cout << found.getName() << " added to " << plan.getName() << "!" << endl;
            return;
        }
    } else {
        cout << "\nExact match not found. Searching similar items..." << endl;
        db.showMatches(query);

        char tryAgain;
        cout << "Try exact name from above? (y/n): ";
        cin >> tryAgain;

        if (tryAgain == 'y' || tryAgain == 'Y') {
            string exactName;
            cout << "Enter exact name: ";
            cin.ignore();
            getline(cin, exactName);

            if (db.search(exactName, found)) {
                plan.addItem(found);
                cout << found.getName() << " added to " << plan.getName() << "!" << endl;
                return;
            } else {
                cout << "Still not found. Switching to manual entry." << endl;
            }
        }
    }

    // manual entry fallback
    cout << "\n--- Manual Entry ---" << endl;
    string itemName;
    double protein, carbs, fat;

    cout << "Enter food name: ";
    cin.ignore();
    getline(cin, itemName);

    cout << "Enter Protein (g): ";
    cin >> protein;
    while (protein < 0) {
        cout << "Invalid! Enter positive value: ";
        cin >> protein;
    }

    cout << "Enter Carbs (g): ";
    cin >> carbs;
    while (carbs < 0) {
        cout << "Invalid! Enter positive value: ";
        cin >> carbs;
    }

    cout << "Enter Fat (g): ";
    cin >> fat;
    while (fat < 0) {
        cout << "Invalid! Enter positive value: ";
        cin >> fat;
    }

    FoodItem manual(itemName, protein, carbs, fat);
    plan.addItem(manual);
    cout << itemName << " added to " << plan.getName() << "!" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "     NUTRITION MACRO TRACKER" << endl;
    cout << "========================================" << endl;

    FoodDatabase db;

    MealPlan planA("Bulking Plan");
    MealPlan planB("Cutting Plan");

    int choice;

    do {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Add food item to Plan A (" << planA.getName() << ")" << endl;
        cout << "2. Add food item to Plan B (" << planB.getName() << ")" << endl;
        cout << "3. Search food in database" << endl;
        cout << "4. View Plan A Report" << endl;
        cout << "5. View Plan B Report" << endl;
        cout << "6. Compare Plans" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addFoodToPlan(planA, db);
        } else if (choice == 2) {
            addFoodToPlan(planB, db);
        } else if (choice == 3) {
            string keyword;
            cout << "Enter keyword to search: ";
            cin.ignore();
            getline(cin, keyword);
            db.showMatches(keyword);
        } else if (choice == 4) {
            planA.displayReport();
        } else if (choice == 5) {
            planB.displayReport();
        } else if (choice == 6) {
            ComparePlans(planA, planB);
        } else if (choice == 7) {
            cout << "\nExiting. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
