/*!
 * \file
 * \author
 * \version
 * \date
 * \brief
 */

#ifndef SAC2_ASSET_FONT_HPP
#define SAC2_ASSET_FONT_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

//! \class AssetFont
/*!
 * \brief
 */
class AssetFont: public Asset<sf::Font>
{
public:
  /*!
   * \brief
   */
  explicit AssetFont(const std::string& filename);

  /*!
   * \brief
   */
  ~AssetFont();

  /*!
   * \brief
   */
  status_t load();

private:
  const std::string m_filename;
};  // class AssetFont


inline AssetFont::AssetFont(const std::string& filename):
    Asset<sf::Font>(ASSET_FONT),
    m_filename(filename)
{

}

inline AssetFont::~AssetFont()
{

}

}  // namespace sac2

#endif //! SAC2_ASSET_FONT_HPP
