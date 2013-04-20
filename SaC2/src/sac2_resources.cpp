#include "sac2_resources.hpp"

namespace sac2 {

sac2_asset_map_t create_image()
{
  sac2_asset_map_t map_image;
  map_image.insert(std::make_pair("IM01", "/home/orange/project-c/SaC2/samples/image01.png"));
  return map_image;
}

const sac2_asset_map_t Res::image = create_image();

}
