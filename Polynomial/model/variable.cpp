#include "variable.hpp"
#include <tuple>
#include <sstream>

Variable::Variable(char name, int index) :
    m_name(name),
    m_index(index)
{}

Variable::~Variable() {}

std::string Variable::String() const {
    std::ostringstream output;
    output << this->m_name << "_" << this->m_index;
    return output.str();   
}    

bool Variable::operator<(const Variable& rhs) const {
    return std::tie(this->m_name, this->m_index) < std::tie(rhs.m_name, rhs.m_index);
}

bool Variable::operator==(const Variable& rhs) const {
     return std::tie(this->m_name, this->m_index) == std::tie(rhs.m_name, rhs.m_index);
}

//////////////////////////////////////////////////////////////////////////////
// Properties

char Variable::GetName() const {
    return this->m_name;
}
   
int  Variable::GetIndex() const {
    return this->m_index;
}