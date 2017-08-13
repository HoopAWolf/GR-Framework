#ifndef SCENE_TEXT_H
#define SCENE_TEXT_H

#include "Scene.h"
#include "Mtx44.h"
#include "PlayerInfo/PlayerInfo.h"
#include "GroundEntity.h"
#include "FPSCamera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "GenericEntity.h"

<<<<<<< HEAD
=======
/*Editor*/
//#include "Editor\Editor.h"

>>>>>>> a9330da8500c044ac6d1286198d7c480bec42861
class ShaderProgram;
class SceneManager;
class TextEntity;
class Light;
class SceneText : public Scene
{	
public:
	SceneText();
	~SceneText();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:
	SceneText(SceneManager* _sceneMgr); // This is used to register to SceneManager

	ShaderProgram* currProg;
	Player* playerInfo;
	GroundEntity* groundEntity;
	FPSCamera *camera;
	TextEntity* textObj[3];
	Light* lights[2];

	GenericEntity* theCube;

	static SceneText* sInstance; // The pointer to the object that gets registered
<<<<<<< HEAD
=======

	/*Editor Object for writing and reading text files*/
	//Editor *theEditor;
>>>>>>> a9330da8500c044ac6d1286198d7c480bec42861
};

#endif