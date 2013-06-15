/*!
 * \file    sac2_scene.hpp
 * \author  Chengwu HUANG <chengwhuang@gmail.com>
 * \version 0.1
 * \date    2013 - 05 -17
 * \brief   Provides Scene class
 */

#ifndef SAC2_SCENE_HPP
#define SAC2_SCENE_HPP

#include <string>
#include <map>

#include "sac2_type.hpp"
#include "sac2_asset_sprite.hpp"
#include "sac2_asset_sound.hpp"
#include "sac2_asset_music.hpp"

namespace sac2
{

typedef unsigned int scene_id_t;
typedef unsigned int deep_t;

/*!
 * \class   Scene
 * \brief   Scene management
 * \details 
 */
class Scene
{
public:
  /*!
   * \brief Default constructor
   */
  Scene();

  /*!
   * \brief Constructor
   * \param
   */
  explicit Scene(scene_id_t id);

  /*!
   * \brief Copy constructor
   */
  Scene(const Scene& scene);

  /*!
   * \brief Copy constructor
   */
  Scene& operator=(const Scene& scene);

  /*!
   * \brief Destructor
   */
  ~Scene();

  /*!
   * \brief Remove all scene components (sprites and music)
   */
  void clean();

  /*!
   * \brief  Return the identifier of the scene
   * \return Identifier
   */
  scene_id_t get_scene_id() const;

  /*!
   * \brief Add a sprite on the scene
   * \param id   Identifier of the sprite to be added on the scene
   * \param deep 
   */
//  void add_sprite(const sac2_asset_id_t& id, deep_t deep);

  /*!
   * \brief Test whether the scene contains the sprite which has \b id
   * \param id
   */
//  bool has_sprite(const sac2_asset_type_t& id) const;

  /*!
   * \brief  Get a sprite
   * \param  id Identifier of the sprite
   * \return Return \b NULL whether the sprite is NOT available on the
   *         current scene
   */
//  AssetSprite* get_sprite(const sac2_asset_id_t& id) const;

  /*!
   * \brief Get the current music
   * \return Current music
   */
  AssetMusic* get_music() const;

  /*!
   * \brief Remove a sprite from the scene
   * \param id Identifiier of the sprite to be removed
   */
//  void remove_sprite(const sac2_asset_id_t& id);

  /*!
   * \brief Copy constructor
   */
//  void add_musics(const sac2_asset_id_t& id);

  /*!
   * \brief Replace the current music by another one
   * \param id Identifier of the music to be played instead
   */
//  void replace_music(const sac2_asset_id_t& id);

  /*!
   * \brief Update the scene
   */
  void update();

protected:
  scene_id_t m_identifier;
  std::map<deep_t, AssetSprite*> m_sprites;
  AssetMusic* p_musics;
private:

};  // class Scene


inline Scene::Scene():
  m_identifier(0)
{

}

inline Scene::Scene(scene_id_t id):
  m_identifier(id)
{

}

inline Scene::~Scene()
{
  clean();
}

inline scene_id_t Scene::get_scene_id() const
{
  return m_identifier;
}

inline AssetMusic* Scene::get_music() const
{
  return p_musics;
}

}

#endif //! SAC2_SCENE_HPP
