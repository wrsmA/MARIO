#include "Label.h"

Label::Label(char* string)
{
	_color = GetColor(255, 255, 255);
	strcpy(_string, "");
	SetString(string);
}

Label::~Label()
{
}
void Label::Draw()
{
	DrawString(_position.x, _position.y, _string, _color);
}