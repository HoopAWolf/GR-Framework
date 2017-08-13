#pragma once

#include "Controller.h"

#include <fstream>

class Keyboard :
	public Controller
{
private:
    enum VK
    {
        VK_FORWARD = 1,
        VK_LEFTWARD,
        VK_BACKWARD,
        VK_RIGHTWARD,
        VK_FORWARD1,
        VK_LEFT1,
        VK_BACK1,
        VK_RIGHT1,
        VK_SPRINT,
        VK_JUMP,
        VK_RELOAD,
        VK_CHANGE,
        VK_RESET,
        VK_CROUCH,
        NUM_VK,
    };
    unsigned int KeyList[NUM_VK];
public:
	Keyboard();
	virtual ~Keyboard();
	// Create this controller
	virtual bool Create(CPlayerInfo* thePlayerInfo = NULL);
	// Read from the controller
    virtual bool Load(std::string _filePath);
	virtual int Read(const float deltaTime);
};

