#ifndef ENUMSTRING_H
#define ENUMSTRING_H

#include <string>
#include <map>

enum class COLORS : unsigned char { black, green, red, blue }; //enum class : char

template<typename T> struct EnumMap {
private:
    static std::map<std::string, T> m_eMap;
public:
    static const auto& getMap() { return m_eMap; }
};

template<>
std::map<std::string, COLORS> EnumMap<COLORS>::m_eMap = {
                            {std::string("black"), COLORS::black},
                            {std::string("green"), COLORS::green},
                            {std::string("red"), COLORS::red},
                            {std::string("blue"), COLORS::blue}
};


template <typename T>
auto stringToEnum(const std::string& str)
{
    return EnumMap<T>::getMap().at(str);
}

template <typename T>
auto enumToString(T t)
{
    for (auto& [F, S] : EnumMap<T>::getMap())
    {
        if (S == t)
        {
            return F;
        }
    }
    throw "bad_enum_parameter";
}


#endif // ENUMSTRING_H
