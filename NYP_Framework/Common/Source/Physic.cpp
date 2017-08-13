#include "Physic.h"

Physic::Physic()
	:force(0, 0, 0)
	,mass(1)
{
}

Physic::~Physic()
{
}

float Physic::GetMass()
{
	return mass;
}

void Physic::SetMass(float _value)
{
	mass = _value;
}

Vector3 Physic::GetForce()
{
	return force;
}

void Physic::SetForce(Vector3 _value)
{
	force = _value;
}
