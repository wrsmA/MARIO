#pragma once
#include "GameObject.h"
class Label : public GameObject
{
	unsigned int _color;
	char _string[128];
public:
	Label(char* string);
	~Label();
	void Draw();
	void SetColor(int r, int g, int b)
	{
		_color = GetColor(r, g, b);
	}
	void SetString(char* string)
	{
		strcpy(_string, string);
	}
};
