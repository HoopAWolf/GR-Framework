#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "MeshList.h"

/******************************************************************************/
/*!
		Class MeshBuilder:
\brief	Provides methods to generate mesh of different shapes
*/
/******************************************************************************/
class MeshBuilder : public Singleton<MeshBuilder>
{
	friend Singleton<MeshBuilder>;
public:
	Mesh* GenerateAxes(const std::string &meshName, float lengthX=0.0f, float lengthY=0.0f, float lengthZ=0.0f);
	Mesh* GenerateCrossHair(const std::string &meshName, float colour_r=1.0f, float colour_g=1.0f, float colour_b=0.0f, float length=1.0f);
	Mesh* GenerateQuad(const std::string &meshName, Color color, float length = 1.f);
	Mesh* GenerateCube(const std::string &meshName, Color color, float length = 1.f);
	Mesh* GenerateRing(const std::string &meshName, Color color, unsigned numSlice, float outerR = 1.f, float innerR = 0.f);
	Mesh* GenerateSphere(const std::string &meshName, Color color, unsigned numStack, unsigned numSlice, float radius = 1.f);
	Mesh* GenerateCone(const std::string &meshName, Color color, unsigned numSlice, float radius, float height);
	Mesh* GenerateOBJ(const std::string &meshName, const std::string &file_path);
	Mesh* GenerateText(const std::string &meshName, unsigned row, unsigned col);
	Mesh* GenerateSkyPlane(const std::string &meshName, Color color, int slices,float PlanetRadius, float AtmosphereRadius, float hTile, float vTile);
};

#endif