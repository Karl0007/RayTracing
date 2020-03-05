#pragma once
#include "Head.h"
#include "Ray.h"
#include "Scene.h"

class Camera
{
public:
	int height, weight;
	float sizex, sizey;
	Vec3 original;
	Vec3 direction;
	Vec3 vertical;
	Vec3 horizontal;
	Byte *picture;
	Camera() { picture = nullptr; };
	void Init(int w, int h, float x, float y, Vec3 const& o, Vec3 const& d, Vec3 const& v) {
		delete picture; 
		height = h, weight = w, sizex = x, sizey = y, original = o, direction = d, vertical = v;
		vertical = (vertical - direction * vertical.dot(direction)).normalized();
		horizontal = direction.cross(vertical).normalized();
		picture = new Byte[height*weight * 3];
	}
	~Camera() { delete picture; picture = nullptr; }
	void MakePicture(Scene & scene);
	void SaveColor(Byte *pos,Color const &c) {
		pos[0] = (Byte)255.0f*c.x();
		pos[1] = (Byte)255.0f*c.y();
		pos[2] = (Byte)255.0f*c.z();
	}
	float randf() {
		return (rand() % 100) / 100.0f;
	}
};

