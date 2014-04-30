//----------------------------------------------------------------------------
//  Test 02
//----------------------------------------------------------------------------

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//----------------------------------------------------------------------------
//  graphics_module
//----------------------------------------------------------------------------
void graphics_module()
{
  sf::CircleShape cs;
  sf::Color cl;
  sf::ConvexShape xs;
  sf::Font ft;
  sf::Glyph gh;
  sf::Image im;
  sf::Rect<float> rf;
  sf::RectangleShape rs;
  sf::RenderStates ds;
  sf::RenderTexture rt;
  sf::RenderWindow rw;
  sf::Shader sd;
  sf::Sprite sp;
  sf::Text tx;
  sf::Texture tt;
  sf::Transform tf;
  sf::Transformable tb;
  sf::Vertex vx;
  sf::VertexArray va;
  sf::View vw;
}

//----------------------------------------------------------------------------
//  audio_module
//----------------------------------------------------------------------------
void audio_module()
{
  sf::Music mc;
  sf::Sound sd;
  sf::SoundBuffer sb;
  sf::SoundBufferRecorder sr;
}

//----------------------------------------------------------------------------
//  window_module
//----------------------------------------------------------------------------
void window_module()
{
  sf::Context cx;
  sf::ContextSettings cs;
  sf::VideoMode vm;
  sf::Window ww;
}

//----------------------------------------------------------------------------
//  system_module
//----------------------------------------------------------------------------
void system_module()
{
  sf::Clock ck;
  sf::Mutex mx;
  sf::Lock lk(mx);
  sf::String sg;
  sf::Time tm;
}

//----------------------------------------------------------------------------
//  test_02
//----------------------------------------------------------------------------
void test_02()
{
  graphics_module();
  audio_module();
  window_module();
  system_module();
}

//----------------------------------------------------------------------------
//  main
//----------------------------------------------------------------------------
int main()
{
  test_02();
  return 0;
}
