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
            if(isLeapYear(yyyy) && dd>29){
                    return false;
            }
            if(!isLeapYear(yyyy) && dd>28)
                return false;
            return true;
        default:
            if(dd>31)
                return false;
            return true;

    }
}

bool Date::isLeapYear(int yyyy){
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
    //c'è del codice duplicato ma non mi andava di aggiungere altre funzioni
    int day1 = d1.dd;
    int day2 = d2.dd;
    for (int i = 1900; i<d1.yyyy; i++){
        isLeapYear(i) ? day1+=366 : day1 +=365;
    }
    for (int i = 1900; i<d2.yyyy; i++){
        isLeapYear(i) ? day2+=366 : day2 +=365;
    }
    for (int i = 1; i<d1.mm; i++){
        switch (i) {
            case 4:
            case 6:
            case 9:
            case 11:
                day1 += 30;
                break;
            case 2:
                isLeapYear(d1.yyyy) ? day1+=29 : day1+=28;
                break;
            default:
                day1+=31;
        }
    }
    for (int i = 1; i<d2.mm; i++){
        switch (i) {
            case 4:
            case 6:
            case 9:
            case 11:
                day2 += 30;
                break;
            case 2:
                isLeapYear(d2.yyyy) ? day2+=29 : day2+=28;
                break;
            default:
                day2+=31;
        }
    }
    return abs(day1-day2);
}




