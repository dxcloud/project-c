#ifndef ICELOS_IMAGE_HPP
#define ICELOS_IMAGE_HPP

#include <icelos_type.hpp>

namespace icelos
{

/// @class Image
/// @brief
/// @note
///   Image manipulation methods are slow operations.
class Image
{
public:
  /// @brief Public default constructor.
  Image();

  /// @brief Public destructor
  ~Image();

  /// @brief Copy an image.
  /// @param[in] source
  ///   Source image to copy.
  /// @param[in] x
  ///   Coordinate-X of the destination position.
  /// @param[in] y
  ///   Coordinate-Y of the destination position.
  /// @param[in] area
  ///   Rectangle of the source image to copy.
  ///   Whether this parameter is omitted, the whole image is copied.
  /// @return
  ///   Status code.
  status_t copy(const Image& source,
                int32_t x,
                int32_t y,
                const rect_t& area=rect_t::EMPTY);

  /// @brief Create a new image.
  /// @param[in] size
  ///   Size of the image.
  /// @param[in] pixels
  ///   Array of pixels for the creation of the image.
  /// @return
  ///   Status code.
  /// @note
  ///   Each pixel must be a 32-bit RGBA value.
  /// @warning
  ///   Whether the length of @b pixels is NOT 'width * height * 4' bytes,
  ///   the behaviour of this method is undefined.
  status_t create(const vector_t& size, void* pixels);

  /// @brief Create a new image.
  /// @param[in] width
  ///   Width of the image.
  /// @param[in] height
  ///   Height of the image.
  /// @param[in] pixels
  ///   Array of pixels for the creation of the image.
  /// @return
  ///   Status code.
  /// @note
  ///   Each pixel must be a 32-bit RGBA value.
  /// @warning
  ///   Whether the length of @b pixels is NOT 'width * height * 4' bytes,
  ///   the behaviour of this method is undefined.
  status_t create(int32_t width, int32_t height, void* pixels);

  /// @brief Load an image from a file.
  /// @param[in] filename
  ///   Filename of the image to load.
  /// @return
  ///   Status code.
  status_t load(const string_t& filename);

  /// @brief Save the image to a file.
  /// @param[in] filename
  ///   Filename of the image to save.
  /// @return
  ///   Status code.
  status_t save(const string_t& filename);

  /// @brief Fill a rectangle with a specific color.
  /// @param[in] area
  ///   Rectangle to fill.
  ///   Whether this parameter is omitted, the entire image is filled by
  ///   the specific color.
  /// @return
  ///   Status code.
  status_t fill(color_t color, const rect_t& area=rect_t::EMPTY);

  /// @brief Get the size of the image.
  /// @return
  ///   Size of the image.
  vector_t get_size() const;

private:
  SDL_Surface* p_sdl_surface;
}; // class Image

} // namespace icelos

#endif // ICELOS_IMAGE_HPP

