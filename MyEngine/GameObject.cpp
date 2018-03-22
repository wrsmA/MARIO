#include "GameObject.h"

GameObject::GameObject()
{
	_position.x = 0.0f;
	_position.y = 0.0f;
	_position.z = 0.0f;//positionコンストラクト初期化
	_size.x = 0.0f;
	_size.y = 0.0f;
	_size.z = 0.0f;//positionコンストラクト初期化
}

GameObject::~GameObject()
{
}
void GameObject::Update()
{
}
void GameObject::Draw()
{
}