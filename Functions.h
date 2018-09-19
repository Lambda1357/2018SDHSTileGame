#pragma once

namespace utility {

	template <typename T>
	void lerp(T* target, const T& start, const T& end, float speed = 0.01f)
	{
		*target = start + (end - start) * speed;
	}

};