#pragma once
#ifndef PHYSIC_H
#define PHYSIC_H

#include "Vector3.h"

class Physic {
public:
	Physic();
	virtual ~Physic();

	float GetMass();
	void SetMass(float _value);

	Vector3 GetForce();
	void SetForce(Vector3 _value);

protected:
	float mass;

	Vector3 force;
};

#endif