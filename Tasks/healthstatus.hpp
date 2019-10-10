# pragma once

#include <string>

enum class Healthstatus
{
    HEALTHY, SICK, DEAD, UNKNOWN
};

std::string healthstatus2string(Healthstatus const h)
{
    switch (h)
    {
    case Healthstatus::HEALTHY:
        return "healthy";
    case Healthstatus::SICK:
        return "sick";
    case Healthstatus::DEAD:
        return "dead";
    default:
        return "unknown";
    }
}

Healthstatus string2healthstatus(std::string const sh)
{
    if (sh == "healthy")
        return Healthstatus::HEALTHY;
    else if (sh == "sick")
        return Healthstatus::SICK;
    else if (sh == "dead")
        return Healthstatus::DEAD;
    else
        return Healthstatus::UNKNOWN;
}