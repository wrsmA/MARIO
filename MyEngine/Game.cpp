#include "Game.h"
#include "..\\PlayScene.h"
#include "Scene.h"

Scene* Game::_scene = NULL;
Game::~Game()
{
	delete _scene;
}
//�ŏ��ɂ�肽������
void Game::Start()
{
	_scene = new PlayScene;
	_scene->Start();
}

//��ɂ�肽������
void Game::Update()
{
	_scene->Update();
}
//�V�[���؂�ւ�
void Game::ChangeScene(Scene* scene)
{
	delete _scene;
	_scene = scene;
	_scene->Start();
}