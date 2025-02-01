//
// Created by hloi on 11/5/2021.
//

#include "Rivers.h"
#include <string>
using namespace std;

const string &Rivers::getRiverName() const {
    return river_name;
}

void Rivers::setRiverName(const string &riverName) {
    river_name = riverName;
}

double Rivers::getPh() const {
    return pH;
}

void Rivers::setPh(double pH) {
    this->pH = pH;
}

double Rivers::getDo() const {
    return DO;
}

void Rivers::setDo(double DO) {
    this->DO = DO;
}

const list<Rivers*> &Rivers::getRivers() const {
    return rivers;
}

void Rivers::setRivers(const list<Rivers*> &rivers) {
    this->rivers = rivers;
}

Rivers::Rivers(string name, double ph, double DO, list<Rivers*> rivers) {
    this->river_name = name;
    this->pH = ph;
    this->DO = DO;
    this->rivers = rivers;
}

void Rivers::make_river(Rivers* river) {
    rivers.push_back(river);
}

string Rivers::list_acidic_rivers(Rivers* rivers) {
    list<Rivers*>::const_iterator begin = rivers->getRivers().begin();
    list<Rivers*>::const_iterator end = rivers->getRivers().end();
    if (rivers->pH < 7) {
        string rn = rivers->river_name;
        return rn + " " + list_acidic_tributaries(begin, end);
    }
    return list_acidic_tributaries(begin, end);

}

string Rivers::list_acidic_tributaries(list<Rivers*>::const_iterator begin,
                                       list<Rivers*>::const_iterator end) {
    if (begin == end) {
        return "";
    }
    Rivers* front = *begin++;
    return list_acidic_rivers(front) + list_acidic_tributaries(begin, end);
}

string Rivers::list_acidic_rivers() {
    return list_acidic_rivers(this);
}
