# pragma once

#include <string>

enum class Gender
{
    FEMALE, MALE, DIVERSE
};

std::string gender2string(Gender const g)
{
    switch (g)
    {
    case Gender::MALE:
        return "male";
    case Gender::FEMALE:
        return "female";
    default:
        return "diverse";
    }
}

Gender string2gender(std::string const sGender)
{
    if (sGender == "male")
        return Gender::MALE;
    else if (sGender == "female")
        return Gender::FEMALE;
    else
        return Gender::DIVERSE;
}