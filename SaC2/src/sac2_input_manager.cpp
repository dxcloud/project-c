#include <sac2_input_manager.hpp>

namespace sac2
{

void InputManager::initialize()
{
  if (false == m_initialized) { m_initialized = true; }
}

//----------------------------------------------------------------------------
//  InputManager::update
//----------------------------------------------------------------------------
void InputManager::update(float dt)
{
  p_input_config->handle_inputs();
}

//----------------------------------------------------------------------------
//  InputManager::cleanup
//----------------------------------------------------------------------------
void InputManager::cleanup()
{
  if (0 != p_input_config) {
    delete p_input_config;
    p_input_config = 0;
#ifdef SAC2_LOGGER_ENABLED
    Logger::log_info("InputManager::cleanup - input config removed");
#endif
  }
}

//----------------------------------------------------------------------------
//  InputManager::set_input_config
//----------------------------------------------------------------------------
void InputManager::set_input_config(InputConfig* input_config)
{
  cleanup();
  p_input_config = input_config;
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("InputManager::set_input_config - input config set");
#endif
}

}
