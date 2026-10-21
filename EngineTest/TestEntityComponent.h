#pragma once

#include "Test.h"
#include "..\Engine\Components\Entity.h"
#include "..\Engine\Components\Transform.h"

#include <iostream>
#include <ctime>

using namespace d12;

class EngineTest : public Test
{
public:
	bool Initialize() override 
	{
		srand((u32)time(nullptr));
		return true;
	}

	void Run() override 
	{
		do
		{
			for (u32 i = 0; i < 10000; ++i)
			{
				CreateRandom();
				RemoveRandom();
				mNumEntities = (u32)mEntities.size();
			}
			PrintResults();
		} while (getchar() != 'q');
	}

	void Shutdown() override 
	{

	}

private:
	void CreateRandom()
	{
		u32 count = rand() % 20;

		if (mEntities.empty())
		{
			count = 1000;
		}
		Transform::InitInfo transformInfo{};
		GameEntity::EntityInfo entityInfo
		{
			&transformInfo
		};

		while (count > 0)
		{
			++mAdded;
			GameEntity::Entity entity{ GameEntity::CreateGameEntity(entityInfo) };
			assert(entity.IsValid() && id::is_valid(entity.GetId()));
			mEntities.push_back(entity);
			assert(GameEntity::IsAlive(entity));
			--count;
		}
	}

	void RemoveRandom()
	{
		u32 count = rand() % 20;
		if (mEntities.size() < 1000) return;
		while (count > 0)
		{
			const u32 index{ (u32)rand % (u32)mEntities.size() };
			const GameEntity::Entity entity{mEntities[index]};
			assert(entity.IsValid() && id::is_valid(entity.GetId()));
			if (entity.IsValid())
			{
				GameEntity::RemoveGameEntity(entity);
				mEntities.erase(mEntities.begin() + index);
				assert(!GameEntity::IsAlive(entity));
				++mRemoved;
			}
			--count;
		}
	}

	void PrintResults()
	{
		std::cout << "Entities Created:" << mAdded << "\n";
		std::cout << "Entities Removed:" << mRemoved << "\n";
	}

	Util::vector<GameEntity::Entity> mEntities;

	u32 mAdded{ 0 };
	u32 mRemoved{ 0 };
	u32 mNumEntities{ 0 };
};