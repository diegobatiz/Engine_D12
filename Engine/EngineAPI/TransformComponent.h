#pragma once

#include "..\Components\ComponentsCommon.h"

namespace d12::Transform 
{
	DEFINE_TYPED_ID(transform_id);

	class Component final
	{
	public:
		constexpr explicit Component(transform_id id) : mId(id) {}
		constexpr Component() : mId(id::invalid_id) {}
		constexpr transform_id GetId() const { return mId; }
		constexpr bool IsValid() const { return id::is_valid(mId); }

		Math::vec4 GetRotation() const;
		Math::vec3 GetPosition() const;
		Math::vec3 Scale() const;

	private:
		transform_id mId;
	};

}