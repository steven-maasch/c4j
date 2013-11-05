#include "rationalnumber.h"

/*
 *  Definition of intern functions
 */
int rnEuklid(int, int);

RationalNumber rnNormalize(RationalNumber);

bool rnIsValid(RationalNumber n) {
    return n.denominator != 0;
}

bool rnEqual(RationalNumber n, RationalNumber n1) {
    RationalNumber normalizeN = rnNormalize(n);
    RationalNumber normalizeN1 = rnNormalize(n1);
    return (normalizeN.numerator == normalizeN1.numerator) &&
            (normalizeN.denominator == normalizeN1.denominator);
}

bool rnLessThan(RationalNumber n, RationalNumber n1) {

    int tmp1 = n.numerator * n1.denominator;
    int tmp2 = n.denominator * n1.numerator;

     if((n.denominator < 0 && n1.denominator > 0) || (n1.denominator < 0 && n.denominator > 0)) {
        return tmp1 > tmp2;
    } else {
        return tmp1 < tmp2;
    }
}

RationalNumber rnAdd(RationalNumber n, RationalNumber n1) {
    RationalNumber result;
    result.numerator = n.numerator * n1.denominator + n1.numerator * n.denominator;
    result.denominator = n.denominator * n1.denominator;
    return rnNormalize(result);
}

RationalNumber rnSubtract(RationalNumber n, RationalNumber n1) {
    RationalNumber result;
    result.numerator = n.numerator * n1.denominator - n1.numerator * n.denominator;
    result.denominator = n.denominator * n1.denominator;
    return rnNormalize(result);
}

RationalNumber rnMultiply(RationalNumber n, RationalNumber n1) {
    RationalNumber result;
    result.numerator = n.numerator * n1.numerator;
    result.denominator = n.denominator * n1.denominator;
    return rnNormalize(result);
}

RationalNumber rnDivide(RationalNumber n, RationalNumber n1) {

    RationalNumber reziprok = { n1.denominator, n1.numerator };

    if(!rnIsValid(n) || !rnIsValid(n1) || !rnIsValid(reziprok)) {
        RationalNumber tmp = { 0, 0};
        return tmp;
    }
    return rnNormalize(rnMultiply(n, reziprok));
}

int rnEuklid(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return rnEuklid(b, a % b);
    }
}

RationalNumber rnNormalize(RationalNumber n) {
    int ggT = rnEuklid(n.numerator, n.denominator);
    RationalNumber tmp = { n.numerator / ggT, n.denominator / ggT };
    return tmp;
}
