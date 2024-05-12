#ifndef LABPROG_DATE_H
#define LABPROG_DATE_H
#include <stdexcept>

class Date {
public:
    Date(int d, int m, int y);

    int getDd() const {
        return dd;
    }

    int getMm() const {
        return mm;
    }

    int getYyyy() const {
        return yyyy;
    }
    bool operator<(const Date& rhs) const;
    bool operator==(const Date &rhs) const;
    static int distanceBetween(const Date d1, const Date d2);
private:
    int dd;
    int mm;
    int yyyy;

    bool isValidDay() const;
    bool isValidDate() const;
    bool isLeapYear() const;

};


#endif //LABPROG_DATE_H
