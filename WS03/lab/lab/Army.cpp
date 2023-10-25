
#include "Army.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds {
    void Army::setEmpty() {
        *nation = '\0';
        units = 0;
        power = 0;
    }

    void Army::createArmy(const char* country, double pow, int troops) {
        int safe = 0;
        if (country != nullptr && !(strlen(country) <= 1)) {
            if (pow > 0) {
                if (troops > 0) {
                    for (int i=0; i < MAX_NAME_LEN; i++) {
                        nation[i]=country[i];
                    }
                    nation[strlen(country)] = '\0';
                    power = pow;
                    units = troops;
                    safe = 1;
                }
            }
        }
        if (!safe) {
            setEmpty();
        }
    }

    void Army::updateUnits(int troops) {
        if (troops <= 0) {
            units += troops;
            power += (troops * 0.25);
        }
        if (troops > 0) {
            units += troops;
            power += (troops * 0.25);
        }
    }

    const char* Army::checkNationality() const {
        return nation;
    }

    int Army::checkCapacity() const {
        return units;
    }

    double Army::checkPower() const {
        return power;
    }

    bool Army::isEmpty() const {
        bool ok = false;
        if (units <= 0 || power <= 0) {
            ok = true;
        }
        if (nation == nullptr || strlen(nation) <= 0) {
            ok = true;
        }
        return ok;
    }

    bool Army::isStrongerThan(const Army& army) const {
        bool ok = false;
        if (power > army.power) {
            ok = true;
        }
        return ok;
    }

    void battle(Army& arm1, Army& arm2) {
        cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality();
        if (!arm1.isEmpty() && !arm2.isEmpty()) {
            if (arm1.isStrongerThan(arm2)) {
                cout << ", " << arm1.checkNationality() << " is victorious!" << endl;
                int lost = arm2.checkCapacity()/2;
                arm2.updateUnits(-lost);
            }
            else {
                cout << ", " << arm2.checkNationality() << " is victorious!" << endl;
                int lost = arm1.checkCapacity()/2;
                arm1.updateUnits(-lost);
            }
        }
    }

    void displayDetails(const Army* armies, int size) {
        if (armies != nullptr && size > 0) {
            cout << "Armies reporting to battle: \n";
            for (int i = 0; i < size; i++) {
                if (armies[i].isEmpty())
                    continue;
                cout << "Nationality: " << armies[i].checkNationality() << ", ";
                cout << "Units Count: " << armies[i].checkCapacity() << ", ";
                cout << "Power left: " << fixed << setprecision(1) << armies[i].checkPower() << endl;
            }
        }
    }

}
