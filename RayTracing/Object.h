#pragma once
#include "Ray.h"
class Object
{
public:
	int id;
	Vec3 color;
	virtual float hit(Ray &r) = 0;
	virtual Vec3 normal(Vec3 &v) = 0;
	void SetColor(Color &c) {
		color = c;
	}
	Object(int i = 0) : id(i) { color = Color(0, 1, 0); }
	virtual ~Object(){}
};

class Sphere : public Object {
public:
	Vec3 center;
	float radius;
	Sphere(Vec3 const &c,float r,int i) : center(c),radius(r),Object(i) {}
	Sphere() : Sphere(Vec3(0,0,0),1,-1) { }
	~Sphere() {}
	virtual float hit(Ray &r);
	virtual Vec3 normal(Vec3 &v);
};
