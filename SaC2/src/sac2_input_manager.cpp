#include <sac2_input_manager.hpp>

namespace sac2
{

status_t InputManager::initialize()
{
  if (false == m_initialized) {
//    set_input_config(new DefaultInputConfig);
    m_initialized = true;
#ifdef SAC2_LOGGER_ENABLED
    Logger::log_info("InputManager::initialize - successfully initialized");
#endif
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

status_t InputManager::cleanup()
{
  if (0 != p_input_config) {
    delete p_input_config;
    p_input_config = 0;
#ifdef SAC2_LOGGER_ENABLED
    Logger::log_info("InputManager::cleanup - input config removed");
#endif
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

status_t InputManager::update()
{
  p_input_config->handle_inputs();
  return STATUS_SUCCESS;
}

void InputManager::set_input_config(InputConfig* input_config)
{
  cleanup();
  p_input_config = input_config;
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("InputManager::set_input_config - input config set");
#endif
}

}
