#pragma once

#include "..\Components\ComponentsCommon.h"
#include "TransformComponent.h"

namespace d12::GameEntity
{
	DEFINE_TYPED_ID(entity_id);

	class Entity
	{
	public:
		constexpr explicit Entity(entity_id id) : mId(id) {}
		constexpr Entity() : mId(id::invalid_id) {}
		constexpr entity_id GetId() const { return mId; }
		constexpr bool IsValid() const { return id::is_valid(mId); }

		Transform::Component GetTransform() const;

	private:
		entity_id mId;

	};
}