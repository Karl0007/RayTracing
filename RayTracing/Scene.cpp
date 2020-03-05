#include "Scene.h"


int Scene::AddSphere(Vec3 const & v, float r,int id)
{
	while (id == -1 || objs.count(id)) id = rand();
	objs[id] = new Sphere(v, r, id);
	return id;
}

Color Scene::GetColor(Ray & r)
{
	Vec3 light(0,2,2);
	float dis = 2000;
	Object* obj = nullptr;
	for (auto i : objs) {
		float tmp = i.second->hit(r);
		if (tmp < dis && tmp > 0) {
			dis = tmp;
			obj = i.second;
		}
	}
	if (obj) {
		Vec3 hitpoint = r.RayPoint(dis);
		Ray tmp(light, hitpoint - light);
		Vec3 lt = tmp.RayPoint(obj->hit(tmp));
		if ((lt - hitpoint).norm() < 0.001f) {
			return obj->color*((light - hitpoint).normalized().dot(obj->normal(hitpoint)));
		}
		else {
			return Color(0, 0, 0);
		}
	}
	return Color(0,0,0);
}

Object * Scene::GetObj(int id)
{
	if (objs.count(id)) return objs[id];
	return nullptr;
}

bool Scene::DelObj(int id)
{
	if (objs.count(id)) {
		delete objs[id];
		objs[id] = nullptr;
		objs.erase(id);
		return true;
	}
	return false;
}

Scene::Scene()
{
}


Scene::~Scene()
{
	for (auto i : objs)
	{
		delete i.second;
		i.second = nullptr;
	}
}
