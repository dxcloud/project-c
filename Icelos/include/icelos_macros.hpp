#ifndef ICELOS_MACROS_HPP
#define ICELOS_MACROS_HPP

namespace icelos
{

#define RESOURCE_MANAGER ResourceManager::instance()
#define RENDER_MANAGER   RenderManager::instance()
#define STATE_MANAGER    StateManager::instance()
#define INPUT_MANAGER    InputManager::instance()

#if defined(ICELOS_DEBUG)
#  define OUT(X) std::cout << X << std::endl;
#else
#  define OUT(X)
#endif

}

#endif // ICELOS_MACROS_HPP
