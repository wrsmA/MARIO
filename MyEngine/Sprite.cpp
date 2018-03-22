#include "Sprite.h"

Sprite::Sprite()
{
	_srcX = _srcY = _width = _height = 0;
}

Sprite::~Sprite()
{
}
void Sprite::Load(char* fileName)
{
	_graphicHandle = LoadGraph(fileName);
	if (_graphicHandle == -1)
	{
		printfDx("ÇÀÇ•ÇÊÇÒÇ»Ç‡ÇÒÉoÅ[ÉJ(%s)\n",fileName);
	}
	else
	{
		int w, h;
		GetGraphSize(_graphicHandle, &w, &h);
		_size.x = w;
		_size.y = h;

		_width = w;
		_height = h;
	}
}
void Sprite::Draw()
{
	//DrawGraph(_position.x, _position.y, _graphicHandle, TRUE);
	DrawRectGraph(_position.x, _position.y, _srcX, _srcY, _width, _height, _graphicHandle, TRUE, FALSE);
}