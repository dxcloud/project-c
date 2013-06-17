/*!
 * \file sac2_version.hpp
 * \date 2013-06-22
 */

#ifndef SAC2_VERIONS_HPP
#define SAC2_VERSION_HPP

#include <string>
#include <sstream>

namespace sac2
{

/*!
 * \enum  version_field_t
 * \brief Represents the format of a version number.
 *        Used to access the corresponding field of the version number.
 */
typedef enum version_field_t{
  MAJOR,    //!< Major value field
  MINOR,    //!< Minor value field
  BUILD,    //!< Build value field
  REVISION  //!< Revision value field
} version_field_t;

/**!
 * \class   Version
 * \brief   Represents the version number of an under development project.
 * \details It allows to control the version of a project by comparing with
 *          another one.  
 *          The format of the version number is:
 *          \b major.minor[.build[.revision]]. All these four numbers are
 *          8-bit, therefore they must be between \b 0 and \b 255.
 * \note    The following principle could be adopted for versioning:
 *          - \b MAJOR: significant changes in functionality, where backward
 *                      compatibility cannot be assumed.
 *          - \b MINOR: new features or fixes have been added.
 *          - \b BUILD: changes of the platform, compiler.
 *          - \b REVISION a higher number might be used when minor bugs are
 *                        fixed.
 * \see     version_field_t
 */
class Version
{
public:
  /*!
   * \brief   Default constructor
   * \details Initialize an instance where each field equals 0.
   */
  Version();

  /*!
   * \brief   Override constructor
   * \param   major Major value
   * \param   minor Minor value
   * \details Initialize an instance with the specified \b MAJOR and
   *          \b MINOR values
   */
  Version(uint8_t major, uint8_t minor);

  /*!
   * \brief   Override constructor
   * \param   major Major value
   * \param   minor Minor value
   * \param   build Build value
   * \details Initialize an instance with the specified \b MAJOR, \b MINOR
   *          and \b BUILD values.
   */
  Version(uint8_t major, uint8_t minor, uint8_t build);

  /*!
   * \brief   Override constructor
   * \param   major    Major value
   * \param   minor    Minor value
   * \param   build    Build value
   * \param   revision Revision value
   * \details Initialize an instance with the specified \b MAJOR, \b MINOR,
   *          \b BUILD and \b REVISION values
   */
  Version(uint8_t major, uint8_t minor, uint8_t build, uint8_t revision);

  /*!
   * \brief   Copy constructor
   * \param   version Version to be copied.
   */
  Version(const Version& version);

  /*!
   * \brief   Default destructor
   */
  ~Version();

  /*!
   * \brief   Assignment operator
   * \param   version Version to be copied.
   */
  Version& operator=(const Version& version);

  /*!
   * \brief   Return the version as a single 32-bit number:
   *          - bits [31..24]: major value
   *          - bits [23..16]: minor value
   *          - bits [15..8]: build value
   *          - bits [7..0]: revision value
   * \return  32-bit number representing the version.
   */
  uint32_t operator()() const;

  /*!
   * \brief   Get a specified version field value.
   * \param   field Specifies the field to be returned.
   * \return  The value of the version field specified by \b field.
   * \see     version_field_t
   */
  uint8_t operator()(version_field_t field) const;

  /*!
   * \brief   Modify a specified version field value.
   * \param   field Specifies the field to be modified.
   * \return  The modified value of the version field specified by \b field.
   * \see     version_field_t
   */
  uint8_t& operator()(version_field_t field);

  /*!
   * \brief   Member comparison operator
   * \param   version Version to be compared to.
   * \details Test whether the current and the specified version are equal.
   * \return  Return \b true whether they are equal, \b false otherwise.
   */
  bool operator==(const Version& version) const;

  /*!
   * \brief   Member comparison operator
   * \param   version Version to be compared to.
   * \details Test whether the current and the specified version are NOT
   *          equal.
   * \return  Return \b true whether they are NOT equal, \b false otherwise.
   */
  bool operator!=(const Version& version) const;

  /*!
   * \brief   Member comparison operator
   * \param   version Version to be compared to.
   * \details Test whether the current version is less than the specified
   *          version.
   * \return  Return \b true whether the current version is less than the
   *          specified version, \b false otherwise.
   */
  bool operator<(const Version& version) const;

  /*!
   * \brief   Member comparison operator
   * \param   version Version to be compared to.
   * \details Test whether the current version is less or equal than
   *          the specified version.
   * \return  Return \b true whether the current version is less or equal
   *          than the specified version, \b false otherwise.
   */
  bool operator<=(const Version& version) const;

  /*!
   * \brief   Member comparison operator
   * \param   version Version to be compared to.
   * \details Test whether the current version is greater than the specified
   *          version.
   * \return  Return \b true whether the current version is greater than the
   *          specified version, \b false otherwise.
   */
  bool operator>(const Version& version) const;

  /*!
   * \brief   Member comparison operator
   * \param   version Version to be compared to.
   * \details Test whether the current version is greater or equal than
   *          the specified version.
   * \return  Return \b true whether the current version is greater or equal
   *          than the specified version, \b false otherwise.
   */
  bool operator>=(const Version& version) const;

  /*!
   * \brief   Return the version number as a string:
   *          \b MAJOR.MINOR.BUILD.REVISION
   * \return  String format of the version
   */
  std::string info() const;

private:
  uint8_t m_major;     //!< Major value
  uint8_t m_minor;     //!< Minor value
  uint8_t m_build;     //!< Build value
  uint8_t m_revision;  //!< Revision value
};


}

#include <sac2_version.inl>

#endif
