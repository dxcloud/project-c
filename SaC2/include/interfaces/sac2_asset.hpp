/*!
 * \file    sac2_asset.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides basic Asset used by the class \b AssetManager
 */

#ifndef SAC2_ASSET_HPP
#define SAC2_ASSET_HPP

namespace sac2
{

/*!
 * \class   Asset
 * \brief   Base virtual class for assets
 * \details An Asset could be:
 *          - sf::Sprite
 *          - sf::Sound
 *          - sf::Music
 *          - sf::Text
 *          This template class is basically a wrapper class for SFML
 *          graphical or audio elements.
 */
template<typename T>
class Asset
{
public:
  /*!
   * \brief Default constructor
   */
  Asset();

  /*!
   * \brief Default destructor
   */
  virtual ~Asset();

  /*!
   * \brief  Get SFML Graphical or Audio element
   * \return 
   */
  const T& get_asset() const;

protected:
  T m_asset;   //!< SFML Asset
};  // class Asset


//----------------------------------------------------------------------------
//  Asset::Asset
//----------------------------------------------------------------------------
template<typename T>
inline Asset<T>::Asset()
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Asset::~Asset
//----------------------------------------------------------------------------
template<typename T>
inline Asset<T>::~Asset()
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Asset::get_asset
//----------------------------------------------------------------------------
template<typename T>
inline const T& Asset<T>::get_asset() const
{
  return m_asset;
}

}  // namespace sac2

#endif  //! SAC2_ASSET_HPP
