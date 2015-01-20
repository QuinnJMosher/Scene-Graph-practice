#ifndef _SCENE_H_
#define _SCENE_H_
#include "SceneNode.h"

class Scene
{
public:
	Scene();
	~Scene();

	void UpdateTransforms();
	void RenderScene();
	void UpdateScene(float a_fDeltaTime);
	SceneNode* Root(){ return m_scene_root; }

private:
	SceneNode* m_scene_root;
};

#endif //_SCENE_H_