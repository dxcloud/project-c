/*!
 * \file sac2_graphic_asset.inl
 */

#ifndef SAC2_GRAPHIC_ASSET_HPP_INCLUDE
#define SAC2_GRAPHIC_ASSET_HPP_INCLUDE

#include <sac2_rendering_manager.hpp>

namespace sac2
{

//----------------------------------------------------------------------------
//  GraphicAsset::constructor
//----------------------------------------------------------------------------
template<class C>
inline GraphicAsset<C>::GraphicAsset():
  Asset<C>()
{

}

//----------------------------------------------------------------------------
//  GraphicAsset::destructor
//----------------------------------------------------------------------------
template<class C>
inline GraphicAsset<C>::~GraphicAsset()
{

}

//----------------------------------------------------------------------------
//  GraphicAsset::get_position
//----------------------------------------------------------------------------
template<class C>
inline point_t GraphicAsset<C>::get_position() const
{
  point_t position(Asset<C>::m_asset.getPosition());
  return position;
}

//----------------------------------------------------------------------------
//  GraphicAsset::get_scale
//----------------------------------------------------------------------------
template<class C>
inline vector_t GraphicAsset<C>::get_scale() const
{
  vector_t factor(Asset<C>::m_asset.getScale());
  return factor;
}

//----------------------------------------------------------------------------
//  GraphicAsset::get_orientation
//----------------------------------------------------------------------------
template<class C>
inline float GraphicAsset<C>::get_orientation() const
{
  return Asset<C>::m_asset.getRotation();
}

//----------------------------------------------------------------------------
//  GraphicAsset::set_position
//----------------------------------------------------------------------------
template<class C>
inline void GraphicAsset<C>::set_position(float x, float y)
{
  Asset<C>::m_asset.setPosition(x, y);
}

//----------------------------------------------------------------------------
//  GraphicAsset::set_position
//----------------------------------------------------------------------------
template<class C>
inline void GraphicAsset<C>::set_position(const point_t& position)
{
  Asset<C>::m_asset.setPosition(position.x, position.y);
}

//----------------------------------------------------------------------------
//  GraphicAsset::set_scale
//----------------------------------------------------------------------------
template<class C>
inline void GraphicAsset<C>::set_scale(float x, float y)
{
//  if ((ZERO < x) && (ZERO < y)) { return STATUS_INVAL; }
  Asset<C>::m_asset.setScale(x, y);
}

//----------------------------------------------------------------------------
//  GraphicAsset::set_scale
//----------------------------------------------------------------------------
template<class C>
inline void GraphicAsset<C>::set_scale(const vector_t& factor)
{
  Asset<C>::m_asset.setScale(factor.x, factor.y);
}

//----------------------------------------------------------------------------
//  GraphicAsset::set_orientation
//----------------------------------------------------------------------------
template<class C>
inline void GraphicAsset<C>::set_orientation(float angdeg)
{
  Asset<C>::m_asset.setRotation(angdeg);
}

//----------------------------------------------------------------------------
//  GraphicAsset::move
//----------------------------------------------------------------------------
template<class C>
inline void GraphicAsset<C>::move(float x, float y)
{
  Asset<C>::m_asset.move(x, y);
}

//----------------------------------------------------------------------------
//  GraphicAsset::move
//----------------------------------------------------------------------------
template<class C>
inline void GraphicAsset<C>::move(const vector_t& offset)
{
  Asset<C>::m_asset.move(offset.x, offset.y);
}

//----------------------------------------------------------------------------
//  GraphicAsset::rotate
//----------------------------------------------------------------------------
template<class C>
inline void GraphicAsset<C>::rotate(float angdeg)
{
  Asset<C>::m_asset.rotate(angdeg);
}

template<class C>
inline void GraphicAsset<C>::draw()
{
  RenderingManager::instance().add_drawable(&(Asset<C>::m_asset));
}

}

#endif  //! SAC2_GRAPHIC_ASSET_HPP_INCLUDE
