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

	//機能：オブジェクトの消去
	//引数：オブジェクト
	//戻り値：なし
	void Destroy(GameObject* object);

	void AddObject(GameObject* object);
};