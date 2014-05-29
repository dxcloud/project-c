#ifndef ICELOS_TEXT_HPP
#define ICELOS_TEXT_HPP

#include <icelos_type.hpp>
#include <icelos_graphics.hpp>

#include <icelos_resource_manager.hpp>

namespace icelos
{

//class Font;
// class Texture;
// class Renderer;
class ResourceManager;

class Text:
  public Graphics
{
public:
  Text();
  ~Text();
  explicit Text(const string_t text);
  void set_font(resource_id_t id);
//  void set_size(size_t size);
  const string_t& get_text() const;
  void set_text(const string_t& text);
protected:
//   void draw(Renderer& renderer) const;
  void update();
  void cleanup();
private:
  TTF_Font* p_sdl_font;
  string_t  m_text;
  color_t   m_color;
};

} // namespace icelos

#endif /// ICELOS_TEXT_HPP

