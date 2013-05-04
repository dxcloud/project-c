#include "sac2_asset_text.hpp"

namespace sac2
{

sac2_status_t AssetText::set_text(const std::string& text)
{
  m_asset.SetText(text);
  return STATUS_SUCCESS;
}

sac2_status_t AssetText::set_font(const sf::Font& font)
{
  m_asset.SetFont(font);
  return STATUS_SUCCESS;
}

}
