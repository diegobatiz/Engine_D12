#include "Transform.h"
#include "Entity.h"

namespace d12::Transform
{
	namespace
	{
		Util::vector<Math::vec3> positions;
		Util::vector<Math::vec4> rotations;
		Util::vector<Math::vec3> scales;
	}

	Component CreateTransform(const InitInfo& info, GameEntity::Entity entity)
	{
		assert(entity.IsValid());
		const id::id_type entityIndex{ id::index(entity.GetId()) };

		if (positions.size() > entityIndex)
		{
			rotations[entityIndex] = Math::vec4(info.rotation);
			positions[entityIndex] = Math::vec3(info.position);
			scales[entityIndex] = Math::vec3(info.scale);
		}
		else
		{
			assert(positions.size() == entityIndex);
			rotations.emplace_back(info.rotation);
			positions.emplace_back(info.position);
			scales.emplace_back(info.scale);
		}

		return Component(transform_id{ (id::id_type)positions.size() - 1 });
	}

	void RemoveTransform(Component id)
	{
		assert(id.IsValid());
	}

	Math::vec4 Component::GetRotation() const
	{
		assert(IsValid());
		return rotations[id::index(mId)];
	}

	Math::vec3 Component::GetPosition() const
	{
		assert(IsValid());
		return positions[id::index(mId)];
	}

	Math::vec3 Component::Scale() const
	{

		assert(IsValid());
		return scales[id::index(mId)];
	}
}