#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    int numerator, denominator;
};

bool rnIsValid(RationalNumber);

bool rnEqual(RationalNumber, RationalNumber);

bool rnLessThan(RationalNumber, RationalNumber);

RationalNumber rnAdd(RationalNumber, RationalNumber);

RationalNumber rnSubtract(RationalNumber, RationalNumber);

RationalNumber rnMultiply(RationalNumber, RationalNumber);

RationalNumber rnDivide(RationalNumber, RationalNumber);

#endif // RATIONALNUMBER_H
