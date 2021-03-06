////////////////////////////////////////////////////////////////////////////////
/// @file    icelos.hpp
/// @brief   Main include file.
/// @date    2014-05-14
/// @version 0.1 (alpha)
/// @author  Chengwu Huang <chengwhuang@gmail.com>
////////////////////////////////////////////////////////////////////////////////

#ifndef ICELOS_STATUS_HPP
#define ICELOS_STATUS_HPP

#include <icelos_type.hpp>

namespace icelos
{



//! Table of all status code and the corresponding description messages.
typedef std::map<status_t, const std::string> status_map_t;

//! Constant iterator of \b status_map_t
typedef status_map_t::const_iterator status_citer_t;

class Status
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Default constructor
  ////////////////////////////////////////////////////////////////////////////
  Status();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Override constructor
  //! \param[in] status
  //!     Status code
  //! \details
  //!     Initialize with a status code. \b STATUS_SUCCESS is used if NOT
  //!     specified.
  //! \see
  //!     status_t
  ////////////////////////////////////////////////////////////////////////////
  explicit Status(status_t status);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Copy constructor
  //! \param[in] status
  //!     Status object to be copied.
  ////////////////////////////////////////////////////////////////////////////
  Status(const Status& status);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Default destructor
  ////////////////////////////////////////////////////////////////////////////
  ~Status();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Assignment operator
  //! \param[in] status
  //!     Status to be copied.
  //! \return
  //!     Copied status object.
  ////////////////////////////////////////////////////////////////////////////
  Status& operator=(const Status& status);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Return the status code held by the class.
  //! \return
  //!     Status code
  ////////////////////////////////////////////////////////////////////////////
  status_t operator()() const;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Member comparison operator
  //! \param[in] status
  //!     Status to be compared to.
  //! \details
  //!     Test whether the current and the specified status are equal.
  //! \return
  //!     Return \b true whether they are equal, \b false otherwise.
  ////////////////////////////////////////////////////////////////////////////
  bool operator==(const Status& status) const;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Member comparison operator
  //! \param[in] status
  //!     Status to be compared to.
  //! \details
  //!     Test whether the current and the specified status are equal.
  //! \return 
  //!     Return \b true whether they are NOT equal, \b false otherwise.
  ////////////////////////////////////////////////////////////////////////////
  bool operator!=(const Status& status) const;
  const string_t& get_info() const;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Get the message that describes the status code.
  //! \param[in] status_code
  //!     Status code
  //! \return
  //!     Status code description message.
  ////////////////////////////////////////////////////////////////////////////
  static const string_t& status_info(status_t status_code);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Print all status code and the corresponding description.
  ////////////////////////////////////////////////////////////////////////////
  static void print_status_table();

private:
  //! Table of status message.
  static const status_map_t m_status_table;
  //! Hold status code
  status_t                  m_status;
};  // class Status

} // namespace icelos

#endif //! ICELOS_STATUS_HPP

