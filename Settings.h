#pragma once

# ifdef __WIN32__

namespace settings{
	constexpr int windowWidth = 800;
	constexpr int windowHeight = 600;
	constexpr int viewportX = 0;
	constexpr int viewportY = 0;
	constexpr int viewportWidth = 800;
	constexpr int viewportHeight = 600;
	constexpr char windowTitle[] = "3D Solar System";
}

#else
namespace settings{
	inline constexpr int windowWidth = 800;
	inline constexpr int windowHeight = 600;
	inline constexpr int viewportX = 0;
	inline constexpr int viewportY = 0;
	inline constexpr int viewportWidth = 800;
	inline constexpr int viewportHeight = 600;
	inline constexpr char windowTitle[] = "3D Solar System";
}
#endif