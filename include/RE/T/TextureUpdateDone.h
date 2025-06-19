#pragma once

namespace RE
{
	class __declspec(novtable) TextureUpdateDone
	{
	public:
		static constexpr auto RTTI{ RTTI::TextureUpdateDone };
		static constexpr auto VTABLE{ VTABLE::TextureUpdateDone };

		// add
		virtual bool Update();  // 00
	};
}
