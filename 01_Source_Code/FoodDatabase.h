#ifndef FOODDATABASE_H
#define FOODDATABASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include "FoodItem.h"
using namespace std;

class FoodDatabase {
private:
    map<string, FoodItem> db;

    // convert string to lowercase for case-insensitive search
    string toLower(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }

public:
    FoodDatabase() {
        loadFromCSV("foods.csv");
    }

    void loadFromCSV(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Warning: foods.csv not found. Manual entry only." << endl;
            return;
        }

        string line;
        getline(file, line); // skip header

        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            string p, c, f;

            getline(ss, name, ',');
            getline(ss, p, ',');
            getline(ss, c, ',');
            getline(ss, f, ',');

            if (name.empty()) continue;

            double protein = stod(p);
            double carbs   = stod(c);
            double fat     = stod(f);

            FoodItem item(name, protein, carbs, fat);
            db[toLower(name)] = item;
        }

        file.close();
        cout << "Database loaded: " << db.size() << " food items." << endl;
    }

    // search and return food item, returns true if found
    bool search(string query, FoodItem &result) {
        string lower = toLower(query);
        if (db.find(lower) != db.end()) {
            result = db[lower];
            return true;
        }
        return false;
    }

    // show all foods that contain the search keyword
    void showMatches(string keyword) {
        string lower = toLower(keyword);
        int count = 0;
        cout << "\n--- Matching foods ---" << endl;
        for (auto it = db.begin(); it != db.end(); it++) {
            if (it->first.find(lower) != string::npos) {
                FoodItem f = it->second;
                cout << "  " << f.getName()
                     << "  [P: " << f.getProtein() << "g"
                     << "  C: " << f.getCarbs() << "g"
                     << "  F: " << f.getFat() << "g]" << endl;
                count++;
            }
        }
        if (count == 0) {
            cout << "  No matches found." << endl;
        }
        cout << "----------------------" << endl;
    }

    int getSize() {
        return db.size();
    }
};

#endif
