#include <string>

class VariableName {
public:
    VariableName(char name, int index);
    virtual ~VariableName();
    std::string String() const;
    void ShowIndex(bool s);
    
private:
    bool m_showIndex;
    int m_index;
    char m_name;
};