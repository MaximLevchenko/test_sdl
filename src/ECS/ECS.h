#pragma once

#ifndef TEST_SDL_ECS_H
#define TEST_SDL_ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

using namespace std;

class Component;

class Entity;

class Manager;

using ComponentID = std::size_t;

// assigns a unique id to the new type <T>, if a function was called multiple times with same <T>,
// id will stay the same
//===================================================================
inline ComponentID getNewComponentTypeID ()
{
	static ComponentID lastID = 0u;
	return lastID++;
}

template<typename T>
inline ComponentID getComponentTypeID () noexcept
{
	static_assert (std::is_base_of<Component, T>::value, "");
	static ComponentID typeID = getNewComponentTypeID();
	return typeID;
}
//===================================================================

//bitset for checking if our entity has components
//===================================================================
constexpr size_t maxComponents = 32;

using ComponentBitset = bitset<maxComponents>;
using ComponentArray = array<Component*, maxComponents>;

//===================================================================
class Component
{
public:
	virtual ~Component () {}

	virtual void init () {}
	virtual void update () {}
	virtual void draw () {}

	Entity *entity{nullptr};//TODO: added this
};

class Entity
{

public:

	void update ()
	{
		for (auto &c: components) c->update();
	}
	void draw ()
	{
		for (auto &c: components) c->draw();
	}

	bool isActive () const {return active;}
	void destroy () {active = false;}
	template<typename T>
	bool hasComponent () const
	{
		return componentBitset[getComponentTypeID<T>()];
	}

	template<typename T, typename... TArgs>
	T &addComponent (TArgs &&... mArgs)
	{
		T *c(new T(std::forward<TArgs>(mArgs)...));

		c->entity = this;
		std::unique_ptr<Component> uPtr{c};
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitset[getComponentTypeID<T>()] = true;
		c->init();

		return *c;
	}

	template<typename T>
	T &getComponent () const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T *>(ptr);
	}

//	gameObject.getComponent<PositionComponent>().setXpos(25)

private:
//	Manager& manager;
	bool active = true;
	vector<unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitset componentBitset;
};

class Manager
{
public:
	void update ()
	{
		for (auto &e: entities)
		{
			e->update();
		}
	}
	void draw ()
	{
		for (auto &e: entities)
		{
			e->draw();
		}
	}

	void refresh ()
	{
		entities.erase(remove_if(begin(entities), end(entities),
		                         [] (const unique_ptr<Entity> &mEntity) {
			                         return !mEntity->isActive();
		                         }), end(entities));
	}
	Entity &addEntity ()
	{
		Entity *e = new Entity();
		unique_ptr<Entity> uPtr{e};
		entities.emplace_back(move(uPtr));
		return *e;
	}

private:
	vector<unique_ptr<Entity>> entities;


};

#endif //TEST_SDL_ECS_H
