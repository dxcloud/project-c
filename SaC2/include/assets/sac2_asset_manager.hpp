//////////////////////////////////////////////////////////////////////////////
//! \file sac2_asset_manager.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.2 (alpha)
//! \date
//!     2013-04-08: Initial develepment.
//! \date
//!     2013-08-16: Include sound and music management.
//! \brief
//!     Provides AssetManager class.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_ASSET_MANAGER_HPP
#define SAC2_ASSET_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <sac2_manager.hpp>

namespace sac2
{

// forward declaration
class SpriteAsset;
class FontAsset;
class AudioManager;

//////////////////////////////////////////////////////////////////////////////
//! \class AssetManager
//! \brief
//!     Class provides asset management utilities.
//! \details
//!     This class is a central class for managing assets.
//!     Resource may include Texture, Font, etc, and are loaded from files.
//!     The AssetManager contain a list of all asset filenames. This list
//!     must be initialized by the user, and cannot be modified in runtime.
//! \note
//!     This class is implemented with Singleton Pattern
//////////////////////////////////////////////////////////////////////////////
class AssetManager:
  public Manager<AssetManager>
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Allows to call constructor and destructor of private attribute.
  ////////////////////////////////////////////////////////////////////////////
  friend class Manager<AssetManager>;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Delegates sound and music resources.
  ////////////////////////////////////////////////////////////////////////////
  friend class AudioManager;

  ////////////////////////////////////////////////////////////////////////////
  //! \typedef asset_map_t
  //! \brief
  //!     Map, associates an ID with a filename.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::map<asset_id_t, const string_t>   asset_map_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \typedef asset_iter_t
  //! \brief
  //!     Iterator, equivalent to \b asset_map_t::iterator.
  //! \see AssetManager::asset_map_t
  ////////////////////////////////////////////////////////////////////////////
  typedef asset_map_t::iterator                  asset_iter_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \typedef asset_const_iter_t
  //! \brief
  //!     Constant Iterator, equivalent to \b asset_map_t::const_iterator.
  //! \see AssetManager::asset_map_t
  ////////////////////////////////////////////////////////////////////////////
  typedef asset_map_t::const_iterator            asset_const_iter_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \typedef texture_map_t
  //! \brief
  //!     Map, associates an ID with a loaded texture.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::map<asset_id_t, sf::Texture*>     texture_map_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \typedef font_map_t
  //! \brief
  //!     Map, associates an ID with a loaded font.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::map<asset_id_t, sf::Font*>        font_map_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \typedef music_map_t
  //! \brief
  //!     Map, associates an ID with a music resource.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::map<asset_id_t, sf::Music*>       music_map_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \typedef buffer_map_t
  //! \brief
  //!     Map, associates an ID with a sound resource.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::map<asset_id_t, sf::SoundBuffer*> buffer_map_t;

public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Explicitly load a texture.
  //! \param[in] id
  //!     Identifier of the texture to load.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully loaded the texture.
  //! \retval STATUS_FAIL
  //!     Failed to load the texture.
  //! \retval STATUS_MISS
  //!     Specified texture NOT found.
  //! \note
  //!     This method is called when the texture to use is NOT loaded yet.
  ////////////////////////////////////////////////////////////////////////////
  status_t load_texture(asset_id_t id);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Explicitly unload and remove a texture.
  //! \param[in] id
  //!     Identifier of the texture to unload.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully unload the texture.
  //! \retval STATUS_CANCEL
  //!     Specified texture is already unloaded.
  ////////////////////////////////////////////////////////////////////////////
  status_t unload_texture(asset_id_t id);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Load the sprite by the texture specified by \b id.
  //! \details
  //!     This method will search the loaded texture list first.
  //!     If the texture is NOT loaded yet, it will try to load the texture
  //!     specified by \b id, and then load the sprite by the texture.
  //! \param[in] id
  //!     Identifier of the texture to load.
  //! \param[out] sprite
  //!     Sprite to load to.
  //!     This paramter left inchanged whether the texture is NOT found.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully set the texture.
  //! \retval STATUS_ERROR
  //!     Failed to load the texture.
  //! \note
  //!     Check the returned status code before using the sprite.
  ////////////////////////////////////////////////////////////////////////////
  status_t use_texture(asset_id_t id, SpriteAsset& sprite);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Explicitly load a sound buffer.
  //! \param[in] id
  //!     Identifier of the sound buffer to load.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully loaded the sound buffer.
  //! \retval STATUS_FAIL
  //!     Failed to load the sound buffer.
  //! \retval STATUS_MISS
  //!     Specified sound buffer NOT found.
  //! \note
  //!     This method is called when the sound to use is NOT loaded yet.
  ////////////////////////////////////////////////////////////////////////////
  status_t load_sound(asset_id_t id);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Explicitly unload and remove a sound buffer.
  //! \param[in] id
  //!     Identifier of the sound buffer to unload.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully unload the sound buffer.
  //! \retval STATUS_CANCEL
  //!     Specified sound buffer is already unloaded.
  ////////////////////////////////////////////////////////////////////////////
  status_t unload_sound(asset_id_t id);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Explicitly load a music track.
  //! \param[in] id
  //!     Identifier of the music to load.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully loaded the music.
  //! \retval STATUS_FAIL
  //!     Failed to load the music.
  //! \retval STATUS_MISS
  //!     Specified music resource NOT found.
  ////////////////////////////////////////////////////////////////////////////
  status_t load_music(asset_id_t id);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Explicitly unload and remove a music.
  //! \param[in] id
  //!     Identifier of the music to unload.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully unload the musice.
  //! \retval STATUS_CANCEL
  //!     Specified music buffer is already unloaded.
  ////////////////////////////////////////////////////////////////////////////
  status_t unload_music(asset_id_t id);

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Collection of filenames.
  ////////////////////////////////////////////////////////////////////////////
  static const asset_map_t m_asset_table;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Collection of font resources.
  ////////////////////////////////////////////////////////////////////////////
  font_map_t               m_font_map;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Collection of music resources.
  ////////////////////////////////////////////////////////////////////////////
  music_map_t              m_music_map;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Collection of sound resources.
  ////////////////////////////////////////////////////////////////////////////
  buffer_map_t             m_buffer_map;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Collection of texture resources.
  ////////////////////////////////////////////////////////////////////////////
  texture_map_t            m_texture_map;

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private default constructor.
  ////////////////////////////////////////////////////////////////////////////
  AssetManager();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private default constructor.
  ////////////////////////////////////////////////////////////////////////////
  ~AssetManager();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private copy constructor.
  ////////////////////////////////////////////////////////////////////////////
  AssetManager(const AssetManager&);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private assignment operator.
  ////////////////////////////////////////////////////////////////////////////
  AssetManager& operator=(const AssetManager&);

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Remove all loaded assets.
  ////////////////////////////////////////////////////////////////////////////
  void cleanup();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Template method for setting asset.
  //! \tparam M
  //!     Asset map type.
  //! \tparam R
  //!     SFML resource type.
  //! \tparam A
  //!     Asset type.
  //! \param id
  //!     Identifier of the asset to use.
  //! \param asset
  //!     Resource to load to.
  //! \param asset_map
  //!     Map containing loaded asset.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully set the asset.
  //! \retval STATUS_ERROR
  //!     Failed to load the asset.
  ////////////////////////////////////////////////////////////////////////////
  template<typename M, typename R, typename A>
  status_t use_asset(asset_id_t id, A& asset, M& asset_map);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Template method for loading asset.
  //! \tparam M
  //!     Asset map type.
  //! \tparam R
  //!     SFML resource type.
  //! \param id
  //!     Identifier of the asset to load.
  //! \param asset_map
  //!     Map containing loaded asset.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully loaded the texture.
  //! \retval STATUS_FAIL
  //!     Failed to load the texture.
  //! \retval STATUS_MISS
  //!     Specified texture NOT found.
  ////////////////////////////////////////////////////////////////////////////
  template<typename M, typename R>
  status_t load_asset(asset_id_t id, M& asset_map);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Template method for unloading asset.
  //! \param id
  //!     Identifier of the asset to load.
  //! \param asset_map
  //!     Map containing loaded assets.
  //! \return
  //!     The following status could be returned:
  //!     - \b STATUS_SUCCESS: successfully unload the texture.
  //!     - \b STATUS_CANCEL:  specified texture is already unloaded.
  ////////////////////////////////////////////////////////////////////////////
  template<typename M>
  status_t unload_asset(asset_id_t id, M& asset_map);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Template method for removing all loaded asset.
  //! \param asset_map
  //!     Map containing loaded assets.
  ////////////////////////////////////////////////////////////////////////////
  template<typename M>
  void remove_asset(M& asset_map);
};  // class AssetManager

}  // namespace sac2

#include <sac2_asset_manager.inl>

#endif  //! SAC2_ASSET_MANAGER_HPP
