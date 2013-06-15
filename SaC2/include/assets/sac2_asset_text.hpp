/*!
 * \file
 * \author
 * \version
 * \date
 * \brief
 */

#ifndef SAC2_ASSET_TEXT_HPP
#define SAC2_ASSET_TEXT_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_drawable.hpp"

namespace sac2
{

class AssetText:
  public Drawable<sf::String>
{
public:
  /*!
   * \brief
   */
  AssetText();

  /*!
   * \brief
   */
  ~AssetText();

  /*!
   * \brief
   */
  status_t set_text(const std::string& text);

  /*!
   * \brief
   */
  status_t set_font(const sf::Font& font);
};  // class AssetText


inline AssetText::AssetText():
  Drawable<sf::String>()
{

}

inline AssetText::~AssetText()
{

}

}  // namespace sac2

#endif  //! SAC2_ASSET_TEXT_HPP
