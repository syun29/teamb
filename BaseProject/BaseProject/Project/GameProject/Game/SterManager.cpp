#include "SterManager.h"
#include "Constellation_Star.h"
#include"Nomal.h"
struct StarData {
	CVector3D pos;
	int type;
	int id;
};
//std::vector<StarData>star_data = {
//	{CVector3D(100,20,0),eType_Nomal,0},
//	{CVector3D(1500,20,100),eType_Nomal,0},
//	{CVector3D(3000,20,0),eType_Nomal,0},
//	{CVector3D(3500,20,200),eType_Nomal,0},
//	{CVector3D(4000,20,0),eType_Nomal,0},
//	{CVector3D(5500,20,0),eType_Nomal,0},
//	{CVector3D(4500,20,-50),eType_Tri,0},
//	{CVector3D(2030,20,60),eType_Tri,0},
//	{CVector3D(3500,20,0),eType_Tri,0},
//	{CVector3D(400,20,0),eType_Quad,0},
//	{CVector3D(1580,20,0),eType_Quad,0},
//	{CVector3D(100,20,-50),eType_Quad,0},
//	{CVector3D(1450,20,0),eType_Quad,0},
//	{CVector3D(7000,20,0),eType_Penta,0},
//	{CVector3D(6350,20,0),eType_Penta,0},
//	{CVector3D(1250,20,0),eType_Penta,0},
//	{CVector3D(400,20,0),eType_Penta,0},
//	{CVector3D(300,0,0),eType_Penta,0},
//};


SterManager::SterManager()
	:sterCnt(4)
	, ObjectBase(eType_Star)
{
	for (int i = 0; i < 10; i++) {
		CVector3D pos(Utility::Rand(0.0f, 9000.f),
			Utility::Rand(0.0f, 150.0f),
			Utility::Rand(0.0f, 100.0f));
		new Nomal(pos, CVector3D(50, 200, 50), CVector3D(50, -100, 50));
	}
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < j + 3; i++) {
			CVector3D pos(Utility::Rand(0.0f, 9000.f),
				Utility::Rand(50.0f, 250.0f),
				Utility::Rand(0.0f, 100.0f));
				new Constellation_Star(pos, CVector3D(50, 100, 30), CVector3D(50, 0, 30), j);
		}
	}
}

SterManager::~SterManager()
{
}

void SterManager::Update()
{
	
		
	
	 
}


