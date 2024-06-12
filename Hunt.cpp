#include <iostream>
#include "Hunt.h"
using namespace std;

Hunt::Hunt()
{
	//constructor
	int rtemp; // used for random numbers
	//Create a temporary array of Chamber pointers 
	//(this array has a local scope and will be deleted)
	Chamber* ptrArray[20];
	//Dynamically allocate 20 Chamber objects, each pointed to by a pointer in the array
	for(int i=0; i<20; i++)
	{
    		ptrArray[i] = new Chamber(i+1, nullptr, nullptr, nullptr);
	}
	//Set the Chambers to point to one another to build your game map
	//The map is based on an icosahedron (d-20), see class discussion
	ptrArray[0]->setPtrs(ptrArray[6], ptrArray[18], ptrArray[12]);
	ptrArray[1]->setPtrs(ptrArray[11], ptrArray[17], ptrArray[19]);
	ptrArray[2]->setPtrs(ptrArray[16], ptrArray[15], ptrArray[18]);
	ptrArray[3]->setPtrs(ptrArray[17], ptrArray[10], ptrArray[13]);
	ptrArray[4]->setPtrs(ptrArray[17], ptrArray[14], ptrArray[13]);
	ptrArray[5]->setPtrs(ptrArray[8], ptrArray[15], ptrArray[13]);
	ptrArray[6]->setPtrs(ptrArray[16], ptrArray[0], ptrArray[14]);
	ptrArray[7]->setPtrs(ptrArray[9], ptrArray[19], ptrArray[15]);
	ptrArray[8]->setPtrs(ptrArray[5], ptrArray[10], ptrArray[18]);
	ptrArray[9]->setPtrs(ptrArray[16], ptrArray[11], ptrArray[7]);
	ptrArray[10]->setPtrs(ptrArray[8], ptrArray[3], ptrArray[12]);
	ptrArray[11]->setPtrs(ptrArray[9], ptrArray[14], ptrArray[1]);
	ptrArray[12]->setPtrs(ptrArray[10], ptrArray[4], ptrArray[0]);
	ptrArray[13]->setPtrs(ptrArray[3], ptrArray[5], ptrArray[19]);
	ptrArray[14]->setPtrs(ptrArray[4], ptrArray[11], ptrArray[6]);
	ptrArray[15]->setPtrs(ptrArray[5], ptrArray[2], ptrArray[7]);
	ptrArray[16]->setPtrs(ptrArray[9], ptrArray[2], ptrArray[6]);
	ptrArray[17]->setPtrs(ptrArray[4], ptrArray[3], ptrArray[1]);
	ptrArray[18]->setPtrs(ptrArray[2], ptrArray[8], ptrArray[0]);
	ptrArray[19]->setPtrs(ptrArray[1], ptrArray[13], ptrArray[7]);

	//set gameOver bool to false
	gameOver = false;

	//set the player to begin in the first chamber
	player = ptrArray[0];

	//give the bats, the pit, and the wumpus a random starting chamber (not chamber 1)
	rtemp = rand()%18+1; //random values between 1 and 19, exclude 0
	wumpus = ptrArray[rtemp];
	//wumpus = ptrArray[6];
	cout<<"CHEATING: Wumpus Location: "<<wumpus->getID()<<endl;
	rtemp = rand()%18+1; //random values between 1 and 19, exclude 0
	bats = ptrArray[rtemp];
	//bats = ptrArray[18];
	cout<<"CHEATING: Bats Location: "<<bats->getID()<<endl;
	rtemp = rand()%18+1; //random values between 1 and 19, exclude 0
	pit = ptrArray[rtemp];
	//pit = ptrArray[12];
	cout<<"CHEATING: Pit Location: "<<pit->getID()<<endl;

	//set the number of arrows
	numArrows=5;
}


void Hunt::play()
{
	while(gameOver != true)
	{
		reportPosition();
		cout << "Make a door selection: " << endl;
		cout << "Door 1 leads to Chamber " << player->getDoor1ID() << endl;
		cout << "Door 2 leads to Chamber " << player->getDoor2ID() << endl;
		cout << "Door 3 leads to Chamber " << player->getDoor3ID() << endl;
		int choice;
		cin >> choice;
		
		movePlayer(choice);
	}
}

void Hunt::reportPosition()
{
	cout << "You are currently in chamber " << player->getID() << ":" << endl;
	// break these all into seperate if statements so they can all happen if they all happen to be true
	if(pit->getID() == player->getDoor1ID() || pit->getID() == player->getDoor2ID() || pit->getID() == player->getDoor3ID()) // you feel a breeze from one of the three chambers
	{
		cout << "You feel a breeze nearby." << endl;
	}
	
	if(wumpus->getID() == player->getDoor1ID() || wumpus->getID() == player->getDoor2ID() || wumpus->getID() == player->getDoor3ID()) // you smell a terrible smell
	{
		cout << "You smell a terrible smell." << endl;
	}
	
	if(bats->getID() == player->getDoor1ID() || bats->getID() == player->getDoor2ID() || bats->getID() == player->getDoor3ID()) // you hear flapping wings and rushing wind
	{
		cout << "You hear flapping wings and rushing wind." << endl;
	}
}

void Hunt::movePlayer(int val)
{
	if(val != 1 && val != 2 && val !=3) // validation to let the user know they can't enter values < 1 or values > 3
	{
		cout << "Invalid Selection!!" << endl;
	}
	else
	{
		// player is set to value passed in by copy
		if(val == 1)
		{
			player = player->getDoor1Ptr();
			if((player->getID() && wumpus->getID()) || (player->getID() && pit->getID()) || (player->getID() && bats->getID()))
			{ // if the player and the wumpus, bats, or pit are in the same chamebr
				killPlayer(1);// send a 1 to killPlayer
			}
			else
			{
				killPlayer(0);
			}
		}
		else if(val == 2)
		{
			player = player->getDoor2Ptr();
			if((player->getID() && wumpus->getID()) || (player->getID() && pit->getID()) || (player->getID() && bats->getID()))
			{ // if the player and the wumpus, bats, or pit are in the same chamebr
				killPlayer(1);// send a 1 to killPlayer
			}
			else
			{
				killPlayer(0);
			}
		}
		else
		{
			player = player->getDoor3Ptr();
			if((player->getID() && wumpus->getID()) || (player->getID() && pit->getID()) || (player->getID() && bats->getID()))
			{ // if the player and the wumpus, bats, or pit are in the same chamebr
				killPlayer(1);// send a 1 to killPlayer
			}
			else
			{
				killPlayer(0);
			}
		}
	}
}

void Hunt::randomFlight()
{

}

void Hunt::killPlayer(int val)
{
	if(val == 1)
	{
		if(wumpus->getID() == player->getID())
		{
			cout << "The player was killed by the wumpus" << endl;
		}
		else if(pit->getID() == player->getID())
		{
			cout << "The player was killed by the pit" << endl;
		}
		else if(bats->getID() == player->getID())
		{
			cout << "The player was killed by the bats" << endl;
		}
	}
}

int Hunt::fire()
{
	return 0;
}

void Hunt::moveWumpus()
{
	
}