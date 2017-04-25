#pragma once

#include "GameObject.h"

class Game
{
public:
	Game();
	~Game();

	void checkObstacles2OutOfBounds();
	void checkCollisionWithPlayer();

	void setPlayerLayer(int newInt);

	bool getGameOn();

	GameObject *getPlayer();
	int getPlayerLayer();

	GameObject *getObstacles1();
	int getNumberOfObstacles1();

	GameObject *getObstacles2();
	int getNumberOfObstacles2();

private:

	bool gameIsOn;

	int playerLayer;
	GameObject* player;

	int numberOfObstacles1;
	GameObject* obstacles1;

	int numberOfObstacles2;
	GameObject* obstacles2;
};

