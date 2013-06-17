/*!
 * \file sac2_status.inl
 */

#ifndef SAC2_STATUS_INL
#define SAC2_STATUS_INL

namespace sac2{

//----------------------------------------------------------------------------
//  Status::Status
//----------------------------------------------------------------------------
inline Status::Status():
  m_status(STATUS_SUCCESS)
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Status::Status
//----------------------------------------------------------------------------
inline Status::Status(status_t status_code):
  m_status(status_code)
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Status::Status
//----------------------------------------------------------------------------
inline Status::Status(unsigned int val):
  m_status(status_cast(val))
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Status::Status
//----------------------------------------------------------------------------
inline Status::Status(const Status& status):
  m_status(status.m_status)
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Status::~Status
//----------------------------------------------------------------------------
inline Status::~Status()
{
  // do nothing
}

//----------------------------------------------------------------------------
//  Status::operator=
//----------------------------------------------------------------------------
inline Status& Status::operator=(const Status& status)
{
  this->m_status = status.m_status;
  return (*this);
}

//----------------------------------------------------------------------------
//  Status::operator=
//----------------------------------------------------------------------------
inline Status& Status::operator=(uint8_t val)
{
  m_status = status_cast(val);
  return (*this);
}

//----------------------------------------------------------------------------
//  Status::operator()
//----------------------------------------------------------------------------
inline status_t Status::operator()() const
{
  return m_status;
}

//----------------------------------------------------------------------------
//  Status::operator==
//----------------------------------------------------------------------------
inline bool Status::operator==(const Status& status) const
{
  return (status.m_status == this->m_status);
}

//----------------------------------------------------------------------------
//  Status::operator!=
//----------------------------------------------------------------------------
inline bool Status::operator!=(const Status& status) const
{
  return (status.m_status != this->m_status);
}

}  // namespace sac2

#endif  // SAC2_STATUS_INL
