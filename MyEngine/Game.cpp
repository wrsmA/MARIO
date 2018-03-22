#include "Game.h"
#include "..\\PlayScene.h"
#include "Scene.h"

Scene* Game::_scene = NULL;
Game::~Game()
{
	delete _scene;
}
//Å‰‚É‚â‚è‚½‚¢‚±‚Æ
void Game::Start()
{
	_scene = new PlayScene;
	_scene->Start();
}

//í‚É‚â‚è‚½‚¢‚±‚Æ
void Game::Update()
{
	_scene->Update();
}
//ƒV[ƒ“Ø‚è‘Ö‚¦
void Game::ChangeScene(Scene* scene)
{
	delete _scene;
	_scene = scene;
	_scene->Start();
}