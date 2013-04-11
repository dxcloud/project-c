#ifndef _ASSET_SPRITE_HPP_
#define _ASSET_SPRITE_HPP_

/*!
 * \file    sac2_asset_sprite.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides class \b AssetSprite
 */

#include <string>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

//! \class AssetSprite
/*!
 * \brief Sprite manipulation
 */
class AssetSprite: public Asset
{
 public:

  /*!
   * \brief Constructor
   * \param filename Name of file for loading
   */
  AssetSprite(const std::string& filename):
    Asset(filename, ASSET_SPRITE),
    p_sprite(new sf::Sprite)
  {}

  /*!
   * \brief Destructor
   */
  ~AssetSprite()
  {
    delete_asset();
  }

  /*!
   * \brief Set the position of the sprite
   * \param x New x coordonate
   * \param y New y coordonate
   * \return SaC2 status
   */
  sac2_status_t set_position(float x, float y)
  {
    p_sprite->SetPosition(x, y);

    return STATUS_SUCCESS;
  }

  /*!
   * \brief Resize the sprite
   * \param w 
   * \param h
   * \return SaC2 status
   */
  sac2_status_t resize(float x, float y)
  {
    p_sprite->Resize(x, y);

    return STATUS_SUCCESS;
  }

  /*!
   * \brief Flip the sprite horizontally/vertically
   * \param h
   * \param v
   * \return SaC2 status
   */
  sac2_status_t flip(bool flip_x, bool flip_y)
  {
    if (true == flip_x) p_sprite->FlipX(true);
    if (true == flip_y) p_sprite->FlipY(true);

    return STATUS_SUCCESS;
  }

  /*!
   * \brief  Load the asset
   * \return SaC2 status
   */
  virtual sac2_status_t load_asset();

  /*!
   * \brief  Delete the loaded asset
   * \return SaC2 status
   */
  virtual sac2_status_t delete_asset();
 protected:
 
 private:

  sf::Sprite*  p_sprite;  //!< Image asset
};  // class AssetSprite

}

#endif