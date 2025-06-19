#pragma once

namespace RE
{
	class __declspec(novtable) TextureUpdateStage
	{
	public:
		static constexpr auto RTTI{ RTTI::TextureUpdateStage };
		static constexpr auto VTABLE{ VTABLE::TextureUpdateStage };

		// add
		virtual bool Update();  // 00
	};
}
