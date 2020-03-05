#pragma once
#include "Head.h"
class Ray
{
public:
	Vec3 ori;
	Vec3 dir;
	Ray() : Ray(Vec3(0,0,0),Vec3(1,0,0)) {}
	Ray(Vec3 o, Vec3 d) : ori(o),dir(d) {}
	Vec3 RayPoint(float x) {
		return ori + dir.normalized() * x;
	}
	~Ray(){}
};

