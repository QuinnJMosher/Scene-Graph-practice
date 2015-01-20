#include "Scene.h"

Scene::Scene() {
	m_scene_root = new SceneNode();
}

Scene::~Scene() { }

void Scene::UpdateTransforms() {
	m_scene_root->UpdateTransforms();
}

void Scene::RenderScene() {
	m_scene_root->RenderAll();
}

void Scene::UpdateScene(float a_fDeltaTime) {
	m_scene_root->UpdateAll(a_fDeltaTime);
}