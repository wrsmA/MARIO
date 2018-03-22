#pragma once
#include "vector"
#include "GameObject.h"
class Scene
{
protected:
	std::vector<GameObject*> _gameObject;
public:
	Scene();
	virtual ~Scene();
	virtual void Start() = 0;
	virtual void Update();

	//�@�\�F�I�u�W�F�N�g�̏���
	//�����F�I�u�W�F�N�g
	//�߂�l�F�Ȃ�
	void Destroy(GameObject* object);

	void AddObject(GameObject* object);
};