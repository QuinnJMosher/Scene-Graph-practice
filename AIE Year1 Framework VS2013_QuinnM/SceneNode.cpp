#include "SceneNode.h"

SceneNode::SceneNode() {
	m_local_transform = Matrix3();
}
SceneNode::~SceneNode() { };

//parent/child management
void SceneNode::SetParent(SceneNode* a_parent) {
	m_parent = a_parent;
}

void SceneNode::AddChild(SceneNode* a_child) {
	m_children.emplace_back(a_child);
	a_child->SetParent(this);
}
void SceneNode::RemoveChild(SceneNode* a_child) {
	int i = 0;
	while (m_children[i] != a_child && i < m_children.size()) {
		i++;
	}
	if (i < m_children.size()) {
		m_children.erase(m_children.begin() + i);
	}
}

//transform management
void SceneNode::UpdateTransforms()
{
	if (m_parent != nullptr)
		m_global_transform = m_parent->m_global_transform * m_local_transform;
	else
		m_global_transform = m_local_transform;

	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		(*i)->UpdateTransforms();
	}
}

void SceneNode::SetLocalTransform(Matrix3 a_transform) {
	m_local_transform = a_transform;
}

Matrix3 SceneNode::GetLocalTransform() {
	return m_local_transform;
}

Matrix3 SceneNode::GetGlobalTransform() {
	return m_global_transform;
}

//Game Management functions
void SceneNode::RenderAll() {
	Render();
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		(*i)->RenderAll();
	}
}
void SceneNode::UpdateAll(float a_fDeltaTime) {
	Update(a_fDeltaTime);
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		(*i)->UpdateAll(a_fDeltaTime);
	}
}

void SceneNode::Render() {
	unsigned int sprite = CreateSprite("images/crate_sideup.png", 50, 50, false);
	Vector2 vec = Vector2(1, 1);
	vec = m_local_transform * vec;
	MoveSprite(sprite, vec.x, vec.y);
	DrawSprite(sprite);
	DestroySprite(sprite);
}

void SceneNode::Update(float a_fDeltaTime) {
	//do nothing
}