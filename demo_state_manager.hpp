#pragma once

#include <functional>
#include <sdbusplus/bus.hpp>
#include "xyz/openbmc_project/Demo/Demo/server.hpp"

namespace phosphor
{
namespace demo
{
namespace manager
{

using DemoInherit = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::Demo::server::Demo>;

/** @class Demo
 *  @brief OpenBMC Demo state management implementation.
 *  @details A concrete implementation for xyz.openbmc_project.State.Demo
 *  DBus API.
 */
class Demo : public DemoInherit
{
  public:
    /** @brief Constructs Demo State Manager
     *
     * @param[in] bus       - The Dbus bus object
     * @param[in] busName   - The Dbus name to own
     * @param[in] objPath   - The Dbus object path
     */
    Demo(sdbusplus::bus::bus& bus, const char* objPath) :
        BMCInherit(bus, objPath, true), bus(bus){     
    };

    /** @brief Returns current system time
     *
     *  @return uint64_t - Epoch time, in milliseconds, of the current system time.
     */
    uint64_t getSystemTime() const override;

  private:
  
    /** @brief Persistent sdbusplus DBus bus connection. **/
    sdbusplus::bus::bus& bus;

};

} // namespace manager
} // namespace demo
} // namespace phosphor
