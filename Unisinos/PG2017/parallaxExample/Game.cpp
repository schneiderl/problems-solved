#include "Game.h"

Game::Game(){
	gameIsOn = true;

	playerLayer = 1;
	player = new GameObject();

	numberOfObstacles1 = 3;
	obstacles1 = new GameObject[numberOfObstacles1]();

	numberOfObstacles2 = 3;
	obstacles2 = new GameObject[numberOfObstacles2]();
}

Game::~Game(){
}

void Game::checkObstacles2OutOfBounds(){
	for (int i = 0; i < numberOfObstacles2; i++){
		obstacles1[i].checkOutOfBounds();
		obstacles2[i].checkOutOfBounds();
	}
}

void Game::checkCollisionWithPlayer()
{
	if (playerLayer == 0){
		for (int i = 0; i < numberOfObstacles1; i++){
			if (obstacles1[i].getPosX() < 50){
				if (obstacles1[i].getPosX() + 45 < player->getPosX() + player->getSprite()->getCurrentImage()->getWidth()){
					gameIsOn = false;
				}
			}
		}
	}
	else{
		for (int i = 0; i < numberOfObstacles2; i++){
			if (obstacles2[i].getPosX() < 50){
				if (obstacles2[i].getPosX() + 40 < player->getPosX() + player->getSprite()->getCurrentImage()->getWidth()){
					gameIsOn = false;
				}
			}
		}
	}
}

void Game::setPlayerLayer(int newInt){
	playerLayer = newInt;
}

bool Game::getGameOn(){
	return gameIsOn;
}

GameObject * Game::getPlayer(){
	return player;
}

int Game::getPlayerLayer(){
	return playerLayer;
}

GameObject* Game::getObstacles1(){
	return obstacles1;
}

int Game::getNumberOfObstacles1(){
	return numberOfObstacles1;
}

GameObject* Game::getObstacles2(){
	return obstacles2;
}

int Game::getNumberOfObstacles2(){
	return numberOfObstacles2;
}
