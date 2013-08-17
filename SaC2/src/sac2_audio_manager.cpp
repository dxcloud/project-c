//////////////////////////////////////////////////////////////////////////////
//! \file sac2_audio_manager.cpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (alpha)
//! \date
//!     2013-07-03
//////////////////////////////////////////////////////////////////////////////

#include <sac2_audio_manager.hpp>
#include <sac2_asset_manager.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
// AudioManager::AudioManager
//////////////////////////////////////////////////////////////////////////////
AudioManager::AudioManager():
  m_sound_map()
{
  LOG_DEBUG("AudioManager::ctor - successfully initialized")
}

//////////////////////////////////////////////////////////////////////////////
// AudioManager::~AudioManager
//////////////////////////////////////////////////////////////////////////////
AudioManager::~AudioManager()
{
  LOG_DEBUG("AudioManager::dtor - successfully destroyed")
}

//////////////////////////////////////////////////////////////////////////////
// AudioManager::play_sound
//////////////////////////////////////////////////////////////////////////////
status_t AudioManager::play_sound(asset_id_t id)
{
  if (m_sound_map.end() == m_sound_map.find(id)) {
    if (STATUS_SUCCESS != AssetManager::instance().load_sound(id)) {
      return STATUS_ERROR;
    }
    sf::Sound* sound(new sf::Sound);
    sound->setBuffer(*(AssetManager::instance().m_buffer_map[id]));
    m_sound_map.insert(std::make_pair(id, sound));
  }  // sound
  m_sound_map[id]->play();
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AudioManager::pause_sound
//////////////////////////////////////////////////////////////////////////////
status_t AudioManager::pause_sound(asset_id_t id)
{
  if (m_sound_map.end() == m_sound_map.find(id)) { return STATUS_CANCEL; }
  m_sound_map[id]->pause();
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AudioManager::stop_sound
//////////////////////////////////////////////////////////////////////////////
status_t AudioManager::stop_sound(asset_id_t id)
{
  if (m_sound_map.end() == m_sound_map.find(id)) { return STATUS_CANCEL; }
  m_sound_map[id]->stop();
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AudioManager::play_music
//////////////////////////////////////////////////////////////////////////////
status_t AudioManager::play_music(asset_id_t id)
{
  if (AssetManager::instance().m_music_map.end()
      == AssetManager::instance().m_music_map.find(id)) {
    return STATUS_CANCEL;
  }
  AssetManager::instance().m_music_map[id]->play();
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AudioManager::pause_music
//////////////////////////////////////////////////////////////////////////////
status_t AudioManager::pause_music(asset_id_t id)
{
  if (AssetManager::instance().m_music_map.end()
      == AssetManager::instance().m_music_map.find(id)) {
    return STATUS_CANCEL;
  }
  AssetManager::instance().m_music_map[id]->pause();
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AudioManager::stop_music
//////////////////////////////////////////////////////////////////////////////
status_t AudioManager::stop_music(asset_id_t id)
{
  if (AssetManager::instance().m_music_map.end()
      == AssetManager::instance().m_music_map.find(id)) {
    return STATUS_CANCEL;
  }
  AssetManager::instance().m_music_map[id]->stop();
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AudioManager::cleanup
//////////////////////////////////////////////////////////////////////////////
void AudioManager::cleanup()
{
  for (sound_iter_t iter(m_sound_map.begin());
       iter != m_sound_map.end();
       ++iter) {
    delete iter->second;
    iter->second = 0;
  }
  m_sound_map.clear();
}

}  // namespace sac2
