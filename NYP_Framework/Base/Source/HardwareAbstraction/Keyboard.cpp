#include "Keyboard.h"
#include <iostream>
#include <sstream>
using namespace std;

#include "KeyboardController.h"
#include "../PlayerInfo/PlayerInfo.h"

const bool _CONTROLLER_KEYBOARD_DEBUG = false;

Keyboard::Keyboard()
{
}


Keyboard::~Keyboard()
{
}

// Create this controller
bool Keyboard::Create(Player* thePlayerInfo)
{
	Controller::Create(thePlayerInfo);
	KeyList[CONTROLLER_MOVEFRONT] = 'W';
	KeyList[CONTROLLER_MOVEBACK] = 'S';
	KeyList[CONTROLLER_MOVELEFT] = 'A';
	KeyList[CONTROLLER_MOVERIGHT] = 'D';

	return false;
}


bool Keyboard::Load(std::string _filePath)
{
    return false;
}

// Read from the controller
int Keyboard::Read(const float deltaTime)
{
	Controller::Read(deltaTime);
	if (_CONTROLLER_KEYBOARD_DEBUG)
	return 0;

	for (int i = 0;i < NUM_CONRTOLLER;++i)
	{
		if (KeyboardController::GetInstance()->IsKeyDown(KeyList[i]))
		{
			(this->*(controllerfunc[i]))(deltaTime);
		}
	}
}
