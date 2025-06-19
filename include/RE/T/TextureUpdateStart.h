#pragma once

namespace RE
{
	class __declspec(novtable) TextureUpdateStart
	{
	public:
		static constexpr auto RTTI{ RTTI::TextureUpdateStart };
		static constexpr auto VTABLE{ VTABLE::TextureUpdateStart };

		// add
		virtual bool Update();  // 00
	};
}
