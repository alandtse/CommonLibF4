#pragma once

namespace RE
{
	template <class T>
	class NiRect
	{
	public:
		constexpr NiRect() = default;

		constexpr NiRect(T a_left, T a_right, T a_top, T a_bottom) :
			left(a_left), right(a_right), top(a_top), bottom(a_bottom)
		{}

		// members
		T left;    // 00
		T right;   // ??
		T top;     // ??
		T bottom;  // ??
	};

	extern template class NiRect<float>;
	extern template class NiRect<std::int32_t>;
	extern template class NiRect<std::uint32_t>;
}
