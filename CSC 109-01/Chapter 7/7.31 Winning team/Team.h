/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef TEAMH
#define TEAMH

#include <string>

class Team {
    private:
        std::string name;
        int wins;
        int losses;

    public:
        void SetName(std::string teamName);

        void SetWins(int teamWins);

        void SetLosses(int teamLosses);

        std::string GetName() const;

        int GetWins() const;

        int GetLosses() const;

        double GetWinPercentage() const;

        void PrintStanding();
};

#endif
