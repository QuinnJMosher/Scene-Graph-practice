#ifndef _SCENENODE_H_
#define _SCENENODE_H_

#include <vector>
#include "Matrix3.h"
#include "Vector2.h"
#include "AIE.h"

class SceneNode
{
public:
	SceneNode();
	virtual ~SceneNode();

	//parent/child management
	void SetParent(SceneNode* a_parent);
	void AddChild(SceneNode* a_child);
	void RemoveChild(SceneNode* a_child);

	//transform management
	void UpdateTransforms();
	void SetLocalTransform(Matrix3 a_transform);
	Matrix3 GetLocalTransform();
	Matrix3 GetGlobalTransform();

	//Game Management functions
	void RenderAll();
	void UpdateAll(float a_fDeltaTime);

protected:

	//Abstract functions for subclasses to overload 
	//for building game functionality
	virtual void Render();
	virtual void Update(float a_fDeltaTime);

	//list of children 
	std::vector<SceneNode*> m_children;
	SceneNode* m_parent;

	//transform relative to parent 
	Matrix3 m_local_transform;

	//transform relative to world origin 
	//recalculated by UpdateTransforms()
	Matrix3 m_global_transform;

};

#endif //_SCENENODE_H_