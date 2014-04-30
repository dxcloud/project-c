#include <sac2.hpp>

using namespace sac2;

const AssetManager::asset_map_t AssetManager::m_asset_table = { };

int main(int argc, char* argv[])
{
  sac2::Logger::create();
  sac2::Engine app;
  app.parse_options(argc, argv);
  app.run();

  return 0;
}
