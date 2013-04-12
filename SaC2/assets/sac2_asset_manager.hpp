#ifndef _ASSET_MANAGER_HPP_
#define _ASSET_MANAGER_HPP_

/*!
 * \file    sac2_asset_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides AssetManager class
 */

#include "sac2_type.hpp"
#include "sac2_asset.hpp"
#include "sac2_asset_image.hpp"
#include "sac2_asset_music.hpp"
#include "sac2_asset_sound.hpp"
#include "sac2_asset_sprite.hpp"

namespace sac2
{

//! \class AssetManager
/*!
 * \brief   Asset management
 * \warning The class is implemented with Singleton Pattern
 */
class AssetManager
{
 public:

  /*!
   * \brief
   */
  static AssetManager* get_instance();

  /*!
   * \brief  Initialize AssetManager
   * \return SaC2 status
   */
  sac2_status_t initialize();

  /*!
   * \brief  Destroy AssetManager
   * \return SaC2 status
   */
  sac2_status_t finalize();

  /*!
   * \brief  Get the asset specified by \a type and \a id
   * \param  type The type of desired asset
   * \param  id   Identifier of the asset
   * \return Pointer of the asset
   *         Return 0 if the asset is missing
   */
  Asset* get_asset(sac2_asset_type_t type, sac2_asset_id_t id) const;

  /*!
   * \brief  Load the asset specified by \a type
   * \param  type Type of asset to be loaded
   * \return SaC2 status
   */
  sac2_status_t load_asset(sac2_asset_type_t type);

  /*!
   * \brief  Delete the asset specified by \a type
   * \param  type Type of asset to be deleted
   * \return SaC2 status
   */
  sac2_status_t delete_asset(sac2_asset_type_t type);

 protected:

  /*!
   * \brief Private Constructor
   */
  AssetManager();

  /*!
   * \brief Private Destructor
   */
  ~AssetManager();

 private:

  /*!
   * \brief Private copy Constructor
   * \details Copy is NOT allowed
   */
  AssetManager(const AssetManager& asset_manager);

  /*!
   * \brief Private assignment operator
   * \details Copy is NOT allowed
   */
  AssetManager& operator=(const AssetManager& asset_manager);

  static AssetManager* p_asset_manager;          //!< Unique instance
  //! \TODO Add Map asset for musics, sprites, background...
  std::map<asset_id_t, AssetImage*>  m_images;   //!< Store all image assets
  std::map<asset_id_t, AssetMusic*>  m_musics;   //!< Store all music assets
  std::map<asset_id_t, AssetSound*>  m_sounds;   //!< Store all sound assets
  std::map<asset_id_t, AssetSprite*> m_sprites;  //!< Store all sprites assets

};  // class AssetManager


inline AssetManager::AssetManager()
{

}

inline AssetManager::~AssetManager()
{

}

inline AssetManager* AssetManager::get_instance()
{
  if (0 == p_asset_manager) {
    p_asset_manager = new AssetManager;
  }  // if first instance
  return p_asset_manager;
}

inline sac2_status_t AssetManager::initialize()
{
  return STATUS_SUCCESS;
}

inline sac2_status_t AssetManager::finalize()
{
  if (0 != p_asset_manager) {
    delete p_asset_manager;
    p_asset_manager = 0;
    return STATUS_SUCCESS;
  }  // if p_asset_manager is NOT already deleted
  return STATUS_ALREADY;
}

}  // namespace sac2

#endif