#include "StarBase.h"

StarBase::StarBase()
	:ObjectBase(eType_Star)
{
}

StarBase::StarBase(const CVector3D& pos)
	:score(0),  ObjectBase(pos, eType_Star)

{
}

StarBase::~StarBase()
{
}

void StarBase::TakeScore()
{
	
}
