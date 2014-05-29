#include <icelos_status.hpp>

namespace icelos
{

//////////////////////////////////////////////////////////////////////////////
// Status::m_status_table
//////////////////////////////////////////////////////////////////////////////
const status_map_t Status::m_status_table = {
  {STATUS_SUCCESS, "Status 0 - STATUS_SUCCESS: No error returned"},
  {STATUS_ERROR,   "Status 1 - STATUS_ERROR: Generic error detected"},
  {STATUS_FAIL,    "Status 2 - STATUS_FAIL: Loading resource failed"},
  {STATUS_CANCEL,  "Status 3 - STATUS_CANCEL: Function NOT executed"},
  {STATUS_BUSY,    "Status 4 - STATUS_BUSY: Resource already in use"},
  {STATUS_INVAL,   "Status 5 - STATUS_INVAL: Input parameter is NOT valid"},
  {STATUS_ALREADY, "Status 6 - STATUS_ALREADY: Resource already set"},
  {STATUS_MISS,    "Status 7 - STATUS_MISS: File or Directory NOT found"},
  {STATUS_NOMEM,   "Status 8 - STATUS_NOMEM: Not enough memory space"},
  {STATUS_UNKNOWN, "Status 9 - STATUS_UNKNOWN: Unknown status code"}
};

Status::Status():
  m_status(STATUS_SUCCESS)
{
  // nothing to do
}


//////////////////////////////////////////////////////////////////////////////
// Status::Status
//////////////////////////////////////////////////////////////////////////////
Status::Status(status_t status_code):
  m_status(status_code)
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
// Status::Status
//////////////////////////////////////////////////////////////////////////////
Status::Status(const Status& status):
  m_status(status.m_status)
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
// Status::~Status
//////////////////////////////////////////////////////////////////////////////
Status::~Status()
{
  // do nothing
}

//////////////////////////////////////////////////////////////////////////////
// Status::operator=
//////////////////////////////////////////////////////////////////////////////
Status& Status::operator=(const Status& status)
{
  this->m_status = status.m_status;
  return (*this);
}

//////////////////////////////////////////////////////////////////////////////
// Status::operator()
//////////////////////////////////////////////////////////////////////////////
status_t Status::operator()() const
{
  return m_status;
}

//////////////////////////////////////////////////////////////////////////////
// Status::operator==
//////////////////////////////////////////////////////////////////////////////
bool Status::operator==(const Status& status) const
{
  return (status.m_status == this->m_status);
}

//////////////////////////////////////////////////////////////////////////////
// Status::operator!=
//////////////////////////////////////////////////////////////////////////////
bool Status::operator!=(const Status& status) const
{
  return (status.m_status != this->m_status);
}

const string_t& Status::get_info() const
{
  return status_info(m_status);
}

//////////////////////////////////////////////////////////////////////////////
// Status::status_info
//////////////////////////////////////////////////////////////////////////////
const std::string& Status::status_info(status_t status_code)
{
  status_citer_t status_iter(m_status_table.find(status_code));
  if (m_status_table.end() == status_iter) {
    status_iter = m_status_table.find(STATUS_UNKNOWN);
  }
  return status_iter->second;
}

//////////////////////////////////////////////////////////////////////////////
// Status::print_status_table
//////////////////////////////////////////////////////////////////////////////
void Status::print_status_table()
{
  std::cout << "Status table contains "
            << (uint32_t) NUM_STATUS
            << " entries :"
            << std::endl;

  for (status_citer_t status_iter(m_status_table.begin());
       status_iter != m_status_table.end();
       ++status_iter) {
    std::cout << status_iter->second
              << std::endl;
  }
}

}  // namespace icelos

