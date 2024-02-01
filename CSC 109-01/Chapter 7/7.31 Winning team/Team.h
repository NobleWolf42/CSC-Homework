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
        void SetTeamName(std::string teamName);

        void SetTeamWins(int teamWins);

        void SetTeamLosses(int teamLosses);

        std::string GetTeamName() const;

        int GetTeamWins() const;

        int GetTeamLosses() const;

        double GetWinPercentage() const;

        void PrintStanding();
};

#endif
