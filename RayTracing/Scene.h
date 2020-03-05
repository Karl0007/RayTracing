#pragma once
#include "Camera.h"
#include "Object.h"
#include "Head.h"
#include <unordered_map>
using std::unordered_map;

class Scene
{
private:
	unordered_map<int,Object*> objs;
public:
	int AddSphere(Vec3 const&v, float r,int id = -1);
	Color GetColor(Ray & r);
	Object* GetObj(int id);
	bool DelObj(int id);
	Scene();
	~Scene();
};

