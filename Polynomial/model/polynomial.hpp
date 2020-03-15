#ifndef _POLYNOMIAL_HPP_
#define _POLYNOMIAL_HPP_

#include "monomial.hpp"
#include <vector>


template<typename T> 
class Polynomial {
public:
    Polynomial();
    ~Polynomial();
    Polynomial& addMonomial(Monomial<T> m);

private:
    std::vector<Monomial<T> > m_monomials;
};


#endif
