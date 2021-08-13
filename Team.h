 #include<vector>
#include "player.h"
class Team{
public:
	Team();
	std::string name;
	int totalRunsScored;
	int wicketLost;
	int totalBallsBowled;
	std::vector<player>players;

};
