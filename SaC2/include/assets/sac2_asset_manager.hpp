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
#include <sac2_logger.hpp>

namespace sac2
{



typedef std::map<asset_id_t, const std::string> asset_map_t;
typedef asset_map_t::iterator asset_iter_t;
typedef asset_map_t::const_iterator asset_const_iter_t;

typedef std::map<asset_id_t, sf::Texture*> texture_map_t;
typedef std::map<asset_id_t, sf::Font*> font_map_t;
typedef std::map<asset_id_t, sf::SoundBuffer*> sound_map_t;
typedef texture_map_t::iterator texture_iter_t;
typedef font_map_t::iterator font_iter_t;
typedef sound_map_t::iterator sound_iter_t;

class AssetSprite;
class AssetSound;
class AssetMusic;

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

  status_t get_music(asset_id_t id, AssetMusic& music);
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
  status_t get_sprite(asset_id_t id, AssetSprite& sprite);

  status_t get_sound(asset_id_t id, AssetSound& sound);
  /*!
   * \brief  Load a texture
   * \param  id Identifier of the texture to be loaded
   * \return The following status could be returned
   *         - \b STATUS_SUCCESS
   *         - \b STATUS_FAIL: SFML was NOT to load correctly the texture
   *         - \b STATUS_MISS: There are no texture with \b id as identifier
   */
  status_t load_texture(asset_id_t id);

  status_t load_sound(asset_id_t id);
  /*!
   * \brief Remove an unused texture
   * \param id Identifier of the texture to be unloaded
   * \return The following status could be returned
   *         - \b STATUS_SUCCESS
   *         - \b STATUS_CANCEL: There are no loaded texture with \b id as
   *                             identifier
   */
  status_t unload_texture(asset_id_t id);

  status_t unload_sound(asset_id_t id);

  /*!
   * \brief  Update
   */
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

  template<typename M, typename I, typename R, typename A>
  status_t get_asset(asset_id_t id, A& asset, M& asset_map);

  template<typename M, typename C>
  status_t load_asset(asset_id_t id, M& asset_map);

  template<typename M, typename I>
  status_t unload_asset(asset_id_t id, M& asset_map);

private:
  static const asset_map_t       m_asset_table;  //!< Image type resource name
  font_map_t            m_font_map;
  sound_map_t           m_sound_map;
  texture_map_t         m_texture_map;
};  // class AssetManager

}  // namespace sac2

#include <sac2_asset_manager.inl>

#endif  //! SAC2_ASSET_MANAGER_HPP
