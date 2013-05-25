/*!
 * \file    sac2_asset_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides AssetManager class
 */

#ifndef SAC2_ASSET_MANAGER_HPP
#define SAC2_ASSET_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "sac2_type.hpp"
#include "sac2_resources.hpp"
#include "sac2_manager.hpp"

namespace sac2
{

class AssetFont;
class AssetImage;
class AssetMusic;
class AssetSound;
class AssetSprite;
class AssetBuffer;
class AssetText;


//! \class AssetManager
/*!
 * \brief   Asset management
 * \details This class provides asset manipulation utilities.
 *          This class is implemented with Singleton Pattern
 */
class AssetManager: public Manager<AssetManager>
{
public:
  friend class Manager<AssetManager>;
  friend class Resource;

  /*!
   * \brief  Get the asset specified by \a type and \a id
   * \param  type The type of desired asset
   * \param  id   Identifier of the asset
   * \return Pointer of the asset
   *         Return 0 if the asset is missing
   */
  status_t get_sprite(AssetSprite& sprite, const sac2_asset_id_t& id);

  /*!
   * \brief
   */
  status_t add_asset(sac2_asset_type_t type,
                          const sac2_asset_id_t& id);

  /*!
   * \brief  Load the asset specified by \a type
   * \param  type Type of asset to be loaded
   * \return SaC2 status
   */
  status_t load_asset(sac2_asset_type_t type);

  /*!
   * \brief  Delete the asset specified by \a type
   * \param  type Type of asset to be deleted
   * \return SaC2 status
   */
  status_t delete_asset(sac2_asset_type_t type,
                             const sac2_asset_id_t& id);

  status_t load_sprite(AssetSprite& sprite, const sac2_asset_id_t& id);

  status_t load_font(AssetText& text, const sac2_asset_id_t& id);

  status_t load_sound(AssetSound& sound, const sac2_asset_id_t& id);

  status_t load_music(AssetMusic& music, const sac2_asset_id_t& id);

  void load_sprite(const sac2_asset_id_t& id);
  void load_font(const sac2_asset_id_t& id);
  void load_image(const sac2_asset_id_t& id);

  /*!
   * \brief Initialize the manager
   * \return SaC2 status
   */
  status_t initialize();

  status_t update();

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
  AssetManager(const AssetManager&);

  /*!
   * \brief Private assignment operator
   * \details Copy is NOT allowed
   */
  AssetManager& operator=(const AssetManager&);

private:
  Resource                                    m_resource;
  std::map<sac2_asset_id_t, AssetImage*>       m_images;
  std::map<sac2_asset_id_t, sf::Font*>        m_fonts;
  std::map<sac2_asset_id_t, sf::SoundBuffer*> m_sound_buffers;
  std::map<sac2_asset_id_t, AssetSprite*>     m_sprites;
  std::map<sac2_asset_id_t, AssetMusic*>      m_musics;   //!< Store all music asset
};  // class AssetManager


typedef std::map<sac2_asset_id_t, AssetImage*>::iterator asset_image_it;
typedef std::map<sac2_asset_id_t, AssetSprite*>::iterator asset_sprite_it;
typedef std::map<sac2_asset_id_t, AssetMusic*>::iterator asset_music_it;

inline AssetManager::AssetManager():
    Manager<AssetManager>(),
    m_resource()
{

}

inline AssetManager::~AssetManager()
{

}

}  // namespace sac2

#endif  //! SAC2_ASSET_MANAGER_HPP
