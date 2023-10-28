#include <iostream>
#include <cstring>
#include <iostream>

class Rational final {
    public:
        Rational(int numerator, int denominator);
        Rational(const Rational& other);

        Rational& operator=(const Rational& other);
        Rational& operator+=(const Rational &rha);
        Rational& operator-=(const Rational &rha);
        Rational& operator*=(const Rational &rha);
        Rational& operator/=(const Rational &rha);
        Rational operator+() const;
        Rational operator-() const;
        
        explicit operator double() const {
        return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
        }

        double toDouble() const {
        return static_cast<double>(*this);
        }
    
    private:
        friend bool operator<(const Rational &, const Rational &);

        int m_numerator;
        int m_denominator;
};

bool operator<(const Rational &lha, const Rational &rha);
bool operator>(const Rational &lha, const Rational &rha);
bool operator<=(const Rational &lha, const Rational &rha);
bool operator>=(const Rational &lha, const Rational &rha);
bool operator==(const Rational &lha, const Rational &rha);
bool operator!=(const Rational &lha, const Rational &rha);


#pragma once
#include <iostream>
#include <numeric>

class Rational final {
public:
Rational(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
normalize();
}

Rational(const Rational& other) : m_numerator(other.m_numerator), m_denominator(other.m_denominator) {}

Rational& operator+=(const Rational &rha) {
m_numerator = m_numerator * rha.m_denominator + rha.m_numerator * m_denominator;
m_denominator *= rha.m_denominator;
normalize();
return *this;
}

Rational operator+(const Rational &rha) const {
return Rational(*this) += rha;
}

// Операторы унарного минуса и плюса
Rational operator-() const {
return Rational(-m_numerator, m_denominator);
}

Rational operator+() const {
return *this;
}

// Остальные операторы и методы
Rational& operator-=(const Rational &rha) {
return *this += -rha;
}

Rational operator-(const Rational &rha) const {
return Rational(*this) -= rha;
}

Rational& operator*=(const Rational &rha) {
m_numerator *= rha.m_numerator;
m_denominator *= rha.m_denominator;
normalize();
return *this;
}

Rational operator*(const Rational &rha) const {
return Rational(*this) *= rha;
}

Rational& operator/=(const Rational &rha) {
return *this *= {rha.m_denominator, rha.m_numerator};
}

Rational operator/(const Rational &rha) const {
return Rational(*this) /= rha;
}

explicit operator double() const {
return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

double toDouble() const {
return static_cast<double>(*this);
}

private:
void normalize() {
int gcd = std::gcd(m_numerator, m_denominator);
m_numerator /= gcd;
m_denominator /= gcd;
}

int m_numerator;
int m_denominator;

public:
friend bool operator<(const Rational &lha, const Rational &rha);
friend bool operator>(const Rational &lha, const Rational &rha);
friend bool operator<=(const Rational &lha, const Rational &rha);
friend bool operator>=(const Rational &lha, const Rational &rha);
friend bool operator==(const Rational &lha, const Rational &rha);
friend bool operator!=(const Rational &lha, const Rational &rha);

friend Rational operator+(int lhs, const Rational& rhs);
friend Rational operator-(int lhs, const Rational& rhs);
friend Rational operator*(int lhs, const Rational& rhs);
friend Rational operator/(int lhs, const Rational& rhs);
};

bool operator<(const Rational &lha, const Rational &rha) {
return lha.toDouble() < rha.toDouble();
}

bool operator>(const Rational &lha, const Rational &rha) {
return rha < lha;
}

bool operator<=(const Rational &lha, const Rational &rha) {
return !(lha > rha);
}

bool operator>=(const Rational &lha, const Rational &rha) {
return !(lha < rha);
}

bool operator==(const Rational &lha, const Rational &rha) {
return !(lha < rha || lha > rha);
}

bool operator!=(const Rational &lha, const Rational &rha) {
return !(lha == rha);
}

Rational operator+(int lhs, const Rational& rhs) {
return Rational(lhs) + rhs;
}

Rational operator-(int lhs, const Rational& rhs) {
return Rational(lhs) - rhs;
}

Rational operator*(int lhs, const Rational& rhs) {
return Rational(lhs) * rhs;
}

Rational operator/(int lhs, const Rational& rhs) {
return Rational(lhs) / rhs;
}
