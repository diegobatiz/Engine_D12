#pragma once
#include "ComponentsCommon.h"

namespace d12::Transform
{
	struct InitInfo
	{
		f32 position[3]{};
		f32 rotation[4]{};
		f32 scale[3]{ 1.0f, 1.0f, 1.0f };
	};

	Component CreateTransform(const InitInfo& info, GameEntity::Entity entity);
	void RemoveTransform(Component id);


}