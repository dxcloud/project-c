#include <icelos_image.hpp>
#include <icelos_function.hpp>

namespace icelos
{

Image::Image():
  p_sdl_surface(nullptr)
{
  OUT("instanciation image")
}

Image::~Image()
{
  OUT("image call dtor")
  if (nullptr != p_sdl_surface) {
    SDL_FreeSurface(p_sdl_surface);
    p_sdl_surface = nullptr;
  }
}

vector_t Image::get_size() const
{
  if (nullptr == p_sdl_surface) { return vector_t(0, 0); }
  return vector_t(p_sdl_surface->w, p_sdl_surface->h);
}

status_t Image::create(const vector_t& size, void* pixels)
{
  return create(size.w, size.h, pixels);
}

status_t Image::create(int32_t width, int32_t height, void* pixels)
{
  p_sdl_surface = SDL_CreateRGBSurfaceFrom(pixels,
                                           width,
                                           height,
                                           color::BITS_PER_PIXEL,
                                           width * color::BYTES_PER_PIXEL,
                                           color::COLOR_R_MASK,
                                           color::COLOR_G_MASK,
                                           color::COLOR_B_MASK,
                                           color::COLOR_A_MASK);
  ICELOS_SDL_PTR_CHECK(p_sdl_surface)
  return STATUS_SUCCESS;
}

status_t Image::load(const string_t& filename)
{
  p_sdl_surface = IMG_Load(filename.c_str());
  ICELOS_SDL_PTR_CHECK(p_sdl_surface);
  return STATUS_SUCCESS;
}

status_t Image::save(const string_t& filename)
{
  if (nullptr == p_sdl_surface) { return STATUS_CANCEL; }
  ICELOS_SDL_CHECK(IMG_SavePNG(p_sdl_surface, filename.c_str()))
  return STATUS_SUCCESS;
}

status_t Image::copy(const Image& source, int32_t x, int32_t y, const rect_t& area)
{
  if (nullptr == source.p_sdl_surface) { return STATUS_CANCEL; }
  SDL_Rect dest_rect{x, y, 0, 0};
  if (rect_t::EMPTY == area) {
    ICELOS_SDL_CHECK(SDL_BlitSurface(source.p_sdl_surface,
                                     nullptr,
                                     p_sdl_surface,
                                     &dest_rect))
  }
  else {
    SDL_Rect src_rect = func::to_sdl_rect(area);
    ICELOS_SDL_CHECK(SDL_BlitSurface(source.p_sdl_surface,
                                     &src_rect,
                                     p_sdl_surface,
                                     &dest_rect))
  }
  return STATUS_SUCCESS;
}


status_t Image::fill(color_t color, const rect_t& area)
{
  if (nullptr == p_sdl_surface) { return STATUS_CANCEL; }
  uint32_t sdl_color = SDL_MapRGB(p_sdl_surface->format,
                                  color.r,
                                  color.g,
                                  color.b);
  OUT("sdl color="<<sdl_color)
  if (rect_t::EMPTY != area) {
    SDL_Rect sdl_rect = func::to_sdl_rect(area);
    ICELOS_SDL_CHECK(SDL_FillRect(p_sdl_surface, &sdl_rect, sdl_color))
  }
  else {
    ICELOS_SDL_CHECK(SDL_FillRect(p_sdl_surface, nullptr, sdl_color))
  }
  return STATUS_SUCCESS;
}



}

