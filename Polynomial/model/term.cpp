#include "term.hpp"
#include <sstream>

Term::Term() {}

Term& Term::WithSubs(std::vector<Subterm> subs) {
    this->m_subterms.clear();
    for (auto&& s : subs) {
        auto it = this->m_subterms.find(s.getVariable());
        if (it == this->m_subterms.end()) {
            m_subterms[s.getVariable()] = new Subterm(s);
        } else {
           m_subterms[s.getVariable()]->setExponent(it->second->getExponent() + s.getExponent());
        }
    }
    return *this; 
}

Term::~Term() {
    for (auto&& it : this->m_subterms) {
        delete it.second;
    }
}

Term::Term(const Term& clone) {
    this->WithSubs(clone.getSubterms());
}
 
Term& Term::operator=(const Term& rhs) {
    if (this != &rhs) {
        this->WithSubs(rhs.getSubterms());
    }
    return *this;
}
    
std::string Term::String() const {
    std::ostringstream output;
    for (auto&& s : m_subterms) {
        output << s.second->String();
    }
    return output.str();
}
    
std::vector<Subterm> Term::getSubterms() const {
    std::vector<Subterm> subs;
    for (auto&& s : m_subterms) {
        subs.push_back(*s.second);
    }
    return subs;
}

Term operator*(Term lhs, const Term& rhs) {
     for (auto&& s : rhs.m_subterms) {
        auto it = lhs.m_subterms.find(s.second->getVariable());
        if (it == lhs.m_subterms.end()) {
            lhs.m_subterms[s.second->getVariable()] = new Subterm(*s.second);
        } else {
            lhs.m_subterms[s.second->getVariable()]->setExponent(it->second->getExponent() + s.second->getExponent());
        }
    }
    return lhs; 
}
 
bool Term::operator==(const Term& rhs) {
    for (auto&& s : this->m_subterms) {
        auto&& it = rhs.m_subterms.find(s.second->getVariable());
        if (it == rhs.m_subterms.end()) {
            return false;
        } 
        if (it->second->getExponent() != s.second->getExponent()){
            return false;
        }
    }
    for (auto&& s : rhs.m_subterms) {
        auto&& it = this->m_subterms.find(s.second->getVariable());
        if (it == this->m_subterms.end()) {
            return false;
        } 
        if (it->second->getExponent() != s.second->getExponent()){
            return false;
        }
    }
    return true;
}