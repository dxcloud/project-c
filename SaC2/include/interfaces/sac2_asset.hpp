/*!
 * \file    sac2_asset.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides basic Asset used by the class \b AssetManager
 */

#ifndef SAC2_ASSET_HPP
#define SAC2_ASSET_HPP

#include <string>

#include "sac2_type.hpp"
#include "sac2_asset_manager.hpp"

namespace sac2
{

template<typename T>

//! \class Asset
/*!
 * \brief   Basic virtual class for assets
 * \details \see \b sac2_asset_type_t for the list of available assets
 */
class Asset
{
public:
  /*!
   * \brief Constructor
   * \param type The type of the asset
   */
  explicit Asset(sac2_asset_type_t type);

  /*!
   * \brief Destructor
   */
  virtual ~Asset();

  /*!
   * \brief  Test whether the asset is loaded
   * \return Return \b true if the asset is correctly loaded,
   *         \b false otherwise
   */
  bool is_loaded() const;

  /*!
   * \brief  Get the asset
   * \return Asset
   */
  const T& get_asset() const;

protected:
  sac2_asset_type_t m_type;    //!< Type of the asset
  bool              m_loaded;  //!< \a true if the asset is loaded
  T                 m_asset;   //!< Asset
};  // class Asset


template<typename T>
inline Asset<T>::Asset(sac2_asset_type_t type):
    m_type(type),
    m_loaded(false)
{

}

template<typename T>
inline Asset<T>::~Asset()
{
  // do nothing
}

template<typename T>
inline const T& Asset<T>::get_asset() const
{
  return m_asset;
}

template<typename T>
inline bool Asset<T>::is_loaded() const
{
  return m_loaded;
}

}  // namespace sac2

#endif  //! SAC2_ASSET_HPP
