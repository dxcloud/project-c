#ifndef ICELOS_SETTING_HPP
#define ICELOS_SETTING_HPP

#include <icelos_type.hpp>

namespace icelos
{

struct setting_t
{
  const string_t APPNAME;
  uint32_t WINDOW_WIDTH;
  uint32_t WINDOW_HEIGHT;
  uint32_t WINDOW_POSITION_X;
  uint32_t WINDOW_POSITION_Y;
  uint32_t WINDOW_FLAGS;
};

} // namespace icelos


#endif // ICELOS_SETTING_HPP

