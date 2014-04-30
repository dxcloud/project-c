#ifndef SAC2_RENDER_OBJECT_HPP
#define SAC2_RENDER_OBJECT_HPP

namespace sac2
{

class RenderObject
{
public:
  RenderObject() {}
  ~RenderObject() {}
  virtual void draw(const RenderObject* render_object) const = 0;
};

}

#endif  //! SAC2_RENDER_OBJECT_HPP
