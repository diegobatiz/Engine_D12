#pragma once

#include "ComponentsCommon.h"

namespace d12::Transform { struct InitInfo; }

#define INIT_INFO(component) namespace component { struct InitInfo; }

INIT_INFO(d12::Transform)

#undef INIT_INFO

namespace d12::GameEntity
{
	struct EntityInfo
	{
		d12::Transform::InitInfo* transform{ nullptr };
	};

	Entity CreateGameEntity(const EntityInfo& info);
	void RemoveGameEntity(Entity id);
	bool IsAlive(Entity id);

}