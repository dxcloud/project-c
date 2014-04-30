//////////////////////////////////////////////////////////////////////////////
//! \file test_03
//! \author
//!     Chengwu Huang
//! \date
//!     2013-08-17
//! \brief
//!     Test \b sac2::AssetManager and \b sac2::AudioManager functionalities.
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <sac2_asset_manager.hpp>
#include <sac2_audio_manager.hpp>

#include "resource.hpp"

// test_error_t load_sound(int id)
// {
//   return load_asset<std::map<int, sf::SoundBuffer*>, sf::SoundBuffer>(id, snd_map);
// }

// void test_03()
// {
// #ifdef USE_SFML_INSTEAD
//   std::cout << "Using SFML" << std::endl;
//  if (snd_map.end() != snd_map.find(SOUND1)) { return; }
//  sf::SoundBuffer* sound_buff(new sf::SoundBuffer);
//  if (false == sound_buff->loadFromFile(asset_map.at(SOUND1))) {
//    std::cout << "loading failed" << std::endl;
//    delete sound_buff;
//    return;
//  }
//  std::cout << "loading success" << std::endl;
//   load_sound(1);
//   if (snd_map.end() != snd_map.find(1)) {
//     return;
//   }  // if asset_map contains `id'
//   if (test_asset_table.end() == test_asset_table.find(1)) {
//     return;
//   }  // m_asset_table does NOT contain `id'
//   sf::SoundBuffer* sound_buff(new sf::SoundBuffer);
//   if (false == sound_buff->loadFromFile(test_asset_table.at(1))) {
//     delete sound_buff;
//     return;
//   }  // error from SFML
//   snd_map.insert(std::make_pair(1, sound_buff));
//  sf::Texture* texture = new sf::Texture;
//  texture->loadFromFile(test_image_1);
//  sf::Sprite sprite;
//  sprite.setTexture(*texture);
//   sf::Sound sound;
//   sound.setBuffer(*sound_buff);
//  sound.play();
//  sf::Music music;
//  music.openFromFile(test_music);
//  music.play();
// #else
//   std::cout << "Using SaC2 AssetManager" << std::endl;
//   sac2::SpriteAsset sprite_1;
//   sac2::SpriteAsset sprite_2;
//   sac2::SoundAsset sound_1;
//   sac2::AssetManager::instance().load_sound(SOUND1);  // load
//  sac2::AssetManager::instance().use_sound(NOT_EXIST, sound_1); // failed
//  sac2::AssetManager::instance().use_sound(SOUND1, sound_1);  // load + use
//  sac2::AssetManager::instance().use_texture(IMAGE1, sprite_1);  // load + use
//  sac2::AssetManager::instance().load_texture(IMAGE1);  // load
//  sac2::AssetManager::instance().use_texture(IMAGE1, sprite_1);  // use
//  sac2::AssetManager::instance().unload_texture(IMAGE2);  // already unload
//  sac2::AssetManager::instance().load_texture(IMAGE2);  // load
//  sac2::AssetManager::instance().load_texture(IMAGE2);  // already load
//  sac2::AssetManager::instance().load_texture(NON_USED);  // not found
//  sac2::AssetManager::instance().use_texture(IMAGE1, sprite_2);  // use
//  sac2::AssetManager::instance().use_texture(IMAGE2, sprite_2);  // use
//  sac2::AssetManager::instance().unload_texture(IMAGE2);  // already unload
//  sound_1.loop(true);
//  sound_1.play();
// #endif
// 
// #ifdef RENDER_TRUE
//   sf::RenderWindow window(sf::VideoMode(800, 800), "test 03");
//   while (window.isOpen())
//   {
//     sf::Event event;
//     while (window.pollEvent(event))
//     {
//       if (event.type == sf::Event::Closed)
//         window.close();
//     }
//     window.clear();
// #ifdef USE_SFML_INSTEAD
//     window.draw(sprite);
// #else
//     window.draw(sprite_1.get_asset());
// #endif
//     window.display();
//   }
// #endif
// 
// #ifdef USE_SFML_INSTEAD
// //  delete texture;
//   delete sound_buff;
// #else
//   sac2::AssetManager::destroy();
// #endif
// }

#define ASSET_MANAGER sac2::AssetManager::instance()
#define AUDIO_MANAGER sac2::AudioManager::instance()

using std::cout;
using std::endl;

void test_sound()
{
  cout << "Start TEST 03" << endl;
  ASSET_MANAGER.load_sound(SOUND0);
  ASSET_MANAGER.load_sound(SOUND1);
  ASSET_MANAGER.load_sound(0x00FF);

  AUDIO_MANAGER.play_sound(SOUND1);
}

void test_music()
{
  AUDIO_MANAGER.play_sound(MUSIC1);
}

int main(int argc, char** argv)
{
  test_sound();

  sf::RenderWindow window(sf::VideoMode(300, 300), "TEST 03");
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) { window.close(); }
      window.clear();
      window.display();
    }
  }

  sac2::AssetManager::destroy();
  sac2::AudioManager::destroy();
  return 0;
}
