#include "rationalnumber.h"

namespace rn {

int RationalNumber::num() const {
    return m_numerator;
}

int RationalNumber::denom() const {
    return m_denomerator;
}

bool RationalNumber::isValid() const {
    return (m_denomerator != 0);
}

RationalNumber RationalNumber::inverse() const {
    return RationalNumber(m_denomerator, m_numerator);
}

RationalNumber RationalNumber::operator+(const RationalNumber rhs) const {
    int newNum = m_numerator * rhs.m_denomerator + rhs.m_numerator * m_denomerator;
    int newDenom = m_denomerator * rhs.m_denomerator;
    return RationalNumber(newNum, newDenom);
}

RationalNumber RationalNumber::operator-() const{
    return RationalNumber(-m_numerator, m_denomerator);
}

bool RationalNumber::operator==(const RationalNumber rhs) const {
    return (m_numerator == rhs.m_numerator && m_denomerator == rhs.m_denomerator);
}

bool RationalNumber::operator<(const RationalNumber rhs) const {
    int tmp1 = m_numerator * rhs.m_denomerator;
    int tmp2 = m_denomerator * rhs.m_numerator;

    if((m_denomerator < 0 && rhs.m_denomerator > 0) || (rhs.m_denomerator < 0 && m_denomerator > 0)) {
        return tmp1 > tmp2;
    } else {
        return tmp1 < tmp2;
    }
}

}
