#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
using namespace std;

class FoodItem {
private:
    string name;
    double protein_g;
    double carb_g;
    double fat_g;

public:
    // default constructor (needed for map)
    FoodItem() {
        name = "";
        protein_g = 0;
        carb_g = 0;
        fat_g = 0;
    }

    // constructor
    FoodItem(string n, double p, double c, double f) {
        name = n;
        protein_g = p;
        carb_g = c;
        fat_g = f;
    }

    // getter functions
    string getName() {
        return name;
    }

    double getProtein() {
        return protein_g;
    }

    double getCarbs() {
        return carb_g;
    }

    double getFat() {
        return fat_g;
    }
};

#endif
