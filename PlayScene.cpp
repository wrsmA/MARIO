#include "PlayScene.h"
#include "MyEngine\\Sprite.h"
#include "Player.h"
#include "Stage.h"

PlayScene::PlayScene()
{
	Sprite *background;
	background = new Sprite;
	background->Load("Assets\\Sky.jpg");
	AddObject(background);
	_player = NULL;
}


PlayScene::~PlayScene()
{
}
void PlayScene::Start()
{
	_player = new Player;
	AddObject(_player);

	_Stage = new Stage;
	AddObject(_Stage);
	_player->SetStage(_Stage);
}