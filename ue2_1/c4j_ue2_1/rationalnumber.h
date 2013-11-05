#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

namespace rn {

class RationalNumber {
    int m_numerator, m_denomerator;

    int euklid(int a, int b) {
        if(b == 0) {
            return a;
        } else {
            return euklid(b, a % b);
        }
    }

public:
    RationalNumber(int numerator=0, int denomerator=1)
        : m_numerator(numerator / euklid(numerator, denomerator)), m_denomerator(denomerator / euklid(numerator, denomerator))
    {

    }

    int num() const;
    int denom() const;
    bool isValid() const;
    RationalNumber inverse() const;
    RationalNumber operator+(const RationalNumber rhs) const;
    RationalNumber operator-() const;
    bool operator==(const RationalNumber rhs) const;
    bool operator<(const RationalNumber rhs) const;
};

}

#endif // RATIONALNUMBER_H
