#include "Game.h"
using namespace std;
Game :: Game(){
	isFirstInnings = false;
	      playersPerTeam = 4;
		  maxBalls = 6;
		  totalPlayers = 11;
		  players[0] = "Virat";
		  players[1] = "Rohit";
		  players[2] = "Dhawan";
		  players[3] = "Pant";
		  players[4] = "Kartik";
		  players[5] = "KLrahul";
		  players[6] = "Jadeja";
		  players[7] = "Hardik";
		  players[8] = "Bumrah";
		  players[9] = "Bkumar";
		  players[10] = "Ishant";

		  teamA.name = "Team-A";
		  teamB.name = "Team-B";

}
void Game::welcome(){
	cout<<"                       <___*==============CRIC-IN================*___>"<<endl;
	cout<<"                       |_____________________________________________|\n";
	cout<<"                       |                                             |\n";
	cout<<"                       |                                             |\n";
	cout<<"                       |     ::Welcome to virtual cricket game::     |\n";
	cout<<"                       |                                             |\n";
	cout<<"                       |                                             |\n";
	cout<<"                       |_____________________________________________|\n\n";
	cout<<"                    <____*===============INSTRUCTIONS==============*____>\n";
	cout<<"                    |                                                  |\n";
	cout<<"                    |                                                  |\n";
	cout<<"                    |  1. Create two teams(Team-A and Team-B with 4    |\n";
	cout<<"                    |    players each)from a given pool of 11 players. |\n";
	cout<<"                    |                                                  |\n";
	cout<<"                    |  2. Lead the toss and decide the choice of play. |\n";
	cout<<"                    |                                                  |\n";
	cout<<"                    |  3. Each innings will be of 6 balls.             |\n";
	cout<<"                    |                                                  |\n";
	cout<<"                    |__________________________________________________|\n";



}
void Game :: showAllPlayers(){
	cout<<"            *========================================*\n";
	cout<<"            |          Pool of 11 players.           |\n";
	cout<<"            |________________________________________|\n";
	cout<<endl<<endl;
	for(int i=0;i<totalPlayers;i++){
		cout<<"       ["<<i<<"]  "<<players[i]<<endl;
	}
}
int Game :: takeIntegerInput(){
    int n;
    while(!(cin>>n))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"\nPlease enter a valid integer value. Try again : " ;
    }
    return n;
}
bool Game :: validateSelectedPlayer(int index)
{
    int n;
    vector<player>players;
    players = teamA.players;
    n = players.size();
    for(int i=0;i<n;i++)
    {
        if (players[i].id == index)
        {
            return  false;
        }
    }
    players = teamB.players;
    n = players.size();
    for(int i =0;i<n;i++)
    {
        if(players[i].id==index)
        {
            return false;
        }
    }
    return true;
}
void Game :: selectPlayers(){
    for(int i=0;i<playersPerTeam;i++)
    {
        playerSelectionA:
        cout<<"  select player " <<i+1<<" of Team-A : " ;
        int playerIndexTeamA = takeIntegerInput();
        if(playerIndexTeamA<0 || playerIndexTeamA>10)
        {
            cout<<endl<<"  Please select from the given players "<<endl;
            goto playerSelectionA;
        }else if(!(validateSelectedPlayer(playerIndexTeamA)))
        {
            cout<<"\nThe player has already been selected. Select another player! \n" <<endl;
            goto playerSelectionA;
        }
        else
        {
    player teamAPlayer;
    teamAPlayer.id = playerIndexTeamA;
    teamAPlayer.name = players[playerIndexTeamA];
    teamA.players.push_back(teamAPlayer);
        }


     playerSelectionB:
    cout<<"  select player " <<i+1<<" of Team-B : "  ;
        int playerIndexTeamB = takeIntegerInput();
        if(playerIndexTeamA<0 || playerIndexTeamA>10)
        {
            cout<<endl<<"  Please select from the given players "<<endl;
            goto playerSelectionB;
        }else if(!(validateSelectedPlayer(playerIndexTeamB)))
        {
            cout<<"\nThe player has already been selected. Select another player!"<<endl;
            goto playerSelectionB;
        }
        else
        {
            player teamBPlayer;
    teamBPlayer.id = playerIndexTeamB;
    teamBPlayer.name = players[playerIndexTeamB];
    teamB.players.push_back(teamBPlayer);
        }

    cout<<endl;

    }
}
void Game :: showTeams(){
    vector<player>teamAPlayers = teamA.players;
    vector<player>teamBPlayers = teamB.players;

    cout<<endl<<endl;
    cout<<"-------------------------\t\t--------------------------"<<endl;
    cout<<"|=======  TEAM A  ======|\t\t|======   TEAM B   =====|"<<endl;
    cout<<"-------------------------\t\t-------------------------"<<endl;
    for(int i =0;i<playersPerTeam;i++)
    {
        cout<<"|\t"<<"["<<i<<"]"<<teamAPlayers[i].name<<"\t|"
             "\t\t"
             "|\t"<<"["<<i<<"]"<<teamBPlayers[i].name<<"\t|"<<endl;

    }
    cout<<"------------------------\t\t-------------------------"<<endl;


}
void Game :: letsToss()
{
    cout<<"----------------------------------------------"<<endl;
    cout<<"|=================LET'S TOSS=================|"<<endl;
    cout<<"----------------------------------------------"<<endl;
	  cout<<endl;
	  cout<<"Tossing the coin..."<<endl;

}
void Game :: toss()
{
    int val,choice;
    srand(time(NULL));
    val = rand()%2;
     switch(val) {

        case 0:
            cout << "\n\t\t\t\tTeam-A won the toss\n";

            break;

        case 1:
            cout << "\n\t\t\t\tTeam-B won the toss\n";

            break;
    }
}
void Game :: tossChoices(Team tossWinnerTeam) {  /* Deciding to bat or ball for the winning team
                                                    and Initializing batting team and bowling team.
                                                  */
    int choice;
    cout << "\n\t\t\t\t||| CHOOSE |||\n";
    cout << "\t\t\t\t1.Batting\n";
    cout << "\t\t\t\t2.Bowling\n";
    cout << "\t\t\t\tEnter the choice(1 for batting and 2 for bowling): ";

    choice = takeIntegerOnly();

    switch(choice) {

        case 1:
            cout << "\n\t\t\t\t" <<  tossWinnerTeam.teamName << " won the toss and decided to bat first\n";
            if(tossWinnerTeam.teamName.compare("Team-A") == 0) {

                battingTeam = &teamA;   // Initializing batting team.
                bowlingTeam = &teamB;   // Initializing bowling team.
            }
            else {

                battingTeam = &teamB;
                bowlingTeam = &teamA;
            }
            break;
        case 2:
            cout << "\n\t\t\t\t" << tossWinnerTeam.teamName << "won the toss and decided to ball first\n";
            if(tossWinnerTeam.teamName.compare("Team-A") == 0) {

                bowlingTeam = &teamA;
                battingTeam = &teamB;
            }
            else {

                bowlingTeam = &teamB;
                battingTeam = &teamA;
            }
            break;
        default:
            cout << "\n\t\t\t\tERROR!!! please enter the valid choice : ";
            tossChoices(tossWinnerTeam);
            break;
    }
}

void Game :: startFirstInnings() {

    cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|===================================== FIRST-INNINGS-STARTS ====================================|\n";
    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n";

    isFirstInnings = true;

    initializingPlayers();
    playInnings();
}

void Game :: startSecondInnings() {

    cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
    cout << "\t\t\t\t|                                                                                               |\n";
    cout << "\t\t\t\t|===================================== SECOND-INNINGS-STARTS ===================================|\n";
    cout << "\t\t\t\t|_______________________________________________________________________________________________|\n";

    isFirstInnings = false;

    Team tempTeam = *battingTeam;
    *battingTeam = *bowlingTeam;
    *bowlingTeam = tempTeam;

    initializingPlayers();
    playInnings();
}
void Game :: initializingPlayers() {

    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];

    cout << "\n\t\t\t\t" << battingTeam->teamName << " : " << batsman->name << " is going to bat\n";
    cout << "\n\t\t\t\t" << bowlingTeam->teamName << " : " << bowler->name << " is going to ball\n";
}

void Game :: playInnings() {

    int i;

    for(i = 0; i < maxBalls; i++) {

        cout << "\n\t\t\t\tPress enter to ball...\n";
        getchar();

        bat();


    }
}

void Game :: bat() {

    int runsScored;

    srand(time(NULL));

    runsScored = rand() % 7;

    // Updating batting specs
    batsman->runsScored = batsman->runsScored + runsScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;
    battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;

    // Updating bowling specs
    bowler->ballsBowled = bowler->ballsBowled + 1;
    bowler->runsGiven = bowler->runsGiven + runsScored;
    bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;

    if(runsScored != 0) {

        cout << "\n\t\t\t\t" << bowler->name << " to " << batsman->name << " " << runsScored << " runs scored!.\n";
    }
    else {

        cout << "\n\t\t\t\t" << bowler->name << " to " << batsman->name << " ! OUT !\n";

        bowler->wicketsTaken = bowler->wicketsTaken + 1;
        battingTeam->wicketsLost = battingTeam->wicketsLost + 1;

        showScoreCard();

        int newIndex = battingTeam->wicketsLost;
        batsman = &battingTeam->players[newIndex];
    }
}

void Game :: showScoreCard() {

    cout << "\n\t\t\t\t|=============================== BATTING STATS ================================|";
    cout << "\n\t\t\t\t________________________________________________________________________________";
    cout << "\n\t\t\t\t" << batsman->name << " : " << batsman->runsScored << " ( " << batsman->ballsPlayed << " )";
    cout << "\n\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
    cout << "\n\t\t\t\t" << battingTeam->teamName << " : " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost;
    cout << "\n\t\t\t\t________________________________________________________________________________";

    cout << "\n\t\t\t\t|=============================== BOWLING STATS ================================|";
    cout << "\n\t\t\t\t________________________________________________________________________________";
    cout << "\n\t\t\t\t" << bowler->name << " : " << bowler->runsGiven << " ( " << bowler->ballsBowled << " )";
    cout << "\n\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
    cout << "\n\t\t\t\t" << bowlingTeam->teamName << " : " << battingTeam->totalRunsScored << " ( " << bowlingTeam->totalBallsBowled << " )";
    cout << "\n\t\t\t\t________________________________________________________________________________";
}

bool Game :: validateInnings() {

    if(isFirstInnings) {

        if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls ) {

            cout << "\t\t\t\t _______________________________________________________________________________________________ \n";
            cout << "\t\t\t\t|                                                                                               |\n";
            cout << "\t\t\t\t|====================================== FIRST-INNINGS-ENDS =====================================|\n";
            cout << "\t\t\t\t|_______________________________________________________________________________________________|\n";

            cout << "\t\t\t\t|============================== " << battingTeam->teamName << " ===============================|\n";
            cout << "\t\t\t\t\t\t\t" << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << "\n";

            cout << "\n\t\t\t\t\t\t!!! RESULT !!!";
            cout << "\n\t\t\t\t" << bowlingTeam->teamName << " needs to  score " << battingTeam->totalRunsScored + 1  << " runs ";
            cout << " in " << maxBalls << " balls \n";

            return false;
            }
        }
        else {

            if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {

        	    cout << battingTeam->teamName << " WON THE MATCH" << "\n\n";
        	    return false;
            }
            else if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

                if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) {

            	cout << bowlingTeam->teamName << " WON THE MATCH" << "\n\n";
            }
            else {

            	cout << "MATCH DRAW" << "\n\n";
            }
            return false;
        }

    return true;
}

void Game :: showMatchSummary() {

	cout << "\t\t\t\t ||| MATCH ENDS ||| " << "\n\n";

    cout << battingTeam->teamname << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << "\n";

    cout << "\t\t\t\t==========================================" << "\n";
    cout << "\t\t\t\t| PLAYER \t BATTING \t BOWLING |" << "\n";

    for (int j = 0; j < playersPerTeam; j++) {
    	Player player = battingTeam->players[j];
    	cout << "\t\t\t\t|----------------------------------------|" << "\n";
    	cout << "\t\t\t\t| " << "[" << j << "] " << player.name << "  \t ";
        cout << player.runsScored << "(" << player.ballsPlayed << ") \t\t ";
		cout << player.ballsBowled << "-" << player.runsGiven << "-";
		cout << player.wicketsTaken << "\t |" << "\n";
    }
    cout << "\t\t\t\t==========================================" << "\n\n";

    cout << bowlingTeam->teamName << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << "\n";

    cout << "\t\t\t\t==========================================" << "\n";
    cout << "\t\t\t\t| PLAYER \t BATTING \t BOWLING |" << "\n";

    for (int i = 0; i < playersPerTeam; i++) {
    	Player player = bowlingTeam->players[i];
        cout << "\t\t\t\t|----------------------------------------|" << "\n";
        cout << "\t\t\t\t| " << "[" << i << "] " << player.name << "  \t ";
        cout << player.runsScored << "(" << player.ballsPlayed << ") \t\t ";
        cout << player.ballsBowled << "-" << player.runsGiven << "-";
		cout << player.wicketsTaken << "\t |" << "\n";
    }
    cout << "\t\t\t\t==========================================" << "\n\n";
}
