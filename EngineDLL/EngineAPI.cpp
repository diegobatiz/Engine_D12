#ifndef EDITOR_INTERFACE
#define EDITOR_INTERFACE extern "C" __declspec(dllexport)
#endif // !EDITOR_INTERFACE

#include "CommonHeaders.h"
#include "Id.h"
#include "..\Engine\Components\Entity.h"
#include "..\Engine\Components\Transform.h"

using namespace d12;

namespace
{
	struct TransformComponent
	{
		f32 position[3];
		f32 rotation[3];
		f32 scale[3];

		Transform::InitInfo ToInitInfo()
		{
			using namespace DirectX;

			Transform::InitInfo info{};
			memcpy(&info.position[0], &position[0], sizeof(f32) * _countof(position));
			memcpy(&info.scale[0], &scale[0], sizeof(f32) * _countof(scale));
			XMFLOAT3A rot{ &rotation[0] };
			XMVECTOR quat{ XMQuaternionRotationRollPitchYawFromVector(XMLoadFloat3A(&rot)) };
			XMFLOAT4A rot_quat{};
			XMStoreFloat4A(&rot_quat, quat);
			memcpy(&info.rotation[0], &rot_quat, sizeof(f32) * _countof(info.rotation));

			return info;
		}
	};

	struct GameEntityDescriptor
	{
		TransformComponent transform;
	};
}

EDITOR_INTERFACE id::id_type
CreateGameEntity(GameEntityDescriptor* e)
{
	assert(e);
	GameEntityDescriptor& desc{ *e };
	Transform::InitInfo transformInfo { desc.transform.ToInitInfo() };
	GameEntity::EntityInfo entityInfo
	{
		&transformInfo
	};
	return GameEntity::CreateGameEntity(entityInfo).GetId();
}

EDITOR_INTERFACE void
RemoveGameEntity(id::id_type id)
{
	assert(id::is_valid(id));
}