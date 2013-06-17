/*!
 * \file sac2_version.inl
 * \date 2013-06-22
 */

#ifndef SAC2_VERSION_INL
#define SAC2_VERSION_INL

namespace sac2
{

//----------------------------------------------------------------------------
//  Version::Version
//----------------------------------------------------------------------------
inline Version::Version():
  m_major(0),
  m_minor(0),
  m_build(0),
  m_revision(0)
{
}

//----------------------------------------------------------------------------
//  Version::Version
//----------------------------------------------------------------------------
inline Version::Version(uint8_t major, uint8_t minor):
  m_major(major),
  m_minor(minor),
  m_build(0),
  m_revision(0)
{
}

//----------------------------------------------------------------------------
//  Version::Version
//----------------------------------------------------------------------------
inline Version::Version(uint8_t major, uint8_t minor, uint8_t build):
  m_major(major),
  m_minor(minor),
  m_build(build),
  m_revision(0)
{
}

//----------------------------------------------------------------------------
//  Version::Version
//----------------------------------------------------------------------------
inline Version::Version(uint8_t major,
                        uint8_t minor,
                        uint8_t build,
                        uint8_t revision):
  m_major(major),
  m_minor(minor),
  m_build(build),
  m_revision(revision)
{
}

//----------------------------------------------------------------------------
//  Version::Version
//----------------------------------------------------------------------------
inline Version::Version(const Version& version)
{
  m_major = version.m_major;
  m_minor = version.m_minor;
  m_build = version.m_build;
  m_revision = version.m_revision;
}

//----------------------------------------------------------------------------
//  Version::~Version
//----------------------------------------------------------------------------
inline Version::~Version()
{
}

//----------------------------------------------------------------------------
//  Version::operator=
//----------------------------------------------------------------------------
inline Version& Version::operator=(const Version& version)
{
  this->m_major = version.m_major;
  this->m_minor = version.m_minor;
  this->m_build = version.m_build;
  this->m_revision = version.m_revision;
  return (*this);
}

//----------------------------------------------------------------------------
//  Version::operator()
//----------------------------------------------------------------------------
inline uint32_t Version::operator()() const
{
  return ((m_major << 24) | (m_minor << 16) | (m_build << 8) | m_revision);
}

//----------------------------------------------------------------------------
//  Version::operator()
//----------------------------------------------------------------------------
inline uint8_t Version::operator()(version_field_t field) const
{
  switch (field) {
    case MAJOR:
      return m_major;
    case MINOR:
      return m_minor;
    case BUILD:
      return m_build;
    case REVISION:
      return m_revision;
    default:
      return 0;
  }
}

//----------------------------------------------------------------------------
//  Version::operator()
//----------------------------------------------------------------------------
inline uint8_t& Version::operator()(version_field_t field)
{
  switch (field) {
    case MAJOR:
      return m_major;
    case MINOR:
      return m_minor;
    case BUILD:
      return m_build;
    default:
      return m_revision;
  }
}

//----------------------------------------------------------------------------
//  Version::operator==
//----------------------------------------------------------------------------
inline bool Version::operator==(const Version& version) const
{
  if ((version.m_major == m_major)
       && (version.m_minor == m_minor)
       && (version.m_build == m_build)
       && (version.m_revision == m_revision)) {
    return true;
  }
  return false;
}

//----------------------------------------------------------------------------
//  Version::operator!=
//----------------------------------------------------------------------------
inline bool Version::operator!=(const Version& version) const
{
  return !(operator==(version));
}

//----------------------------------------------------------------------------
//  Version::operator<
//----------------------------------------------------------------------------
inline bool Version::operator<(const Version& version) const
{
  if (version.m_major > m_major) { return true; }
  if (version.m_minor > m_minor) { return true; }
  if (version.m_build > m_build) { return true; }
  if (version.m_revision > m_revision ) { return true; }
  return false;
}

//----------------------------------------------------------------------------
//  Version::operator<=
//----------------------------------------------------------------------------
inline bool Version::operator<=(const Version& version) const
{
  return !(operator>(version));
}

//----------------------------------------------------------------------------
//  Version::operator>
//----------------------------------------------------------------------------
inline bool Version::operator>(const Version& version) const
{
  if (version.m_major < m_major) { return true; }
  if (version.m_minor < m_minor) { return true; }
  if (version.m_build < m_build) { return true; }
  if (version.m_revision < m_revision ) { return true; }
  return false;
}

//----------------------------------------------------------------------------
//  Version::operator>=
//----------------------------------------------------------------------------
inline bool Version::operator>=(const Version& version) const
{
  return !(operator<(version));
}

//----------------------------------------------------------------------------
//  Version::info
//----------------------------------------------------------------------------
inline std::string Version::info() const
{
  std::stringstream s;
  s << (uint32_t) m_major
    << "."
    << (uint32_t) m_minor
    << "."
    << (uint32_t) m_build
    << "."
    << (uint32_t) m_revision;
  return s.str();
}

}

#endif
