#include "Date.h"

Date::Date(int d, int m, int y): dd(d), mm(m), yyyy(y) {
    if(!isValidDate())
        throw std::invalid_argument("Provided an invalid date");
}
bool Date::isValidDate() const{
    if(mm>12 || mm<1 || !isValidDay())
        return false;
    return true;
}

bool Date::isValidDay() const {
    switch(mm){
        case 4:
        case 6:
        case 9:
        case 11:
            if(dd>30)
                return false;
            return true;
        case 2:
            if(isLeapYear() && dd>29){
                    return false;
            }
            if(!isLeapYear() && dd>28)
                return false;
            return true;
        default:
            if(dd>31)
                return false;
            return true;

    }
}

bool Date::isLeapYear() const {
    if (yyyy % 4 == 0) {
        if (yyyy % 100 == 0) {
            return yyyy % 400 == 0;
        }
        return true;
    }
    return false;
}

bool Date::operator<(const Date &rhs) const{
    int left = ((this->yyyy << 4) | (this->mm << 2)) | this->dd;
    int right = ((rhs.yyyy << 4) | (rhs.mm << 2)) | rhs.dd;
    if(left<right)
        return true;
    return false;
}

bool Date::operator==(const Date &rhs) const {
    if(dd == rhs.dd && mm == rhs.mm && yyyy == rhs.yyyy)
        return true;
    return false;
}

int Date::distanceBetween(const Date d1, const Date d2) {
    int convertedD1 = ((d1.yyyy << 4) | (d1.mm << 2)) | d1.dd;
    int convertedD2 = ((d2.yyyy << 4) | (d2.mm << 2)) | d2.dd;
    return abs(convertedD1-convertedD2);
}



