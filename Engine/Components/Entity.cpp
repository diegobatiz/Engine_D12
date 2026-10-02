#include "Entity.h"
#include "Transform.h"

namespace d12::GameEntity
{
	namespace
	{
		Util::vector<Transform::Component> transforms;

		Util::vector<id::generation_type> generations;
		Util::deque<entity_id> free_ids;
	}


	Entity CreateGameEntity(const EntityInfo& info)
	{
		assert(info.transform); // All game entities must have transform components
		if (!info.transform)
		{
			return Entity{};
		}

		entity_id id;

		if (free_ids.size() > id::min_deleted_elements)//================
		{
			id = free_ids.front();
			assert(!IsAlive(Entity{ id }));
			free_ids.pop_front();
			id = entity_id{ id::new_generation(id) };
			++generations[id::index(id)];
		}
		else
		{
			id = entity_id{ (id::id_type)generations.size() };
			generations.push_back(0);

			transforms.emplace_back();
		}

		const Entity new_entity{ id };
		const id::id_type index{ id::index(id) };

		//Create Transform Component
		assert(transforms[index].IsValid());
		transforms[index] = Transform::CreateTransform(*info.transform, new_entity);
		if (!transforms[index].IsValid()) return Entity();

		return new_entity;
	}

	void RemoveGameEntity(Entity e)
	{
		const entity_id id{ e.GetId() };
		const id::id_type index{ id::index(id) };
		if (IsAlive(e))
		{
			Transform::RemoveTransform(transforms[index]);
			transforms[index] = Transform::Component();
			free_ids.push_back(id);
		}
	}

	bool IsAlive(Entity e)
	{
		assert(e.IsValid());
		const entity_id id{ e.GetId() };
		const id::id_type index{ id::index(id) };
		assert(index < generations.size());
		assert(generations[index] == id::generation(id));

		return generations[index] == id::generation(id) && transforms[index].IsValid();
	}

	Transform::Component Entity::GetTransform() const
	{
		assert(IsAlive(*this));
		const id::id_type index{ id::index(mId) };
		return transforms[index];
	}
}