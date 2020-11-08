#ifndef _VARIABLE_HPP_
#define _VARIABLE_HPP_

#include <string>

class Variable {
public:
    Variable(char name, int index);
    virtual ~Variable();
    std::string String() const;
    bool operator<(const Variable& rhs) const;
    bool operator==(const Variable& rhs) const;
    char GetName() const;
    int GetIndex() const;
private:
    int m_index;
    char m_name;
};

#endif