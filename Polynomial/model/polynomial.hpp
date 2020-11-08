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

#endif
