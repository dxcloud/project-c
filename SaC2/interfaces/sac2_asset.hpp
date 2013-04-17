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
 * \details See \b sac2_asset_type_t for a list of available assets
 */
class Asset
{
 public:

  /*!
   * \brief Constructor
   * \param filename The name of file to use for loading
   * \param type     The type of the asset
   */
  Asset(const std::string& filename, sac2_asset_type_t type);

  /*!
   * \brief Destructor
   */
  virtual ~Asset();

  /*!
   * \brief  Test whether the asset is loaded
   * \return Return \b true if the asset is correctly loaded,
   *         \b false otherwise
   */
  virtual bool is_loaded() const;

  /*!
   * \brief  Get the asset
   * \return Asset
   */
  const T& get_asset() const;

  /*!
   * \brief Load an asset
   * \return SaC2 status
   */
  virtual sac2_status_t load_asset() = 0;

  /*!
   * \brief Delete a loaded asset
   * \return SaC2 status
   */
  virtual sac2_status_t delete_asset() = 0;

 protected:

  const std::string m_filename;       //!< Filename
  sac2_asset_type_t m_type;           //!< Type of the asset
  bool              m_load;           //!< \a true if the asset is loaded
  T                 m_asset;          //!< Asset
  AssetManager*     p_asset_manager;  //!< Asset Manager

 private:
};  // class Asset


template<typename T>
inline Asset<T>::Asset(const std::string& filename, sac2_asset_type_t type):
    m_filename(filename),
    m_type(type),
    m_load(false)
{
  p_asset_manager = AssetManager::get_instance();
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
  return m_load;
}

}

#endif  //! SAC2_ASSET_HPP

