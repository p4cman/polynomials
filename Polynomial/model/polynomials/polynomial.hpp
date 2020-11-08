#ifndef _POLYNOMIAL_HPP_
#define _POLYNOMIAL_HPP_

#include "monomial.hpp"
#include <vector>
#include <string>
#include <sstream>


template<typename T> 
class Polynomial {
public:
    Polynomial();
    virtual ~Polynomial();
    Polynomial& addMonomial(Monomial<T> m);
    std::string String() const;
    template<typename S>
    friend Polynomial<S> Sum(Polynomial<S>& lhs, const Polynomial<S>& rhs);
    template<typename S>
    friend Polynomial<S> Product(Polynomial<S>& lhs, const Polynomial<S>& rhs);
private:
    std::vector<Monomial<T> > m_monomials;
};

template<typename T>
Polynomial<T>::Polynomial() {} 

template<typename T>
 Polynomial<T>::~Polynomial() {}

template<typename T>
Polynomial<T>& Polynomial<T>::addMonomial(Monomial<T> monomial) {
     for (auto&& m : this->m_monomials) {
         if (m.getTerm() == monomial.getTerm()) {
             m.WithCoef(m.getCoefficient() + monomial.getCoefficient());
             return *this;
         }
     }
     this->m_monomials.push_back(monomial);
     return *this;
 }

template<typename T>
std::string Polynomial<T>::String() const {
    std::ostringstream polyStr;
    bool empty = true;
    for (auto&& m : this->m_monomials) {
        if (!empty) {
            polyStr << " + ";
        }
        polyStr << m.String();
        empty = false;
    }
    return polyStr.str();
}

template<typename S>
Polynomial<S> Sum(Polynomial<S>& lhs, const Polynomial<S>& rhs) {
    Polynomial<S> result;
     for (auto&& m : lhs.m_monomials) {
         result.addMonomial(m);
     }
     for (auto&& m : rhs.m_monomials) {
         result.addMonomial(m);
     }
     return result;
}

template<typename T>
Polynomial<T> Product(Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    Polynomial<T> result;
    for (auto&& m1 : lhs.m_monomials) {
        for (auto&& m2 : rhs.m_monomials) {
            result.addMonomial(m1 * m2);
        }
    }
    return result;
}

#endif
