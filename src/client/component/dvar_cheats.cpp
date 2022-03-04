#include <std_include.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"

#include "game/dvars.hpp"
#include "scheduler.hpp"

namespace dvar_cheats
{
	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			if (game::environment::is_sp()) return;

			scheduler::once([]()
			{
				dvars::register_bool("sv_cheats", false, game::DvarFlags::DVAR_FLAG_REPLICATED);
			}, scheduler::pipeline::main);
		}
	};
}

REGISTER_COMPONENT(dvar_cheats::component)
