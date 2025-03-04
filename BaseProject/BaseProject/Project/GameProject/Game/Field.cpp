#include "Field.h"

Field::Field()
{
	m_field = COPY_RESOURCE("field", CImage);
}
void Field::Update()
{

}

void Field::Draw()
{
	m_field.Draw();
}
