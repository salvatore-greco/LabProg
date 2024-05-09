
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
            if((isLeapYear() && dd >29) || (!isLeapYear() && dd>29))
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

