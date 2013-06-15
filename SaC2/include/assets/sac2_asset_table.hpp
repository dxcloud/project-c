/*!
 * \file    sac2_resource.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013 - 04 -20
 * \brief   Allows to access resource by \b Identifier
 */

#ifndef SAC2_ASSET_TABLE_HPP
#define SAC2_ASSET_TABLE_HPP

#include <map>
#include <string>

#include <sac2_type.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

class AssetManager;

enum {
  IMAGE_01 = 0x0001,
  IMAGE_02 = 0x0002
};

//! Constant iterator for \b Res
typedef asset_map_t::iterator resource_iter_t;

/*!
 * \class   AssetTable
 * \brief   Associates a resource name with an \b Identifier
 * \details This class is only used by AssetManager
 */
class AssetTable {
public:
  friend class AssetManager;

private:
  /*!
   * \brief Private default constructor
   */
  AssetTable();

  /*!
   * \brief Private default destructor
   */
  ~AssetTable();

  const std::string& find_asset(asset_id_t id) const;

private:
  /*!
   * \brief Private copy constructor
   */
  AssetTable(const AssetTable&);

  /*!
   * \brief Private assignement operator
   */
  AssetTable& operator=(const AssetTable&);

  /*!
   * \brief Initialize static attribute \b m_textures
   */
  static asset_map_t create_table();

private:
  static const std::string m_res_path;
  static asset_map_t       m_table;  //!< Image type resource name
};  // class AssetTable

//----------------------------------------------------------------------------
//  Ressource::AssetTable
//----------------------------------------------------------------------------
inline AssetTable::AssetTable()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("AssetTable::constructor - successfully created");
#endif
}

//----------------------------------------------------------------------------
//  Ressource::~AssetTable
//----------------------------------------------------------------------------
inline AssetTable::~AssetTable()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("AssetTable::destructor - successfully destroyed");
#endif
}

}  // namespace sac2

#endif  //! SAC2_RESOURCE_HPP
