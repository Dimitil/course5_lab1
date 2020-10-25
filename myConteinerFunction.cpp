#include "myConteinerFunction.h"

std::string operator-(const std::string &str)
{
    std::string res(str);
    for (auto& ch : res)
    {
        if ( ch >= 'a')
        {
            ch = toupper(ch);
        }
        else
        {
            ch = tolower(ch);
        }
    }
    return res;
}
