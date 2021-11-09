// Copyright (c) 2021 Igor All rights reserved
//
// Created by: Igor
// Created on: Nov 2021
// this program calculates the volume of a cylinder

#include <algorithm>

#include <cstring>
#include <ctype.h>
#include <iostream>
#include <sstream>


std::string adress1(std::string name,
                            std::string question,
                            std::string numberOfHouseFromUser,
                            std::string nameOfStreet,
                            std::string city,
                            std::string province,
                            std::string pc,
                            std::string numberOfFlatFromUser  ) {
    // this is function

    std::string apt_street_num = "";
    std::string adress;
    std::stringstream aptStreetNum;
    std::stringstream ssupper;
    std::locale loc;
    std::string str;

    aptStreetNum<< "\n" << name << "\n";
    if (question == "y") {
        aptStreetNum << numberOfFlatFromUser << "-" << numberOfHouseFromUser;
    } else {
        aptStreetNum<< numberOfHouseFromUser;
    }
    aptStreetNum<< " " << nameOfStreet << std::endl;
    aptStreetNum<< city << " " << province << " " << pc;

    str = aptStreetNum.str();
    std::for_each(str.begin(), str.end(), [](char & c) { c = ::toupper(c);});



    return str;
}



int main() {
    // this function gets adress, name, question, numberOfHouseFromUser,
    //   nameOfStreet, city, province, pc, numberOfFlatFromUser

    std::string numberOfFlatFromUser = "";
    std::string numberOfHouseFromUser;
    std::string nameOfStreet;
    std::string city;
    std::string province;
    std::string pc;
    std::string name;
    std::string question;
    std::string adress;

    // input
    std::cout << "Enter your full name: ";
    getline(std::cin, name);
    std::cout << "Do you live in an apartment (y/n): ";
    getline(std::cin, question);

    if (question == "y") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, numberOfFlatFromUser);
        std::cout << "Enter your street number :";
        getline(std::cin, numberOfHouseFromUser);
    } else if (question == "n") {
        std::cout << "Enter your street number :";
        getline(std::cin, numberOfHouseFromUser);
    } else {
     std::cout<< "Invalid input" << std::endl;
    }

    std::cout << "Enter your street name AND type(Main St, Express Pkwy...): ";
    getline(std::cin, nameOfStreet);

    std::cout << "Enter your city: ";
    getline(std::cin, city);

    std::cout << "Enter your province (as an abreviation, ex: ON, BC...): ";
    getline(std::cin, province);

    std::cout << "Enter your postal code (123 456): ";
    getline(std::cin, pc);

    try {
        int test_int = std::stoi(numberOfHouseFromUser);

        if (numberOfFlatFromUser != "") {
            int test_int = std::stoi(numberOfHouseFromUser);
        }

        adress = adress1(
            name,
            question,
            numberOfHouseFromUser,
            nameOfStreet,
            city,
            province,
            pc,
            numberOfFlatFromUser);
        // std::cout << uppercase(adress) << std::endl;
        std::cout << adress << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "Invalid Input" << std::endl;
    }

    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
