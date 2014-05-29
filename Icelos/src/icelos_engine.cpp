#include <icelos_engine.hpp>

//#include <icelos_sprite.hpp>
#include <icelos_render_manager.hpp>
#include <icelos_resource_manager.hpp>
#include <icelos_state_manager.hpp>
#include <icelos_input_manager.hpp>
//#include <icelos_text.hpp>

namespace icelos
{

state_t Engine::m_engine_state = UNINITIALIZED;

Engine::Engine()
//   m_engine_state(UNINITIALIZED)
{
  if (STATUS_SUCCESS == initialize()) { m_engine_state = INITIALIZED; }
  else { m_engine_state = STOPPED; }
}


Engine::Engine(int argc, char* argv[]):
  m_argc(argc),
  m_argv(argv)
{
  if (STATUS_SUCCESS == initialize()) { m_engine_state = INITIALIZED; }
  else { m_engine_state = STOPPED; }
}


Engine::~Engine()
{
  // nothing to do
}

status_t Engine::run()
{
  status_t ret(STATUS_ERROR);
  if (INITIALIZED == m_engine_state) {
    game_loop();
    ret = STATUS_SUCCESS;
  }
  cleanup();
  return ret;
}

void Engine::game_loop()
{
  m_engine_state = RUNNING;
  while (RUNNING == m_engine_state) {
    InputManager::instance().update();
    StateManager::instance().update();
    RenderManager::instance().update();
  } // running
}

status_t Engine::initialize()
{
  for (int i(0); i < m_argc; ++i) {
    OUT("arg #" << i << ": " << m_argv[i])
  }

  if (0 > SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
    return STATUS_FAIL;
  }

  IMG_Init(IMG_INIT_PNG); // SDL Image

  if (0 > TTF_Init()) {
    std::cout << "Failed to initialize TTF: " << TTF_GetError() << std::endl;
    return STATUS_FAIL;
  }

  RenderManager::instance(); // initialize RenderManager
  ResourceManager::instance(); // initialize ResourceManager
  StateManager::instance();
  InputManager::instance();

  return STATUS_SUCCESS;
}

void Engine::cleanup()
{
  InputManager::destroy();
  StateManager::destroy();
  ResourceManager::destroy();
  RenderManager::destroy();

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

void Engine::quit()
{
  m_engine_state = STOPPED;
}

}

