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

#include <sac2_type.hpp>
#include <sac2_manager.hpp>
#include <sac2_asset_table.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

typedef std::map<asset_id_t, sf::Texture*> texture_map_t;
typedef texture_map_t::iterator texture_iter_t;

class AssetSprite;
/*
class AssetFont;
class AssetImage;
class AssetMusic;
class AssetSound;
class AssetBuffer;
class AssetText;
*/
/*!
 * \class   AssetManager
 * \brief   Asset management
 * \details This class provides asset manipulation utilities.
 *          This class is implemented with Singleton Pattern
 */
class AssetManager:
  public Manager<AssetManager>
{
public:
  friend class Manager<AssetManager>;

public:

  /*!
   * \brief   Get the sprite specified by \b id. Attribute of this class
   *          could be modified by this method
   * \param   sprite A texture will be set into this parameter
   * \param   id     Identifier of the texture to be used
   * \details This method will search the loaded texture which is specified
   *          by \b id, if the texture has NOT been found, the method
   *          \b load_texture will be called.
   * \return  The following status could be returned:
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_ERROR: Error from \b load_texture
   * \warning Check the returned status before using the sprite.
   */
  status_t get_sprite(AssetSprite& sprite, asset_id_t id);

  /*!
   * \brief  Load a texture
   * \param  id Identifier of the texture to be loaded
   * \return The following status could be returned
   *         - \b STATUS_SUCCESS
   *         - \b STATUS_FAIL: SFML was NOT to load correctly the texture
   *         - \b STATUS_MISS: There are no texture with \b id as identifier
   */
  status_t load_texture(asset_id_t id);

  /*!
   * \brief Remove an unused texture
   * \param id Identifier of the texture to be unloaded
   * \return The following status could be returned
   *         - \b STATUS_SUCCESS
   *         - \b STATUS_CANCEL: There are no loaded texture with \b id as
   *                             identifier
   */
  status_t unload_texture(asset_id_t id);

  /*!
   * \brief
   */
//  status_t add_asset(sac2_asset_type_t type,
//                          const sac2_asset_id_t& id);

  /*!
   * \brief  Load the asset specified by \a type
   * \param  type Type of asset to be loaded
   * \return SaC2 status
   */
//  status_t load_asset(sac2_asset_type_t type);

  /*!
   * \brief  Delete the asset specified by \a type
   * \param  type Type of asset to be deleted
   * \return SaC2 status
   */
//  status_t delete_asset(sac2_asset_type_t type,
//                             const sac2_asset_id_t& id);

//  status_t load_sprite(AssetSprite& sprite, asset_id_t id);
//  AssetSprite* get_sprite(asset_id_t id);

//  status_t load_font(AssetText& text, const sac2_asset_id_t& id);

//  status_t load_sound(AssetSound& sound, const sac2_asset_id_t& id);

//  status_t load_music(AssetMusic& music, const sac2_asset_id_t& id);

//  void load_sprite(const sac2_asset_id_t& id);
//  void load_font(const sac2_asset_id_t& id);
//  void load_image(const sac2_asset_id_t& id);


  void update();

protected:
  /*!
   * \brief Protected default constructor
   */
  AssetManager();

  /*!
   * \brief Protected default destructor
   */
  virtual ~AssetManager();

  /*!
   * \brief Removed all loaded resource
   */
  void cleanup();

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
  AssetTable            m_asset_table;
  texture_map_t         m_textures;
//  std::map<sac2_asset_id_t, sf::Font*>        m_fonts;
//  std::map<sac2_asset_id_t, sf::SoundBuffer*> m_sound_buffers;
//  std::map<sac2_asset_id_t, AssetSprite*>     m_sprites;
//  std::map<sac2_asset_id_t, AssetMusic*>      m_musics;   //!< Store all music asset
};  // class AssetManager


//typedef std::map<sac2_asset_id_t, AssetImage*>::iterator asset_image_it;
//typedef std::map<sac2_asset_id_t, AssetSprite*>::iterator asset_sprite_it;
//typedef std::map<sac2_asset_id_t, AssetMusic*>::iterator asset_music_it;

}  // namespace sac2

#endif  //! SAC2_ASSET_MANAGER_HPP
