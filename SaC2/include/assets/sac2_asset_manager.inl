//////////////////////////////////////////////////////////////////////////////
//! \file sac2_asset_manager.inl
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (development version)
//! \date
//!     2013-06-30
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_ASSET_MANAGER_HPP_INCLUDE
#define SAC2_ASSET_MANAGER_HPP_INCLUDE

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
// AssetManager::use_asset
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
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AssetManager::load_asset
//////////////////////////////////////////////////////////////////////////////
template<typename M, typename R>
inline status_t AssetManager::load_asset(asset_id_t id, M& asset_map)
{
  if (asset_map.end() != asset_map.find(id)) { return STATUS_ALREADY; }
  if (m_asset_table.end() == m_asset_table.find(id)) {
    LOG_DEBUG("AssetManager::load_asset - ID no recognized")
    return STATUS_MISS;
  }  // ID not found
  R* asset(new R);
  if (false == asset->loadFromFile(m_asset_table.at(id))) {
    delete asset;
    LOG_DEBUG("AssetManager::load_asset - cannot load asset >>")
    LOG_DEBUG(m_asset_table.at(id))
    return STATUS_FAIL;
  }  // error from SFML
  asset_map.insert(std::make_pair(id, asset));
  LOG_DEBUG("AssetManager::load_asset - asset loaded >>")
  LOG_DEBUG(m_asset_table.at(id))
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AssetManager::unload_asset
//////////////////////////////////////////////////////////////////////////////
template<typename M>
inline status_t AssetManager::unload_asset(asset_id_t id, M& asset_map)
{
  typename M::iterator asset_iter(asset_map.find(id));
  if (asset_map.end() == asset_iter) { return STATUS_CANCEL; }
  delete asset_iter->second;
  asset_iter->second = 0;
  asset_map.erase(asset_iter);
  LOG_DEBUG("AssetManager::unload_asset - asset unloaded >>")
  LOG_DEBUG(m_asset_table.at(id))
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// AssetManager::remove_asset
//////////////////////////////////////////////////////////////////////////////
template<class M>
inline void AssetManager::remove_asset(M& asset_map)
{
  for (typename M::iterator asset_iter(asset_map.begin());
       asset_iter != asset_map.end();
       ++asset_iter) {
    delete asset_iter->second;
    asset_iter->second = 0;
    LOG_DEBUG("AssetManager::remove_asset - asset removed >>")
    LOG_DEBUG(m_asset_table.at(asset_iter->first))
  }
  asset_map.clear();
}

}  // namespace sac2

#endif  //! SAC2_ASSET_MANAGER_HPP_INCLUDE
