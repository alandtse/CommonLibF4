#include "REL/F4/Module.h"

namespace REL
{
	namespace detail
	{
		std::size_t get_runtime_index() noexcept
		{
			return F4::get_runtime_index();
		}
	}
}