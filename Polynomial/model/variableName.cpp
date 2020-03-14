#include "VariableName.hpp"

VariableName::VariableName(char name, int index) :
    m_name(name),
    m_index(index),
    m_showIndex(true) 
{}

VariableName::~VariableName() {}

std::string VariableName::String() const {
    return "<<invalid>>";
}    

void VariableName::ShowIndex(bool s) {
    this->m_index = s;
}