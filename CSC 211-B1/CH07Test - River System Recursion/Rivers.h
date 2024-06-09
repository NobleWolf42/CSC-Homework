/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CSC211CH07RIVERSWPI_RIVERS_H
#define CSC211CH07RIVERSWPI_RIVERS_H

#include <list>
#include <string>
#include <iostream>

using std::string;
using std::list;

class Rivers {

public:
    Rivers() {}  // default constructor

    Rivers(string name, double ph, double DO, list<Rivers*> rivers) {
        this->river_name = name;
        this->pH = ph;
        this->DO = DO;
        this->rivers = rivers;
    }

    ~Rivers() {}

    const string &getRiverName() const {
        return river_name;
    }

    void setRiverName(const string &riverName) {
        river_name = riverName;
    }

    double getPh() const {
        return pH;
    }

    void setPh(double pH) {
        this->pH = pH;
    }

    double getDo() const {
        return DO;
    }

    void setDo(double DO) {
        this->DO = DO;
    }

    const list<Rivers*> &getRivers() const {
        return rivers;
    }

    void setRivers(const list<Rivers*> &rivers) {
        this->rivers = rivers;
    }

    void make_river(Rivers* river) {
        rivers.push_back(river);
    }

    /**
     * checks a river system with an acidic river, and also with a river considered non-acidic
     * (on the boundary at acid_level.  The default is 7.)
     * the acidic river is listed, the river with pH=6.5 is not
     * @return name of the rivers.
     */
    string list_acidic_rivers() {
        return list_acidic_rivers(this);
    }

    /**
     * any-unhealthy?:  River -> Boolean
     * consumes a river system and returns true if any river in the system has a pH less than 6.5 or greater than 8.5,
     * @return true or false
     */
    bool unhealthy() {
        return unhealthy_recursive(this);
    }

    /**
     * lower-all-ph:  River -> River
     * consumes a river system and produces a river system the same as the original,
     * except all pH readings are 0.1 lower
     * @return Rivers*
     */
    Rivers* lower_all_ph() {
        lower_all_ph_recursive(this);
        return this;
    }

    /**
     * find-subsystem:  River String-> River OR #false
     * consumes a river system and the name of the river.  The function returns that
     * part of the system that has the named river as its root (or returns false
     * if there is no river in the system with the given name)
     * @param a
     * @return river or NULL
     */
    Rivers* find_subsystem(string name) {
        if (this->getRiverName() == name) {
            return this;
        }
        return find_subsystem_recursive(rivers, name);
    }


    /**
     * print out the rivers with indented (4 space) for the sub-rivers.
     * @param rivers
     * @param level
     */
    void print() {
        print(this, 0);
    }



    /**
     * checks a river system with an acidic river, and also with a river considered non-acidic
     * (on the boundary at acid_level.  The default is 7.0)
     * the acidic river is listed, the river with pH=7.0 is not
     * @return name of the rivers.
     */
    string list_acidic_tributaries(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end) {
        if (begin == end) {
            return "";
        }
        Rivers* front = *begin++;
        return list_acidic_rivers(front) + list_acidic_tributaries(begin, end);
    }

    string list_acidic_rivers(Rivers* rivers) {
        list<Rivers*>::const_iterator begin = rivers->getRivers().begin();
        list<Rivers*>::const_iterator end = rivers->getRivers().end();
        if (rivers->pH < 7) {
            string rn = rivers->river_name;
            return rn + " " + list_acidic_tributaries(begin, end);
        }
        return list_acidic_tributaries(begin, end);
    }

    /**
     * any-unhealthy?:  River -> Boolean
     * consumes a river and produces true if the river's ph is under 6.5 or over 8.5,
     * or if the DO is less than 6ppm
     * @return true or false
     */
    bool unhealthy(Rivers* rivers) {
        if (rivers->getPh() < 6.5 || rivers->getPh() > 8.5) {
            return true;
        }
        for (Rivers* subRiver : rivers->getRivers()) {
            if (unhealthy(subRiver)) {
                return true;
            }
        }
        return false;
    }

    bool unhealthy_trib(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end) {
        if (begin == end) {
            return false;
        }
        Rivers* river = *begin;
        if (river->getPh() < 6.5 || river->getPh() > 8.5) {
            return true;
        }
        return unhealthy_trib(++begin, end);
    }

    /**
     *  consumes a river and produces true if the river's ph is under 6.5 or over 8.5,
     *  or if the DO is less than 6ppm
     * @param river
     * @return true or false
     */
    bool bad_numbers(Rivers* river) {
        if (river->getPh() < 6.5 || river->getPh() > 8.5 || river->getDo() < 6) {
            return true;
        }
        for (Rivers* subRiver : river->getRivers()) {
            if (bad_numbers(subRiver)) {
                return true;
            }
        }
        return false;
    }

    /**
     * lower-all-ph:  River -> River
     * consumes a river system and produces a river system the same as the original,
     * except all pH readings are 0.1 lower
     * @return Rivers*
     */
    Rivers* lower_all_ph(Rivers* rivers, Rivers* newRivers) {
        rivers->setPh(rivers->getPh() - 0.1);
        for (Rivers* subRiver : rivers->getRivers()) {
            lower_all_ph(subRiver, newRivers);
        }
        return rivers;
    }

    list<Rivers*> update_ph(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end, list<Rivers*> newRivers) {
        if (begin == end) {
            return newRivers;
        }
        Rivers* river = *begin;
        river->setPh(river->getPh() - 0.1);
        newRivers.push_back(river);
        return update_ph(++begin, end, newRivers);
    }


    /**
     * find-subsystem:  River String-> River OR #false
     * consumes a river system and the name of the river.  The function returns that
     * part of the system that has the named river as its root (or returns false
     * if there is no river in the system with the given name)
     * @param a
     * @return river or NULL
     */
    Rivers* find_subsystem(Rivers* rivers, string name) {
        if (rivers->getRiverName() == name) {
            return rivers;
        }
        for (Rivers* subRiver : rivers->getRivers()) {
            Rivers* result = find_subsystem(subRiver, name);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }

    /**
     * find-in-list:  ListOfRiver String -> River OR #false
     * consumes a list of rivers and the name of a river.  The function returns the river system in the list
     * that has the river with the given name as its root.  If no such named river exists, the function returns
     * false.
     * @param alor
     * @param name
     * @return River or NULL
     */
    Rivers* find_in_list(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end, string name) {
        if (begin == end) {
            return nullptr;
        }
        Rivers* river = *begin;
        if (river->getRiverName() == name) {
            return river;
        }
        return find_in_list(++begin, end, name);
    }

    /**
     * print out the rivers with indented (4 space) for the sub-rivers.
     * @param rivers
     * @param level
     */
    void print(Rivers* rivers, int level=0) {
        for (int i = 0; i < level; i++) {
            std::cout << "    ";
        }
        std::cout << rivers->getRiverName() << std::endl;
        for (Rivers* subRiver : rivers->getRivers()) {
            print(subRiver, level + 1);
        }
    }

    void print(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end, int level) {
        if (begin == end) {
            return;
        }
        Rivers* river = *begin;
        for (int i = 0; i < level; i++) {
            std::cout << "    ";
        }
        std::cout << river->getRiverName() << std::endl;
        print(river->getRivers().begin(), river->getRivers().end(), level + 1);
        print(++begin, end, level);
    }

    void static setAcidLevel(double acidLevel) {
        acid_level = acidLevel;
    }
    
private:
    string river_name;
    double pH;
    double DO;
    list<Rivers*> rivers;
    static double acid_level;

    bool unhealthy_recursive(Rivers* rivers) {
        if (rivers->getPh() < 6.5 || rivers->getPh() > 8.5) {
            return true;
        }
        for (auto river : rivers->getRivers()) {
            if (unhealthy_recursive(river)) {
                return true;
            }
        }
        return false;
    }

    void lower_all_ph_recursive(Rivers* rivers) {
        rivers->setPh(rivers->getPh() - 0.1);
        for (auto river : rivers->getRivers()) {
            lower_all_ph_recursive(river);
        }
    }

    Rivers* find_subsystem_recursive(Rivers* rivers, string name) {
        for (auto river : rivers->getRivers()) {
            if (river->getRiverName() == name) {
                return river;
            }
            Rivers* result = find_subsystem_recursive(river, name);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }

    void print_recursive(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end, int level) {
        if (begin == end) {
            return;
        }
        for (int i = 0; i < level; ++i) {
            std::cout << "    ";
        }
        std::cout << (*begin)->getRiverName() << std::endl;
        print_recursive((*begin)->getRivers().begin(), (*begin)->getRivers().end(), level + 1);
        print_recursive(++begin, end, level);
    }

};


#endif //CSC211CH07RIVERSWPI_RIVERS_H
