#include "Game.h"
#include "..\\PlayScene.h"
#include "Scene.h"

Scene* Game::_scene = NULL;
Game::~Game()
{
	delete _scene;
}
//最初にやりたいこと
void Game::Start()
{
	_scene = new PlayScene;
	_scene->Start();
}

//常にやりたいこと
void Game::Update()
{
	_scene->Update();
}
//シーン切り替え
void Game::ChangeScene(Scene* scene)
{
	delete _scene;
	_scene = scene;
	_scene->Start();
}