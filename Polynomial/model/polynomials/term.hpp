#ifndef _TERM_HPP_
#define _TERM_HPP_

#include <map>
#include "subterm.hpp"
#include "variable.hpp"
#include <vector>
#include <string>

class Term {
public:
    Term();
    Term(const Term& clone);
    Term& operator=(const Term& rhs);
    Term& WithSubs(std::vector<Subterm> subs);
    virtual ~Term();
    std::string String() const;
    std::vector<Subterm> getSubterms() const;
    friend Term operator*(Term lhs, const Term& rhs);
    bool operator==(const Term& rhs);
 private:
    std::map<Variable, Subterm*> m_subterms;
};

#endif