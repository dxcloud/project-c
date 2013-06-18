#include <SFML/Graphics.hpp>

#include <sac2_asset_manager.hpp>
#include <sac2_asset_sprite.hpp>
#include <sac2_asset_table.hpp>


sac2::asset_map_t sac2::AssetTable::m_table = {};

void render_window(sf::RenderWindow& window, sac2::AssetManager* asset_manager)
{
//  sac2::AssetSprite sprite;
//  if (sac2::STATUS_SUCCESS != asset_manager->get_sprite(sac2::IMAGE_02, sprite)) {
//    return;
// }


sf::Texture texture;
texture.loadFromFile("/home/orange/project-c/SaC2/samples/image/image02.png");
sf::Sprite sprite;
sprite.setTexture(texture);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
//    window.draw(sprite.get_asset());
    window.draw(sprite);
    window.display();
  }
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Test 02");
  sac2::AssetManager* asset_manager(sac2::AssetManager::create());
  render_window(window, asset_manager);
  asset_manager->destroy();
  return sac2::STATUS_SUCCESS;
}
