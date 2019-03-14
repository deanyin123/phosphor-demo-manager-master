#include <sdbusplus/bus.hpp>
#include "config.h"
#include "demo_state_manager.hpp"

int main(int argc, char**)
{
    auto bus = sdbusplus::bus::new_default();

    // For now, we only have one instance of the Demo
    // 0 is for the current instance
    auto objPathInst = std::string(DEMO_OBJPATH) + '0';

    // Add sdbusplus ObjectManager.
    sdbusplus::server::manager::manager objManager(bus, objPathInst.c_str());

    phosphor::demo::manager::Demo manager(bus, objPathInst.c_str());

    bus.request_name(DEMO_BUSNAME);

    while (true)
    {
        bus.process_discard();
        bus.wait();
    }

    exit(EXIT_SUCCESS);
}
