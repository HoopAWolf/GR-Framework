#pragma once

#include "../PlayerInfo/PlayerInfo.h"

class Controller
{
protected:
	CPlayerInfo* thePlayerInfo;
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
	virtual bool Create(CPlayerInfo* thePlayerInfo = NULL);
	// Read from the controller
	virtual int Read(const float deltaTime);

    controllerfunc cfunc[NUM_CONRTOLLER];

};

