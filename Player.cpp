#include "Player.h"
#include "MyEngine\\Game.h"
#include "Stage.h"

Player::Player() :SPEED(10)
{
	//初期位置指定
	SetPosition(0, 300);
	//画像ロード
	Load("Assets\\Player.png");
	//範囲指定
	SetRect(0, 0, 48, 48);
}


Player::~Player()
{
}
void Player::Update()
{
	Move();
}
//移動処理
void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_RIGHT)!=0||CheckHitKey(KEY_INPUT_D)!=0)
	{
		_position.x += SPEED;
		int check1X = (_position.x + 48) / 64;
		int check1Y = _position.y / 64;
		int check2X = check1X;
		int check2Y = (_position.y + 48 - 1) / 64;

		if (_stage->IsTraffic(check1X , check1Y ) == false ||
			_stage->IsTraffic(check2X , check2Y ) == false)
		{
			_position.x = check1X * 64-48;
		}
	}
	if (CheckHitKey(KEY_INPUT_LEFT) != 0 || CheckHitKey(KEY_INPUT_A) != 0)
	{
		_position.x -= SPEED;
		int check1X = (_position.x-1)/ 64;
		int check1Y = _position.y / 64;
		int check2X = (_position.x-1)/64;
		int check2Y = (_position.y+48- 1) / 64;

		if (_stage->IsTraffic(check1X, check1Y) == false ||
			_stage->IsTraffic(check2X, check2Y) == false)
		{
			_position.x = check1X * 64 + 64;
		}

	}
	if (CheckHitKey(KEY_INPUT_UP) != 0 || CheckHitKey(KEY_INPUT_W) != 0)
	{
		_position.y -= SPEED;

		int check1X = _position.x / 64;
		int check1Y = (_position.y-10) / 64;
		int check2X = (_position.x+48 - 1) / 64;
		int check2Y = (_position.y -10) / 64;

		if (_stage->IsTraffic(check1X, check1Y) == false ||
			_stage->IsTraffic(check2X, check2Y) == false)
		{
			_position.y = check1Y * 64 + 64;
		}
	}
	if (CheckHitKey(KEY_INPUT_DOWN) != 0 || CheckHitKey(KEY_INPUT_S) != 0)
	{
		_position.y += SPEED;

		int check1X = _position.x / 64;
		int check1Y = (_position.y + 48) / 64;
		int check2X = (_position.x + 48 - 1) / 64;
		int check2Y = (_position.y + 48) / 64;

		if (_stage->IsTraffic(check1X, check1Y) == false ||
			_stage->IsTraffic(check2X, check2Y) == false)
		{
			_position.y = check1Y * 64 - 48;
		}
	}
}