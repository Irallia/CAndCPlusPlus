#include <tuple>
#include <deque>
#include <set>
#include <iostream>
#include <algorithm>

#include "healthstatus.hpp"

using Patient = std::tuple<size_t, std::string, Healthstatus>;

// patient-id (0-1'000'000), name, healthstatus ("healthy", "sick", "dead").
std::deque<Patient> PATIENTS{};

// ToDo:
size_t DELETED = 0;
size_t ID = 0;

std::deque<Patient>::iterator findPatientId(size_t patientId)
{
    auto lambdaFindPatientId = [patientId] (auto const & p) { return std::get<0>(p) == patientId; };
    std::deque<Patient>::iterator pos = std::find_if(PATIENTS.begin(), PATIENTS.end(), lambdaFindPatientId);
        return pos;
}

void addPatient()
{
    std::cout << "Please enter the NAME (one word) and the HEALTHSTATUS [healthy, sick, dead] of the patient.\n";
    std::string name{};
    std::string sHealthstatus{};
    std::cin >> name >> sHealthstatus;
    Patient const patient{ID, name, string2healthstatus(sHealthstatus)};

    auto findPatient = [name] (auto const & p) { return std::get<1>(p) == name; };
    std::deque<Patient>::iterator pos = std::find_if(PATIENTS.begin(), PATIENTS.end(), findPatient);
    // std::deque<Patient>::iterator pos = std::find(PATIENTS.begin(), PATIENTS.end(), patient);

    if (pos != PATIENTS.end()) {    // patient already in the deque!
        if (std::get<2>(*pos) != string2healthstatus(sHealthstatus)) {
            std::cout << "The patient " << name << " is already in the database, "
                        << "do you want to update the HEALTHSTATUS from "
                        << healthstatus2string(std::get<2>(*pos)) << " to " << sHealthstatus
                        <<"[u], give another name [c] or do nothing [n]?\n";
            // TODO !!!
        }                           // else: do nothing
    } else {                        // else: add patient
        PATIENTS.push_back(patient);
        std::cout << "The patient " << name << " got the id=" << ID << "\n";
        ID++;
    }
}

void deletePatient()
{
    std::cout << "Please enter the ID (0-1'000'000) of the patient you want to delete.\n";
    size_t patientId;
    std::cin >> patientId;

    PATIENTS.erase(findPatientId(patientId));
    DELETED++;
}

void printPatient()
{
    std::cout << "Please enter the ID (0-1'000'000) of the patient you want to print.\n";
    size_t patientId;
    std::cin >> patientId;

    auto & [specificId, specificName, specificHealthstatus] = *findPatientId(patientId);
    std::cout << "The Patient " << specificName << " with the id: " << specificId << " is "
                << healthstatus2string(specificHealthstatus) << ".\n";
}

int main()
{
    std::set<char> options{'a', 'd', 'p', 'q'};

    char option;
    char quit;

    while(quit != 'q') {
        std::cout << "------------------------------------------------------------------------\n"
                    << "Please choose on of the following options:\n\tAdd new patient record [a]"
                    << "\n\tDelete patient record by id [d]\n\tPrint record by id [p]\n\tQuit [q]\n";
        std::cin >> option;

        if (options.find(option) == options.end())
            std::cout << "Not a valid option.";
        else if (option == 'a')
            addPatient();
        else if (option == 'd')
            deletePatient();
        else if (option == 'p')
            printPatient();
        else // (option == 'q')
            quit = 'q';
    }

}