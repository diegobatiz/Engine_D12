#pragma once
#include "CommonHeaders.h"

namespace d12::Math
{
	constexpr float pi = 3.1415926535897937f;
	constexpr float epsilon = 1e-5f;

#if defined(_WIN64)
	using vec2 = DirectX::XMFLOAT2;
	using vec2a = DirectX::XMFLOAT2A;
	using vec3 = DirectX::XMFLOAT3;
	using vec3a = DirectX::XMFLOAT3A;
	using vec4 = DirectX::XMFLOAT4;
	using vec4a = DirectX::XMFLOAT4A;
	using u32vec2 = DirectX::XMUINT2;
	using u32vec3 = DirectX::XMUINT3;
	using u32vec4 = DirectX::XMUINT4;
	using s32vec2 = DirectX::XMINT2;
	using s32vec3 = DirectX::XMINT3;
	using s32vec4 = DirectX::XMINT4;
	using m3x3 = DirectX::XMFLOAT3X3;
	using m4x4 = DirectX::XMFLOAT4X4;
	using m4x4a = DirectX::XMFLOAT4X4A;
#endif
}