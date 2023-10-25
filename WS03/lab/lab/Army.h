
#ifndef SDDS_ARMY_H // replace with relevant names
#define SDDS_ARMY_H
#define MAX_NAME_LEN 50
using namespace std;
namespace sdds {

    class Army {
    private:
        char nation[MAX_NAME_LEN];
        int units;
        double power;
    public:
        void setEmpty();
        void createArmy(const char* country, double pow, int troops);
        void updateUnits(int troops);
        const char* checkNationality() const;
        int checkCapacity() const;
        double checkPower() const;
        bool isEmpty() const;
        bool isStrongerThan(const Army& army)const;
    };

    void battle(Army& arm1, Army& arm2);
    void displayDetails(const Army* armies, int size);
}
#endif