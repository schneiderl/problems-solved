#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <GL/glu.h>

#include "Image.h"
#include "PTMReader.h"
#include "SpriteSheetCutter.h"
#include "SpriteSheet.h"
#include "Layer.h"

#include "Game.h"

using namespace std;

Game myGame;

PTMReader myPTMReader;
Image *background;
Image *newImage;
//Image **PikachuSprites;
Image *foo;
Image *viewport;
SpriteSheet *BigSprite;
SpriteSheet *SmallSprite;

GameObject *ground2;
GameObject *ground2_2;
GameObject *ground3;
GameObject *ground3_2;

Layer *layer1;
Layer *layer2;
Layer *layer3;

Image *layer1BaseImage;
Image *layer2BaseImage;
Image *layer3BaseImage;

GameObject *player;

int index = 0;
int lvl = 0; 


float xOffSet1 = 0;
float xOffSet2 = 0;

//===============
int layer2Offset = 100;

void display(void)
{
	if (myGame.getGameOn() == false){
		glutSetWindowTitle("Game over!");
		return;
	}


	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawPixels(viewport->getWidth(), viewport->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, viewport->getPixels());

	glFlush();
}

void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{

	if ('q' == key)
	{
		exit(0);
	}

	if ('w' == key)
	{
		myGame.setPlayerLayer(0);

		myGame.getPlayer()->setSprite(SmallSprite);

		layer3->getImage()->subImage(layer3BaseImage, myGame.getPlayer()->getPosX(), myGame.getPlayer()->getPosY(),
			myGame.getPlayer()->getSprite()->getCurrentImage()->getWidth(), myGame.getPlayer()->getSprite()->getCurrentImage()->getHeight());
	}

	if ('s' == key)
	{
		myGame.setPlayerLayer(1);

		myGame.getPlayer()->setSprite(BigSprite);

		layer2->getImage()->subImage(layer2BaseImage, myGame.getPlayer()->getPosX(), myGame.getPlayer()->getPosY(),
			myGame.getPlayer()->getSprite()->getCurrentImage()->getWidth(), myGame.getPlayer()->getSprite()->getCurrentImage()->getHeight());
	}

	glutPostRedisplay();
}

void cleanUpLayers()
{
	if (myGame.getPlayerLayer() == 0){
		layer2->getImage()->subImage(layer2BaseImage, myGame.getPlayer()->getPosX(), myGame.getPlayer()->getPosY(),
			myGame.getPlayer()->getSprite()->getCurrentImage()->getWidth(), myGame.getPlayer()->getSprite()->getCurrentImage()->getHeight());
	}
	else{
		layer3->getImage()->subImage(layer3BaseImage, myGame.getPlayer()->getPosX(), myGame.getPlayer()->getPosY(),
			myGame.getPlayer()->getSprite()->getCurrentImage()->getWidth(), myGame.getPlayer()->getSprite()->getCurrentImage()->getHeight());
	}

	for (int i = 0; i < myGame.getNumberOfObstacles1(); i++){
		layer2->getImage()->subImage(layer2BaseImage, myGame.getObstacles1()[i].getPosX(), myGame.getObstacles1()[i].getPosY(),
			myGame.getObstacles1()[i].getSprite()->getCurrentImage()->getWidth(), myGame.getObstacles1()[i].getSprite()->getCurrentImage()->getHeight());
	}

	for (int i = 0; i < myGame.getNumberOfObstacles2(); i++){
		layer3->getImage()->subImage(layer3BaseImage, myGame.getObstacles2()[i].getPosX(), myGame.getObstacles2()[i].getPosY(),
			myGame.getObstacles2()[i].getSprite()->getCurrentImage()->getWidth(), myGame.getObstacles2()[i].getSprite()->getCurrentImage()->getHeight());
	}
}

void incrementObjectPositions()
{
	//BigSprite->incrementImageIndex();
	myGame.getPlayer()->incrementSpriteIndex();

	ground2->addToPosX(layer2->getUpdateRate() * -1);
	ground2_2->addToPosX(layer2->getUpdateRate() * -1);

	ground3->addToPosX(layer3->getUpdateRate() * -1);
	ground3_2->addToPosX(layer3->getUpdateRate() * -1);

	for (int i = 0; i < myGame.getNumberOfObstacles1(); i++){
		myGame.getObstacles1()[i].addToPosX(layer2->getUpdateRate() * -1);
		myGame.getObstacles1()[i].incrementSpriteIndex();
	}

	for (int i = 0; i < myGame.getNumberOfObstacles2(); i++){
		myGame.getObstacles2()[i].addToPosX(layer3->getUpdateRate() * -1);
		myGame.getObstacles2()[i].incrementSpriteIndex();
	}
}

void plotObjectsToLayers()
{
	layer1->getImage()->plotImage(background, 0, 0);
	layer1->getImage()->plotImage(ground2->getImage(), ground2->getPosX(), ground2->getPosY());
	layer1->getImage()->plotImage(ground2_2->getImage(), ground2_2->getPosX(), ground2_2->getPosY());

	layer1->getImage()->plotImage(ground3->getImage(), ground3->getPosX(), ground3->getPosY());
	layer1->getImage()->plotImage(ground3_2->getImage(), ground3_2->getPosX(), ground3_2->getPosY());

	for (int i = 0; i < myGame.getNumberOfObstacles1(); i++)
	{
		layer2->getImage()->plotImage(myGame.getObstacles1()[i].getCurrentImageFromSprite(), myGame.getObstacles1()[i].getPosX(), myGame.getObstacles1()[i].getPosY());
	}

	for (int i = 0; i < myGame.getNumberOfObstacles2(); i++)
	{
		layer3->getImage()->plotImage(myGame.getObstacles2()[i].getCurrentImageFromSprite(), myGame.getObstacles2()[i].getPosX(), myGame.getObstacles2()[i].getPosY());
	}

	if (myGame.getPlayerLayer() == 1)
		layer3->getImage()->plotImage(myGame.getPlayer()->getCurrentImageFromSprite(), myGame.getPlayer()->getPosX(), myGame.getPlayer()->getPosY());
	else
		layer2->getImage()->plotImage(myGame.getPlayer()->getCurrentImageFromSprite(), myGame.getPlayer()->getPosX(), myGame.getPlayer()->getPosY());
}

void plotLayersToViewPort()
{
	viewport->plotImage(layer1->getImage(), 0, 0);
	viewport->plotImage(layer2->getImage(), 0, layer2Offset);
	viewport->plotImage(layer3->getImage(), 0, 0);
}

void checkGroundsOfOfBounds()
{
	if (ground2->getPosX() + ground2->getImage()->getWidth() -7 < 0)
	{
		ground2->setPosX(640);
	}

	if (ground2_2->getPosX() + ground2_2->getImage()->getWidth() -7 < 0)
	{
		ground2_2->setPosX(640);
	}

	if (ground3->getPosX() + ground3->getImage()->getWidth() -13 < 0)
	{
		ground3->setPosX(640);
	}

	if (ground3_2->getPosX() + ground3_2->getImage()->getWidth() -13 < 0){
		ground3_2->setPosX(640);
	}
}

void Timer(int value)
{
	//=========================

	cleanUpLayers();

	incrementObjectPositions();

	myGame.checkObstacles2OutOfBounds();
	myGame.checkCollisionWithPlayer();
	checkGroundsOfOfBounds();
	plotObjectsToLayers();
	

	plotLayersToViewPort();
	
	

	//Redraws the frames
	glutPostRedisplay();
	int currlvl = lvl/15;
	int currVel = 42-(currlvl*2); 
	if(currVel<10){
		currVel = 10; 
	}
	glutTimerFunc(currVel, Timer, 1);
	lvl++;
}

void loadObstacleImage()
{
	Image *tempImage = myPTMReader.createImageFromPTM("sprites_fire.ptm");
	SpriteSheet *tempSpriteSheet = new SpriteSheet(tempImage, 96, 96);

	Image *tempImage2 = myPTMReader.createImageFromPTM("sprites_fire_5.ptm");
	SpriteSheet *temp2SpriteSheet = new SpriteSheet(tempImage2, 96, 96);

	for (int i = 0; i < myGame.getNumberOfObstacles1(); i++)
	{
		myGame.getObstacles1()[i].setSprite(temp2SpriteSheet);
		myGame.getObstacles1()[i].setPosX(700 + (i * 180));
		myGame.getObstacles1()[i].setPosY(0);
	}

	for (int i = 0; i < myGame.getNumberOfObstacles2(); i++)
	{
		myGame.getObstacles2()[i].setSprite(tempSpriteSheet);
		myGame.getObstacles2()[i].setPosX(665 + (i * 210));
		myGame.getObstacles2()[i].setPosY(0);
	}
}

void getLayersReady()
{
	layer1 = new Layer();
	layer2 = new Layer();
	layer3 = new Layer();

	layer1->setImage(new Image(640, 240));
	layer2->setImage(new Image(640, 100));
	layer3->setImage(new Image(640, 100));

	layer1BaseImage = new Image(640, 240);
	layer2BaseImage = new Image(640, 100);
	layer3BaseImage = new Image(640, 100);

	layer2BaseImage->makeImageTransparent();
	layer3BaseImage->makeImageTransparent();

	layer1->getImage()->copyImage(layer1BaseImage);
	layer2->getImage()->copyImage(layer2BaseImage);
	layer3->getImage()->copyImage(layer3BaseImage);
	
	layer2->setUpdateRate(7);
	layer3->setUpdateRate(13);
}

//Might be useful. It was use in the main function instead of plotObjects
void plotImagesIntoLayers()
{
	layer1->getImage()->plotImage(background, 0, 0);

	if (myGame.getPlayerLayer() == 3);
	{
		layer3->getImage()->plotImage(myGame.getPlayer()->getSprite()->getCurrentImage(), myGame.getPlayer()->getPosX(), myGame.getPlayer()->getPosY());
	}

	for (int i = 0; i < myGame.getNumberOfObstacles1(); i++)
	{
		layer2->getImage()->plotImage(myGame.getObstacles2()[i].getSprite()->getCurrentImage(), myGame.getObstacles2()[i].getPosX(), myGame.getObstacles2()[i].getPosY());
	}

	for (int i = 0; i < myGame.getNumberOfObstacles2(); i++)
	{
		layer3->getImage()->plotImage(myGame.getObstacles2()[i].getSprite()->getCurrentImage(), myGame.getObstacles2()[i].getPosX(), myGame.getObstacles2()[i].getPosY());
	}
}


int main(int argc, char** argv)
{
	loadObstacleImage();

	ground2 = new GameObject();
	ground3 = new GameObject();
	ground2_2 = new GameObject();
	ground3_2 = new GameObject();

	getLayersReady();

	//==============

	background = myPTMReader.createImageFromPTM("background.ptm");
	newImage = myPTMReader.createImageFromPTM("sprites_boy.ptm");
	Image *smallSpriteImage = myPTMReader.createImageFromPTM("sprites_boy_5.ptm");

	ground2->setImage(myPTMReader.createImageFromPTM("ground2_new.ptm"));
	ground3->setImage(myPTMReader.createImageFromPTM("ground_down.ptm"));
	ground2_2->setImage(ground2->getImage());
	ground3_2->setImage(ground3->getImage());

	ground2->setPosX(0);
	ground2->setPosY(100);
	ground2_2->setPosX(640);
	ground2_2->setPosY(100);

	ground3->setPosX(0);
	ground3->setPosX(0);
	ground3_2->setPosX(640);
	ground3_2->setPosY(0);

	//==============

	SpriteSheetCutter mySpriteSheetCutter;
	BigSprite = new SpriteSheet(newImage, 50, 54);
	SmallSprite = new SpriteSheet(smallSpriteImage, 50, 54);
	//==============
	
	myGame.getPlayer()->setSprite(BigSprite);
	myGame.getPlayer()->setPosY(0);

	plotObjectsToLayers();

	//==============

	viewport = new Image(layer1->getImage()->getWidth(), layer1->getImage()->getHeight());

	plotLayersToViewPort();
	//==============

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 240);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutKeyboardFunc(keyboard);
	glutTimerFunc(50, Timer, 1);
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}