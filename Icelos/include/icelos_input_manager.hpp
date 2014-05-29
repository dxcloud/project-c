#ifndef ICELOS_INPUT_MANAGER_HPP
#define ICELOS_INPUT_MANAGER_HPP

#include <icelos_manager.hpp>

namespace icelos
{


class InputHandler
{
public:
  InputHandler() {}
  ~InputHandler() {}
  virtual void handle() = 0;
};

class InputManager:
  public Manager<InputManager>
{
public:
  void update();
  void add_input_handler(key_t key, InputHandler* handler);
private:
  InputManager();
  ~InputManager();
  InputManager(const InputManager&);
  InputManager& operator=(const InputManager&);
  friend class Manager<InputManager>;
private:
  std::map<key_t, InputHandler*> m_input_map;
}; // class InputManager

} // namespace icelos

#endif

