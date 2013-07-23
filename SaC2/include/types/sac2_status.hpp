//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_status.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     1.0
//! \date
//!     2013-07-23
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_STATUS_HPP
#define SAC2_STATUS_HPP

#include <iostream>
#include <string>
#include <map>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
//! \enum
//!     status_t
//! \brief
//!     Status code value.
//! \details
//!     This list describes all available status codes.
//!     The class \b Status is able to give status information.
//! \see
//!     Status
//////////////////////////////////////////////////////////////////////////////
enum status_t {
  STATUS_SUCCESS,  //!< General success response
  STATUS_ERROR,    //!< Generic condition: backwards compatible
  STATUS_FAIL,     //!< Initialization failed
  STATUS_CANCEL,   //!< Operation cancelled by a call
  STATUS_BUSY,     //!< Callee function no responding
  STATUS_INVAL,    //!< An invalid parameter was passed
  STATUS_ALREADY,  //!< Parameter is already used/deleted
  STATUS_MISS,     //!< A file is missing
  STATUS_NOMEM,    //!< Memory requirred not available
  STATUS_UNKNOWN   //!< Unknown status
};

//! Table of all status code and the corresponding description messages.
typedef std::map<status_t, const std::string> status_map_t;

//! Constant iterator of \b status_map_t
typedef status_map_t::const_iterator status_const_iter_t;

//////////////////////////////////////////////////////////////////////////////
//! \class
//!     Status
//! \brief
//!     Give information about Status code.
//! \details
//!     This class provides methods for comparing different status codes,
//!     it is also possible to get all available status and their
//!     signification by using static methods.
//! \see
//!     status_t
//////////////////////////////////////////////////////////////////////////////
class Status
{
public:
  //! Number of available status
  static const uint8_t NUM_STATUS;

public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Default constructor
  ////////////////////////////////////////////////////////////////////////////
  Status();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Override constructor
  //! \param[in] status_code
  //!     Status code
  //! \details
  //!     Initialize with a status code. \b STATUS_SUCCESS is used if NOT
  //!     specified.
  //! \see
  //!     status_t
  ////////////////////////////////////////////////////////////////////////////
  explicit Status(status_t status_code=STATUS_SUCCESS);

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

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Get the message that describes the status code.
  //! \param[in] status_code
  //!     Status code
  //! \return
  //!     Status code description message.
  ////////////////////////////////////////////////////////////////////////////
  static const std::string& status_info(status_t status_code);

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

}  // namespace sac2

#include <sac2_status.inl>

#endif  //! SAC2_STATUS_TYPE_HPP
