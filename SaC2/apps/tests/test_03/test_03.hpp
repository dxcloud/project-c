#ifndef TEST_03_HPP
#define TEST_03_HPP

#include <sac2_sprite_asset.hpp>
#include <sac2_sound_asset.hpp>
#include <sac2_asset_manager.hpp>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

enum test_error_t
{
  STATUS_SUCCESS,
  STATUS_ALREADY,
  STATUS_MISS,
  STATUS_FAIL
};

const std::string test_image_1 = "/home/orange/project-c/SaC2/samples/image/image02.png";
const std::string test_image_2 = "/home/orange/project-c/SaC2/samples/image/image03.png";
const std::string test_sound_1 = "/home/orange/project-c/SaC2/samples/sound/sound01.ogg";
// 'sound.ogg' not exist
const std::string test_sound_2 = "/home/orange/project-c/SaC2/samples/sound/sound.ogg";
const std::string test_music = "/home/orange/project-c/SaC2/samples/music/J-E-N-O-V-A.ogg";

const sac2::asset_id_t IMAGE1 = 0x0064U;
const sac2::asset_id_t IMAGE2 = 0x0065U;
const sac2::asset_id_t SOUND1 = 0x0F01U;
const sac2::asset_id_t NON_USED = 0xFFFFU;
const sac2::asset_id_t NOT_EXIST = 0xFF00U;

const sac2::AssetManager::asset_map_t sac2::AssetManager::m_asset_table =
{
  {IMAGE1, test_image_1},
  {IMAGE2, test_image_2},
  {SOUND1, test_sound_1},
  {NOT_EXIST, test_sound_2}
};

const std::map<int, const std::string> test_asset_table =
{
  {1, test_sound_1}
};

std::map<int, sf::SoundBuffer*> snd_map;

template<typename M, typename R>
inline test_error_t load_asset(int id, M& asset_map)
{
  if (asset_map.end() != asset_map.find(id)) {
    return STATUS_ALREADY;
  }  // if asset_map contains `id'
  if (test_asset_table.end() == test_asset_table.find(id)) {
    return STATUS_MISS;
  }  // m_asset_table does NOT contain `id'
  R* asset(new R);
  if (false == asset->loadFromFile(test_asset_table.at(id))) {
    delete asset;
    return STATUS_FAIL;
  }  // error from SFML
  asset_map.insert(std::make_pair(id, asset));
  return STATUS_SUCCESS;
}

test_error_t load_sound(int id);


#endif
