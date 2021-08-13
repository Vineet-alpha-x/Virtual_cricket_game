 #include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include"team.h"
class Game{
public:
	Game();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std :: string players[11];
	bool isFirstInnings;
	Team teamA,teamB;
	Team *battingTeam, *bowlingTeam;
	player *batsman,*bowler;
	void welcome();
	void showAllPlayers();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelectedPlayer(int);
	void showTeams();
	void letsToss();
	void toss();
	void tossChoices(Team);
    void startFirstInnings();
    void initializingPlayers();
    void playInnings();
    void showScoreCard();
    void bat();
    bool validateInnings();
    void startSecondInnings();
    void showMatchSummary();

};

