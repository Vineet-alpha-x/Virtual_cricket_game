 #include "Game.h"
using namespace std;

int main() {
    system("COLOR F0");
	 Game game;
	 game.welcome();
	 cout<<"\n\n     Press Enter to continue ! ";
     getchar();

	 game.showAllPlayers();

	 cout<<"\n\n     Press Enter to continue ! ";
	  getchar();
	  cout<<endl;

      game.selectPlayers();
      game.showTeams();
      cout<<"\n\n     Press Enter to continue ! ";
     getchar();
	  cout<<endl;

     game.letsToss();
     cout<<"\n\n     Press Enter to continue ! ";
     getchar();

     game.toss();











	return 0;
}
