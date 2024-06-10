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
     * consumes a river system and returns true if any river in the system has a pH less than 6.5 or greater than 8.5,
     * @return true or false
     */
    bool unhealthy() {
        return unhealthy(this);
    }

    /**
     * any-unhealthy?:  River -> Boolean
     * consumes a river and produces true if the river's ph is under 6.5 or over 8.5,
     * or if the DO is less than 6ppm
     * @return true or false
     */
    bool unhealthy(Rivers* rivers) {
        if (bad_numbers(rivers)) {
            return true;
        } else if (unhealthy_trib(this->getRivers().begin(), this->getRivers().end())) {
            return true;
        } else {
            return false;
        }
    }

    bool unhealthy_trib(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end) {
        if (begin == end) {
            return false;
        }
        Rivers* river = *begin;
        if (bad_numbers(river)) {
            return true;
        } else if (unhealthy_trib(++begin, end) || unhealthy_trib(river->getRivers().begin(), river->getRivers().end())) {
            return true;
        } else {
            return false;
        }
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
        } else {
            return false;
        }
    }

    /**
     * lower-all-ph:  River -> River
     * consumes a river system and produces a river system the same as the original,
     * except all pH readings are 0.1 lower
     * @return Rivers*
     */
    Rivers* lower_all_ph() {
        Rivers* newRivers = new Rivers();
        return lower_all_ph(this, newRivers);
    }

    /**
     * lower-all-ph:  River -> River
     * consumes a river system and produces a river system the same as the original,
     * except all pH readings are 0.1 lower
     * @return Rivers*
     */
    Rivers* lower_all_ph(Rivers* rivers, Rivers* newRivers) {
        list<Rivers*> temp;
        list<Rivers*> nR = update_ph(rivers->getRivers().begin(), rivers->getRivers().end(), temp);
        return new Rivers(rivers->getRiverName(), rivers->getPh() - .1, rivers->getDo(), nR);
    }

    list<Rivers*> update_ph(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end, list<Rivers*> newRivers) {
        if (begin == end) {
            return newRivers;
        }
        Rivers* river = *begin;
        river->setPh(river->getPh() - 0.1);
        if (!river->getRivers().empty()) {
            list<Rivers*> temp;
            list<Rivers*> nR = update_ph(river->getRivers().begin(), river->getRivers().end(), temp);
            river->setRivers(nR);
        }
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
    Rivers* find_subsystem(string name) {
        return find_subsystem(this, name);
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
        Rivers* out = find_in_list(rivers->getRivers().begin(), rivers->getRivers().end(), name);
        return out;
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
            return NULL;
        }
        Rivers* river = *begin;
        if (river->getRiverName() == name) {
            return river;
        } else if (find_in_list(++begin, end, name) != NULL) {
            return find_in_list(begin, end, name);
        } else if (find_in_list(river->getRivers().begin(), river->getRivers().end(), name) != NULL) {
            return find_in_list(river->getRivers().begin(), river->getRivers().end(), name);
        } else {
            return NULL;
        }
    }

    /**
     * print out the rivers with indented (4 space) for the sub-rivers.
     * @param rivers
     * @param level
     */
    void print() {
        print(this);
    }

    /**
     * print out the rivers with indented (4 space) for the sub-rivers.
     * @param rivers
     * @param level
     */
    void print(Rivers* rivers, int level=0) {
        if (rivers == NULL) {
            return;
        }
        printSpaces(0, level);
        std::cout << rivers->getRiverName() << std::endl;
        if (!rivers->getRivers().empty()) {
            print(rivers->getRivers().begin(), rivers->getRivers().end(), level + 1);
        }
    }

    void print(list<Rivers*>::const_iterator begin, list<Rivers*>::const_iterator end, int level) {
        if (begin == end) {
            return;
        }
        printSpaces(0, level);
        Rivers* river = *begin;
        std::cout << river->getRiverName() << std::endl;
        print(river->getRivers().begin(), river->getRivers().end(), level + 1);
        print(++begin, end, level);
    }

    void printSpaces(int start, int level) {
        std::cout << "    ";
        if (start == level) {
            return;
        }
        printSpaces(start + 1, level);
    }
    
private:
    string river_name;
    double pH;
    double DO;
    list<Rivers*> rivers;

};


#endif //CSC211CH07RIVERSWPI_RIVERS_H
