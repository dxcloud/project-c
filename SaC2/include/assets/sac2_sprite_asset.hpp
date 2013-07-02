//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_sprite_asset.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (development version)
//! \date
//!     2013-07-01
//! \brief
//!     Provides sprite asset manipulation class.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_SPRITE_ASSET_HPP
#define SAC2_SPRITE_ASSET_HPP

#include <SFML/Graphics.hpp>

#include <sac2_graphic_asset.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
//! \brief
//////////////////////////////////////////////////////////////////////////////
class SpriteAsset:
  public GraphicAsset<sf::Sprite>
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Public default constructor
  ////////////////////////////////////////////////////////////////////////////
  SpriteAsset();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Public default destructor
  ////////////////////////////////////////////////////////////////////////////
  ~SpriteAsset();

public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Load the source texture of the sprite
  //! \param[in] texture
  //!     Texture to use by the sprite
  //! \details
  //!     If the source texture changed, the sprite will automatically
  //!     adjust its size.
  ////////////////////////////////////////////////////////////////////////////
  void load(const sf::Texture& texture);

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private copy constructor
  ////////////////////////////////////////////////////////////////////////////
  SpriteAsset(const SpriteAsset&);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private assignement operator
  ////////////////////////////////////////////////////////////////////////////
  SpriteAsset& operator=(const SpriteAsset&);
};  // class SpriteAsset

}  // namespace sac2

#include <sac2_sprite_asset.inl>

#endif  //! SAC2_SPRITE_ASSET_HPP
