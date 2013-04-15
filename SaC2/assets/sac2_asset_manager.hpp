﻿#ifndef _SAC2_ASSET_MANAGER_HPP_
#define _SAC2_ASSET_MANAGER_HPP_

/*!
 * \file    sac2_asset_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides AssetManager class
 */

#include "sac2_type.hpp"
#include "sac2_manager.hpp"
#include "sac2_drawable.hpp"

namespace sac2
{

class Engine;
//class Asset;
class AssetImage;
class AssetMusic;
class AssetSound;
class AssetSprite;

//! \class AssetManager
/*!
 * \brief   Asset management
 * \warning The class is implemented with Singleton Pattern
 */
class AssetManager: public Manager<AssetManager>
{
 public:

  friend class Manager<AssetManager>;

  sac2_status_t initialize(Engine* engine) {
    p_engine = engine;
    return STATUS_SUCCESS;
  }

  /*!
   * \brief  Get the asset specified by \a type and \a id
   * \param  type The type of desired asset
   * \param  id   Identifier of the asset
   * \return Pointer of the asset
   *         Return 0 if the asset is missing
   */
  AssetImage* get_asset(sac2_asset_type_t type, const sac2_asset_id_t& id) const;

  /*!
   * \brief
   */
  sac2_status_t add_asset(sac2_asset_type_t type,
                          const std::string& filename,
                          const sac2_asset_id_t& id="");

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

  sac2_status_t update(Engine* engine);

  sac2_status_t draw(Drawable* drawable);

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

  Engine* p_engine;
  //! \TODO Add Map asset for musics, sprites, background...
  std::map<sac2_asset_id_t, AssetImage*>  m_images;   //!< Store all image assets
  std::map<sac2_asset_id_t, AssetMusic*>  m_musics;   //!< Store all music assets
  std::map<sac2_asset_id_t, AssetSound*>  m_sounds;   //!< Store all sound assets
  std::map<sac2_asset_id_t, AssetSprite*> m_sprites;  //!< Store all sprites assets

};  // class AssetManager


inline AssetManager::AssetManager(): p_engine(0)
{

}

inline AssetManager::~AssetManager()
{

}

}  // namespace sac2

#endif  //! _SAC2_ASSET_MANAGER_HPP_
