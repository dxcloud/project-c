#include <icelos_input_manager.hpp>
#include <icelos_engine.hpp>

namespace icelos
{

InputManager::InputManager():
  Manager<InputManager>()
{
  // nothing to do
}

InputManager::~InputManager()
{
  // nothing to do
}

void InputManager::update()
{
  SDL_Event event;
  while (0 != SDL_PollEvent(&event)) {
    if (SDL_QUIT == event.type) { Engine::quit(); }
    else if (SDL_KEYDOWN == event.type) {
      std::map<key_t, InputHandler*>::iterator it(m_input_map.find((key_t) event.key.keysym.sym));
      if (m_input_map.end() != it) { it->second->handle(); }
    }
  } // poll event
}

void InputManager::add_input_handler(key_t key, InputHandler* handler)
{
  m_input_map.insert(std::make_pair(key, handler));
}

} // namespace icelos

