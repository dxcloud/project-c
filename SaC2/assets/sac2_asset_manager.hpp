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
#include "sac2_manager.hpp"
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
class AssetManager: public Manager<AssetManager>
{
 public:

  friend class Manager<AssetManager>;

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

}  // namespace sac2

#endif