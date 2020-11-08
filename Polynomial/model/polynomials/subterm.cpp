#include "subterm.hpp"
#include <sstream>

Subterm::Subterm(Variable v): 
  m_variable(v),
  m_exponent(1) {
}
    
Subterm::Subterm(Variable v, int exp)
 :m_variable(v),
 m_exponent(exp) {
}

Subterm::~Subterm() {}
    
std::string Subterm::String() const {
    if (this->m_exponent == 0) {
        return "";
    }

    std::ostringstream output;
    output << this->m_variable.String();
    if (this->m_exponent != 1) {
        output << "^" << this->m_exponent;
    }
    return output.str();    
}

bool Subterm::operator==(const Subterm& rhs) const {
    return std::tie(this->m_variable, this->m_exponent) == std::tie(rhs.m_variable, rhs.m_exponent);
}

bool Subterm::isSame(const Subterm& rhs) const {
    return this->m_variable == rhs.m_variable;
}

Variable Subterm::getVariable() const {
    return this->m_variable;
}

int Subterm::getExponent() const {
    return this->m_exponent;
}

void Subterm::setExponent(int exp) {
    this->m_exponent = exp;
}