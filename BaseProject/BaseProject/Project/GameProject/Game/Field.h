#pragma once

class Field
{
private:
	CImage m_field;
	int m_pos;
public:
	 Field();
	void Update();
	void Draw();
};