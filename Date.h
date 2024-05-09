//
// Created by salvatore on 09/05/24.
//

#ifndef LABPROG_DATE_H
#define LABPROG_DATE_H


class Date {
public:
    Date(int d, int m, int a): dd(d), mm(m), aaaa(a){};

    int getDd() const {
        return dd;
    }

    int getMm() const {
        return mm;
    }

    int getAaaa() const {
        return aaaa;
    }

private:
    int dd;
    int mm;
    int aaaa;
};


#endif //LABPROG_DATE_H
