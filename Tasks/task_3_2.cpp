#include <deque>
#include <tuple>
#include <set>
#include <iostream>
#include <algorithm>

#include "healthstatus.hpp"

// patient-id (0-1'000'000), name, healthstatus ("healthy", "sick", "dead").
std::deque<std::tuple<uint64_t, std::string, Healthstatus>> PATIENTS{};

std::deque<std::tuple<uint64_t, std::string, Healthstatus>>::iterator findPatientId(uint64_t patientId)
{
    auto lambdaFindPatientId = [patientId] (auto const & p) { return std::get<0>(p) == patientId; };
    std::deque<std::tuple<uint64_t, std::string, Healthstatus>>::iterator pos
        = std::find_if(PATIENTS.begin(), PATIENTS.end(), lambdaFindPatientId);
        return pos;
}

int main()
{
    std::set<char> options{'a', 'd', 'p', 'q'};

    char option;
    char quit;

    while(quit != 'q') {
        std::cout << "Please choose on of the following options:\n\tAdd new patient record [a]"
                    << "\n\tDelete patient record by id [d]\n\tPrint record by id [p]\n\tQuit [q]\n";
        std::cin >> option;

        if (options.find(option) == options.end())
            std::cout << "Not a valid option.";
        else if (option == 'a')
        {
            uint64_t id = 0;
            std::cout << "Please enter the NAME (one word) and the HEALTHSTATUS [healthy, sick, dead] of the patient.\n";
            std::string name{};
            std::string sHealthstatus{};
            std::cin >> name >> sHealthstatus;
            std::tuple<uint64_t, std::string, Healthstatus> const patient{id, name, string2healthstatus(sHealthstatus)};

            auto findPatient = [name] (auto const & p) { return std::get<1>(p) == name; };
            std::deque<std::tuple<uint64_t, std::string, Healthstatus>>::iterator pos
                = std::find_if(PATIENTS.begin(), PATIENTS.end(), findPatient);
            // std::deque<std::tuple<uint64_t, std::string, Healthstatus>>::iterator pos
            //     = std::find(PATIENTS.begin(), PATIENTS.end(), patient);

            if (pos != PATIENTS.end()) {    // patient already in the deque!
                if (std::get<2>(*pos) != string2healthstatus(sHealthstatus)) {
                    std::cout << "The patient " << name << " is already in the database, "
                                << "do you want to update the HEALTHSTATUS from "
                                << healthstatus2string(std::get<2>(*pos)) << " to " << sHealthstatus
                                <<"[u], change the name [c] or do nothing [n]?\n";
                    // TODO !!!
                }                           // else: do nothing
            } else {                        // else: add patient
                PATIENTS.push_back(patient);
                id++;
            }
        }
        else if (option == 'd')
        {
            std::cout << "Please enter the ID (0-1'000'000) of the patient you want to delete.\n";
            uint64_t patientId;
            std::cin >> patientId;

            PATIENTS.erase(findPatientId(patientId));
        }
        else if (option == 'p')
        {
            std::cout << "Please enter the ID (0-1'000'000) of the patient you want to print.\n";
            uint64_t patientId;
            std::cin >> patientId;

            auto & [specificId, specificName, specificHealthstatus] = *findPatientId(patientId);
            std::cout << "The Patient " << specificName << " with the id: " << specificId << " is "
                        << healthstatus2string(specificHealthstatus) << ".\n";
        }
        else // (option == 'q')
            quit = 'q';
    }

}