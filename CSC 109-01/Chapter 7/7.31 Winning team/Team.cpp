/*
Copyright 2024
Author: Ben Carpenter
*/

#include <iostream>
#include <iomanip> 
#include "Team.h"

void Team::SetName(std::string teamName) {
    name = teamName;
}

void Team::SetWins(int teamWins) {
    wins = teamWins;
}

void Team::SetLosses(int teamLosses) {
    losses = teamLosses;
}

std::string Team::GetName() const {
    return name;
}

int Team::GetWins() const {
    return wins;
}

int Team::GetLosses() const {
    return losses;
}

double Team::GetWinPercentage() const {
    double winPercent;

    winPercent = static_cast<double>(wins) / (wins + losses);

    return winPercent;
}

void Team::PrintStanding() {
    std::cout << "Win percentage: " << GetWinPercentage() << std::endl;

    if (GetWinPercentage() >= 0.5) {
        std::cout << "Congratulations, Team " << name << " has a winning average!" << std::endl;
    } else {
        std::cout << "Team " << name << " has a losing average." << std::endl;
    }
}