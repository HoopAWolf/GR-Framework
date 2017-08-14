#pragma once

#include "../PlayerInfo/PlayerInfo.h"

class Controller
{
protected:
	Player* thePlayerInfo;
    typedef bool(*controllerfunc)(double dt);
public:

    enum CONTROLLER_STATES
    {
        CONTROLLER_MOVEFRONT = 0,
        CONTROLLER_MOVEBACK,
        CONTROLLER_MOVELEFT,
        CONTROLLER_MOVERIGHT,

        NUM_CONRTOLLER,
    };

	Controller();
	virtual ~Controller();

	// Create this controller
	virtual bool Create(Player* thePlayerInfo = NULL);
	// Read from the controller
	virtual int Read(const float deltaTime);

    controllerfunc cfunc[NUM_CONRTOLLER];

};

