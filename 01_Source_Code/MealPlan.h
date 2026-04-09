#ifndef MEALPLAN_H
#define MEALPLAN_H

#include <iostream>
#include <vector>
#include <string>
#include "FoodItem.h"
using namespace std;

class MealPlan {
private:
    string planName;
    vector<FoodItem> items;
    double total_protein;
    double total_carbs;
    double total_fat;

public:
    // constructor - initialize totals to 0
    MealPlan(string name) {
        planName = name;
        total_protein = 0;
        total_carbs = 0;
        total_fat = 0;
    }

    // add a food item and update totals
    void addItem(FoodItem f) {
        items.push_back(f);
        total_protein += f.getProtein();
        total_carbs += f.getCarbs();
        total_fat += f.getFat();
    }

    // display the full report for this plan
    void displayReport() {
        cout << "\n========================================" << endl;
        cout << "  Meal Plan: " << planName << endl;
        cout << "========================================" << endl;
        cout << "Food Items Logged: " << items.size() << endl;
        cout << "----------------------------------------" << endl;

        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ". " << items[i].getName()
                 << "  [P: " << items[i].getProtein() << "g"
                 << "  C: " << items[i].getCarbs() << "g"
                 << "  F: " << items[i].getFat() << "g]" << endl;
        }

        cout << "----------------------------------------" << endl;
        cout << "Total Protein : " << total_protein << "g" << endl;
        cout << "Total Carbs   : " << total_carbs << "g" << endl;
        cout << "Total Fat     : " << total_fat << "g" << endl;
        cout << "========================================" << endl;
    }

    string getName() {
        return planName;
    }

    // friend function declaration
    friend void ComparePlans(const MealPlan& planA, const MealPlan& planB);
};

// friend function - can access private members of MealPlan
void ComparePlans(const MealPlan& planA, const MealPlan& planB) {
    cout << "\n========================================" << endl;
    cout << "   COMPARISON REPORT" << endl;
    cout << "   " << planA.planName << "  vs  " << planB.planName << endl;
    cout << "========================================" << endl;

    double diffProtein = planA.total_protein - planB.total_protein;
    double diffCarbs   = planA.total_carbs   - planB.total_carbs;
    double diffFat     = planA.total_fat     - planB.total_fat;

    cout << "\nMacro         Plan A     Plan B     Difference" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "Protein(g)    " << planA.total_protein << "        "
         << planB.total_protein << "        " << diffProtein << endl;

    cout << "Carbs(g)      " << planA.total_carbs << "        "
         << planB.total_carbs << "        " << diffCarbs << endl;

    cout << "Fat(g)        " << planA.total_fat << "        "
         << planB.total_fat << "        " << diffFat << endl;

    cout << "\n--- Which plan is higher? ---" << endl;

    if (diffProtein > 0)
        cout << "Protein : " << planA.planName << " is higher by " << diffProtein << "g" << endl;
    else if (diffProtein < 0)
        cout << "Protein : " << planB.planName << " is higher by " << -diffProtein << "g" << endl;
    else
        cout << "Protein : Both plans are equal" << endl;

    if (diffCarbs > 0)
        cout << "Carbs   : " << planA.planName << " is higher by " << diffCarbs << "g" << endl;
    else if (diffCarbs < 0)
        cout << "Carbs   : " << planB.planName << " is higher by " << -diffCarbs << "g" << endl;
    else
        cout << "Carbs   : Both plans are equal" << endl;

    if (diffFat > 0)
        cout << "Fat     : " << planA.planName << " is higher by " << diffFat << "g" << endl;
    else if (diffFat < 0)
        cout << "Fat     : " << planB.planName << " is higher by " << -diffFat << "g" << endl;
    else
        cout << "Fat     : Both plans are equal" << endl;

    cout << "========================================" << endl;
}

#endif
