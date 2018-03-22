#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (int i = 0; i < _gameObject.size(); i++)
	{
		delete _gameObject[i];
	}
}
void Scene::Update()
{
	for (int i = 0; i < _gameObject.size(); i++)
	{
		_gameObject[i]->Update();
	}
	for (int i = 0; i < _gameObject.size(); i++)
	{
		_gameObject[i]->Draw();
	}
}
void Scene::Destroy(GameObject* object)
{
	for (int i = 0; i < _gameObject.size(); i++)
	{
		if (_gameObject[i] == object)
		{
			delete _gameObject[i];
			_gameObject.erase(_gameObject.begin() + i);
			break;
		}
	}
}
void Scene::AddObject(GameObject* object)
{
	_gameObject.push_back(object);
	object->SetScene(this);
}