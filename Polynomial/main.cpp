#include <iostream>

#include "model/variable.hpp"
#include "model/subterm.hpp"
#include "model/term.hpp"
#include "model/monomial.hpp"
#include "model/polynomial.hpp"

int main(){
    Subterm s1(Variable('x',1));
    Subterm s2(Variable('x',2),3);
    std::cout<< "Subterms: " << s1.String() << ", "<< s2.String() << std::endl;

    Subterm s3(Variable('x',3),2);
    std::vector<Subterm> subs;
    subs.push_back(s1);
    subs.push_back(s2);
    subs.push_back(s2);
    subs.push_back(s3);
    Term t;
    t.WithSubs(subs);
    std::cout<< "Term: " << t.String() << std::endl;
    subs.clear();
    subs.push_back(Subterm(Variable('x',1)));
    subs.push_back(Subterm(Variable('x',2)));
    subs.push_back(Subterm(Variable('x',4)));
    Term t2;
    t2.WithSubs(subs);
    Term prod = t*t2;
    std::cout<< "product: " << prod.String() << std::endl;

    Monomial<int> m;
    m.WithCoef(10).WithTerm(prod);
           
    std::cout<< "monomial: " << m.String() << std::endl;


    Monomial<int> m2;
    m2.WithCoef(5).WithTerm(t);
    Polynomial<int> poly;
    poly.addMonomial(m);
    poly.addMonomial(m);
    poly.addMonomial(m2);
    std::cout<< "polynomial: " << poly.String() << std::endl;

}
