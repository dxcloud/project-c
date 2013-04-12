#ifndef _ASSET_IMAGE_HPP_
#define _ASSET_IMAGE_HPP_

/*!
 * \file    sac2_asset_image.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides class \b AssetImage
 */

#include <string>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

//! \class AssetImage
/*!
 * \brief Image manipulation
 */
class AssetImage: public Asset
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

  sf::Image* p_image;  //!< Image asset
};  // class AssetImage


inline AssetImage::AssetImage(const std::string& filename):
    Asset(filename, ASSET_IMAGE),
    p_image(new sf::Image)
{

}

inline AssetImage::~AssetImage()
{
  delete_asset();
}

}

#endif