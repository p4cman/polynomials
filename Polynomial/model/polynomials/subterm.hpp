#ifndef _SUBTERM_HPP_
#define _SUBTERM_HPP_

#include "variable.hpp"
#include <map>
#include <string>

////////////////////////////////////////////////////////////////////
// class Subterm

// A subterm is a variable with its exponent

class Subterm {
public:
    Subterm(Variable v);
    Subterm(Variable v, int exp);
    virtual ~Subterm();
    std::string String() const;
    bool operator==(const Subterm& rhs) const;
    bool isSame(const Subterm& rhs) const;
    Variable getVariable() const;
    int getExponent() const;
    void setExponent(int exp);
private:
    Variable m_variable;
    int m_exponent;
};

#endif