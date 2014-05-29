////////////////////////////////////////////////////////////////////////////////
/// @file    icelos_color.hpp
/// @brief   Provides Icelos color manipulation class.
/// @date    2014-05-28
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef ICELOS_COLOR_HPP
#define ICELOS_COLOR_HPP

#include <SDL2/SDL_pixels.h>

#if defined(ICELOS_COLOR)
#  define R color.r
#  define G color.g
#  define B color.b
#  define A color.a
#endif

namespace icelos
{

////////////////////////////////////////////////////////////////////////////////
/// @class   Color
/// @brief   This class is basically a wrapper class of @b SDL_Color.
/// @details
///   
////////////////////////////////////////////////////////////////////////////////
class Color
{
public:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public default consturctor.
  /// @details
  ///   The default constructor initializes a color to black.
  //////////////////////////////////////////////////////////////////////////////
  Color();

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override consturctor.
  /// @param[in] r
  ///   Level of red component.
  /// @param[in] g
  ///   Level of green component.
  /// @param[in] b
  ///   Level of blue component.
  /// @param[in] a
  ///   Level of alpha component.
  //////////////////////////////////////////////////////////////////////////////
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public override consturctor.
  /// @param[in] c
  ///   HTML color code.
  /// @details
  ///   This constructor initializes a color with HTML color code.
  /// @code
  ///   Color red_color(0xFF0000); // hexadecimal value for red
  /// @endcode
  //////////////////////////////////////////////////////////////////////////////
  explicit Color(uint32_t c);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Public destructor
  //////////////////////////////////////////////////////////////////////////////
  ~Color();

public:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief @a SDL_Color structure.
  /// @details
  ///   This is a public member. The value of each color component can be
  ///   modified by using @b SDL_Color structure field. Besides whether
  ///   the constant @b ICELOS_COLOR is defined, color component can be accessed
  ///   by using fields @b R, @b G, @b B and @b A.
  /// @code
  ///   #define ICELOS_COLOR
  ///
  ///   Color sample;
  ///   sample.color.r = 255; // set red component to 255.
  ///   sample.R = 255;       // does same thing as above.
  /// @endcode
  //////////////////////////////////////////////////////////////////////////////
  SDL_Color color;
};

////////////////////////////////////////////////////////////////////////////////
inline Color::Color()
{
  color.r = 0U;
  color.g = 0U;
  color.b = 0U;
  color.a = 255U;
}

////////////////////////////////////////////////////////////////////////////////
inline Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
}

////////////////////////////////////////////////////////////////////////////////
inline Color::Color(uint32_t c)
{
  color.r = (uint8_t) ((c & 0xFF000000) >> 16);
  color.g = (uint8_t) ((c & 0x00FF0000) >> 8);
  color.b = (uint8_t) ((c & 0x0000FF00) >> 0);
  color.a = 255U;
}

////////////////////////////////////////////////////////////////////////////////
inline Color::~Color()
{
  // nothing to do
}

////////////////////////////////////////////////////////////////////////////////
/// @namespace color
/// @brief   Namespace containing common color.
////////////////////////////////////////////////////////////////////////////////
namespace color
{

const Color RED(255, 0 , 0);         ///< Color red
const Color GREEN(0, 255, 0);        ///< Color green
const Color BLUE(0, 0, 255);         ///< Color blue
const Color YELLOW(255, 255, 0);     ///< Color yellow
const Color MAGENTA(255, 0, 255);    ///< Color magenta
const Color CYAN(0, 255, 255);       ///< Color cyan
const Color WHITE(255, 255, 255);    ///< Color white
const Color BLACK(0, 0, 0);          ///< Color black
const Color GRAY(128, 128, 128);     ///< Color gray
const Color SILVER(192, 192, 192);   ///< Color silver
const Color GOLD(255, 215, 0);       ///< Color gold
const Color INDIGO(75, 0, 130);      ///< Color indigo
const Color ORANGE(255, 127, 0);     ///< Color orange
const Color MAROON(128, 0, 0);       ///< Color maroon
const Color TRANSPARENT(0, 0, 0, 0); ///< Color tranparent

}

}

#endif /// ICELOS_COLOR_HPP

