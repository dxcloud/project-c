#include <icelos_render_manager.hpp>
#include <icelos_graphics.hpp>

namespace icelos
{

RenderManager::RenderManager():
  Manager<RenderManager>(),
  p_sdl_window(0),
  p_sdl_renderer(0),
  m_graphics(),
  m_current_time(0),
  m_last_time(0),
  m_frame_rate(time::ZERO)
{
  OUT("+++++++++Render")
  // nothing to do
}

RenderManager::~RenderManager()
{
  // nothing to do
}

void RenderManager::update()
{
  static uint32_t fps(0);
  ++fps;
  uint32_t elapsed(SDL_GetTicks() - m_current_time);
  if (elapsed < m_frame_rate) { SDL_Delay(m_frame_rate - elapsed); }
  m_current_time = SDL_GetTicks();

  if (m_current_time > m_last_time + 1000) {
    m_last_time = m_current_time;
    OUT("fps count=" << fps);
    fps = 0;
  }

  SDL_RenderClear(p_sdl_renderer); // clear rendering target
  for (graphics_iter_t it(m_graphics.begin()); it != m_graphics.end(); ++it) {
    SDL_RenderCopy(p_sdl_renderer,
                   (*it)->p_sdl_texture,
                   &((*it)->m_sdl_src_rect),
                   &((*it)->m_sdl_dest_rect));
  } // render all graphics elements
  SDL_RenderPresent(p_sdl_renderer);
  m_graphics.clear(); // clear graphics elements
}

void RenderManager::add_graphics(Graphics* graphics)
{
  m_graphics.push_back(graphics); // add graphics element
}

void RenderManager::initialize()
{
  p_sdl_window = SDL_CreateWindow("Demo",
                                  0,
                                  0,
                                  800,
                                  600,
                                  SDL_WINDOW_SHOWN);
  if (0 == p_sdl_window) {
//     std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
    return;
  }
//   std::cout << "Window created" << std::endl;

  p_sdl_renderer = SDL_CreateRenderer(p_sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (0 == p_sdl_renderer) {
//     std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
    return ;
  }
//   std::cout << "Renderer created" << std::endl;
}

void RenderManager::cleanup()
{
  if (0 != p_sdl_renderer) {
    SDL_DestroyRenderer(p_sdl_renderer);
    p_sdl_renderer = 0;
//     OUT("Renderer destroyed")
  }
  if (0 != p_sdl_window) {
    SDL_DestroyWindow(p_sdl_window);
    p_sdl_window = 0;
//     OUT("Window destroyed")
  }
}

uint32_t RenderManager::get_frame_rate() const
{
  return (time::MILLISECOND / m_frame_rate);
}

void RenderManager::set_frame_rate(uint32_t fps)
{
  m_frame_rate = time::MILLISECOND / fps;
}


}

