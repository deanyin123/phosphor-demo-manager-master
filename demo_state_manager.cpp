#include <cassert>
#include <phosphor-logging/log.hpp>
#include <sdbusplus/exception.hpp>
#include <sys/sysinfo.h>
#include "demo_state_manager.hpp"

namespace phosphor
{
namespace demo
{
namespace manager
{

// When you see server:: you know we're referencing our base class
namespace server = sdbusplus::xyz::openbmc_project::Demo::server;

using namespace phosphor::logging;
using sdbusplus::exception::SdBusError;


uint64_t Demo::getSystemTime() const
{
    using namespace std::chrono;
    struct sysinfo info;

    auto rc = sysinfo(&info);
    assert(rc == 0);

    // Since uptime is in seconds, also get the current time in seconds.
    auto now = time_point_cast<seconds>(system_clock::now());
    auto rebootTime = now - seconds(info.uptime);

    return duration_cast<milliseconds>(rebootTime.time_since_epoch()).count();
}

} // namespace manager
} // namespace demo
} // namespace phosphor
