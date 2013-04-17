/*!
 * \file    sac2_asset_image.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides class \b AssetImage
 */

#ifndef SAC2_ASSET_IMAGE_HPP
#define SAC2_ASSET_IMAGE_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

//! \class AssetImage
/*!
 * \brief   Image manipulation
 * \details AssetImage is wrapper class of sf::Image, and should NOT be
 *          manipulated directly.
 *          Use AssetSprite instead.
 */
class AssetImage: public Asset<sf::Image>
{
public:

  /*!
   * \brief Constructor
   * \param filename Name of file for loading
   */
  AssetImage(const std::string& filename);

  /*!
   * \brief Destructor
   */
  ~AssetImage();

  /*!
   * \brief  Load the asset
   * \return SaC2 status
   */
  sac2_status_t load_asset();

  /*!
   * \brief  Delete the loaded asset
   * \return SaC2 status
   */
  sac2_status_t delete_asset();

protected:

private:

};  // class AssetImage


inline AssetImage::AssetImage(const std::string& filename):
    Asset<sf::Image>(filename, ASSET_IMAGE)
{

}

inline AssetImage::~AssetImage()
{
  delete_asset();
}

}

#endif  //! SAC2_ASSET_IMAGE_HPP

