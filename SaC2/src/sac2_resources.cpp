#include "sac2_resources.hpp"

namespace sac2 {

sac2_asset_map_t create_image()
{
  sac2_asset_map_t map_image;
  map_image.insert(std::make_pair("IM01", "/home/orange/project-c/SaC2/samples/image01.png"));
  map_image.insert(std::make_pair("IM02", "/home/orange/project-c/SaC2/samples/image02.png"));
  map_image.insert(std::make_pair("IM03", "/home/orange/project-c/SaC2/samples/image03.png"));
  map_image.insert(std::make_pair("IM04", "/home/orange/project-c/SaC2/samples/image04.png"));
  map_image.insert(std::make_pair("IM05", "/home/orange/project-c/SaC2/samples/image05.png"));
  return map_image;
}

const sac2_asset_map_t Res::image = create_image();

}
