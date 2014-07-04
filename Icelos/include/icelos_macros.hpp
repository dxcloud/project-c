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
#  define ICELOS_SDL_CHECK(X) \
          std::cout << "SDL CHECK" << std::endl; \
          if (0 > X) { \
            std::cout << SDL_GetError() << std::endl; \
            return STATUS_FAIL; \
          }

#  define ICELOS_SDL_FLAGS_CHECK(X, flags) \
          if (flags != (X & flags)) { \
            std::cout << SDL_GetError() << std::endl; \
            return STATUS_FAIL; \
          }

#  define ICELOS_SDL_PTR_CHECK(X) \
          if (nullptr == X) { \
            std::cout << SDL_GetError() << std::endl; \
            return STATUS_FAIL; \
          }

#else
#  define OUT(X)
#  define ICELOS_SDL_CHECK(X) X;
#  define ICELOS_SDL_FLAGS_CHECK(X, flags) X;
#  define ICELOS_SDL_PTR_CHECK(X)
#endif

#define ICELOS_WINDOW_WIDTH  RenderManager::instance().get_size().w
#define ICELOS_WINDOW_HEIGHT RenderManager::instance().get_size().h

#define ICELOS_BIT(X) 1 << X

#define ICELOS_INIT_CHECK(X) \
        if (false == X) { return STATUS_FAIL; }

}

// using icelos;

#endif // ICELOS_MACROS_HPP
