#include <iostream>

#include <sac2_status.hpp>

namespace sac2
{

//----------------------------------------------------------------------------
//  Status::m_status_table
//----------------------------------------------------------------------------
const status_map_t Status::m_status_table = {
  {STATUS_SUCCESS, "status 0 - STATUS_SUCCESS: No error returned"},
  {STATUS_ERROR,   "status 1 - STATUS_ERROR: Generic error detected"},
  {STATUS_FAIL,    "status 2 - STATUS_FAIL: Loading resource failed"},
  {STATUS_CANCEL,  "status 3 - STATUS_CANCEL: Function NOT executed"},
  {STATUS_BUSY,    "status 4 - STATUS_BUSY: Resource already in use"},
  {STATUS_INVAL,   "status 5 - STATUS_INVAL: Input parameter is NOT valid"},
  {STATUS_ALREADY, "status 6 - STATUS_ALREADY: Resource already set"},
  {STATUS_MISS,    "status 7 - STATUS_MISS: File or Directory NOT found"},
  {STATUS_NOMEM,   "status 8 - STATUS_NOMEM: Not enough memory space"},
  {STATUS_UNKNOWN, "status 9 - STATUS_UNKNOWN: Unknown status code"}
};

//----------------------------------------------------------------------------
//  Status::NUM_STATUS
//----------------------------------------------------------------------------
const unsigned char Status::NUM_STATUS(m_status_table.size());

//----------------------------------------------------------------------------
//  Status::status_cast
//----------------------------------------------------------------------------
status_t Status::status_cast(unsigned int val)
{
  if (NUM_STATUS < val) { return STATUS_UNKNOWN; }
  return static_cast<status_t>(val);
}

//----------------------------------------------------------------------------
//  Status::status_info
//----------------------------------------------------------------------------
const std::string& Status::status_info(status_t status_code)
{
  status_const_iter_t status_iter(m_status_table.find(status_code));
  if (m_status_table.end() == status_iter) {
    status_iter = m_status_table.find(STATUS_UNKNOWN);
  }
  return status_iter->second;
}

//----------------------------------------------------------------------------
//  Status::print_status_table
//----------------------------------------------------------------------------
void Status::print_status_table()
{
  std::cout << "Status table contains "
            << (uint32_t) NUM_STATUS
            << " entries"
            << std::endl;

  for (status_const_iter_t status_iter(m_status_table.begin());
       status_iter != m_status_table.end();
       ++status_iter) {
    std::cout << status_iter->second
              << std::endl;
  }
}

}  // namespace sac2
