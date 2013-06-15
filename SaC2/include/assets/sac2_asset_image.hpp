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
 * \details \b AssetImage is a wrapper of class \b sf::Image,
 *          and should NOT be directly manipulated (\b AssetManager excepted).
 *          Use class \b AssetSprite instead.
 */
class AssetImage: public Asset<sf::Image>
{
public:
  /*!
   * \brief Constructor
   * \param filename Name of file for loading
   */
  explicit AssetImage(const std::string& filename);
  AssetImage();

  /*!
   * \brief Destructor
   */
  ~AssetImage();

  /*!
   * \brief  Load the image from a file
   * \return Return SaC2 Status:
   *         - \b STATUS_SUCCESS
   *         - \b STATUS_ALREADY
   *         - \b STATUS_FAIL
   */
  status_t load();

  status_t load(const std::string& filename);

private:
//  const std::string m_filename;  //!< Filename of the image

};  // class AssetImage


inline AssetImage::AssetImage():
  Asset<sf::Image>()
{

}

inline AssetImage::AssetImage(const std::string& filename):
    Asset<sf::Image>()
{

}

inline AssetImage::~AssetImage()
{

}

}  //namespace sac2

#endif  //! SAC2_ASSET_IMAGE_HPP
