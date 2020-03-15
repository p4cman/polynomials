#ifndef _MONOMIAL_HPP
#define _MONOMIAL_HPP

#include "variable.hpp"
#include "subterm.hpp"
#include "term.hpp"
#include <string>
#include <sstream>
#include <iostream>

template<typename T>
class Monomial {
public:
    Monomial();
    virtual ~Monomial();
    Monomial& WithTerm(Term t);
    Monomial& WithCoef(T coef);
    std::string String() const;
    T getCoefficient() const;
    Term getTerm() const;    
private:
    T m_coef;
    Term m_term;
};

template<typename T>
Monomial<T>::Monomial() :m_coef(0) {
    std::cout << "monomial created"<< std::endl;
}

template<typename T>
Monomial<T>::~Monomial(){}
    
template<typename T>    
Monomial<T>& Monomial<T>::WithTerm(Term t) {
    this->m_term = t;
     std::cout << "With term: "<< t.String() << std::endl;
    return *this;
}

template<typename T>
Monomial<T>& Monomial<T>::WithCoef(T coef) {
    
    this->m_coef = coef;
    std::cout << "With coef: "<< coef << std::endl;
    return *this;
}

template<typename T>
std::string Monomial<T>::String() const {
    std::ostringstream output;
    if (this->m_coef == 0) {
        output << this->m_coef;
        return output.str();
    }
    std::string termStr = this->m_term.String();
    if (this->m_coef == 1 && termStr == "") {
        output << this->m_coef;
        return output.str();
    }
    if (this->m_coef == 1 && termStr != "") {
        return termStr;
    }
    output << this->m_coef << termStr;
    return output.str();

}

template<typename T>
T Monomial<T>::getCoefficient() const {
    return this->m_coef;
}

template<typename T>
Term Monomial<T>::getTerm() const {
    return this->m_term;
} 

#endif