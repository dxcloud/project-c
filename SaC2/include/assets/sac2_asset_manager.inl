//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_asset_manager.inl
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (development version)
//! \date
//!     2013-06-30
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_ASSET_MANAGER_HPP_INCLUDE
#define SAC2_ASSET_MANAGER_HPP_INCLUDE

#include <stdio.h>
#include <iostream>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
//  AssetManager::use_asset
//////////////////////////////////////////////////////////////////////////////
template<typename M, typename R, typename A>
inline status_t AssetManager::use_asset(asset_id_t id, A& asset, M& asset_map)
{
  typename M::iterator asset_iter(asset_map.find(id));
  if (asset_map.end() == asset_iter) {
    if (STATUS_SUCCESS != load_asset<M, R>(id, asset_map)) {
      return STATUS_ERROR;
    }
  }
  asset.load(*(asset_map[id]));
//  Logger::log_debug("AssetManager::use_asset - use " + (int)id);
  printf("--use %d\n", id);
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
//  AssetManager::load_asset
//////////////////////////////////////////////////////////////////////////////
template<typename M, typename R>
inline status_t AssetManager::load_asset(asset_id_t id, M& asset_map)
{
  // FIXME follwing test leads Valgrind errors:
  // Conditional jump or move depends on uninitialized value(s)
  if (asset_map.end() != asset_map.find(id)) {
    return STATUS_ALREADY;
  }  // if asset_map contains `id'
  if (m_asset_table.end() == m_asset_table.find(id)) {
    return STATUS_MISS;
  }  // m_asset_table does NOT contain `id'
  R* asset(new R);
  if (false == asset->loadFromFile(m_asset_table.at(id))) {
    delete asset;
    return STATUS_FAIL;
  }  // error from SFML
  asset_map.insert(std::make_pair(id, asset));
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
//  AssetManager::unload_asset
//////////////////////////////////////////////////////////////////////////////
template<typename M>
inline status_t AssetManager::unload_asset(asset_id_t id, M& asset_map)
{
  typename M::iterator asset_iter(asset_map.find(id));
  if (asset_map.end() == asset_iter) {
//    Logger::log_debug("AssetManager::unload_asset - already unload " + (int) id);
    printf("--already unload %d\n", id);
    return STATUS_CANCEL;
  }
  delete asset_iter->second;
  asset_iter->second = 0;
  asset_map.erase(asset_iter);
//  Logger::log_debug("AssetManager::unload_asset - success unload " + (int) id);
  printf("--success unload %d\n", id);
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
//  AssetManager::remove_asset
//////////////////////////////////////////////////////////////////////////////
template<class M>
inline void AssetManager::remove_asset(M& asset_map)
{
  for (typename M::iterator asset_iter(asset_map.begin());
       asset_iter != asset_map.end();
       ++asset_iter) {
    delete asset_iter->second;
    asset_iter->second = 0;
//    Logger::log_debug("AssetManager::remove_asset - remove " + (int) asset_iter->first);
    printf("--remove %d\n", asset_iter->first);
  }
  asset_map.clear();
}

}  // namespace sac2

#endif  //! SAC2_ASSET_MANAGER_HPP_INCLUDE
