/*!
 * \file sac2_asset_manager.inl
 */

#ifndef SAC2_ASSET_MANAGER_INL
#define SAC2_ASSET_MANAGER_INL

namespace sac2
{

template<typename M, typename I, typename R, typename A>
status_t AssetManager::get_asset(asset_id_t id, A& asset, M& asset_map)
{
  I asset_iter(asset_map.find(id));
  if (asset_map.end() == asset_iter) {
    if (STATUS_SUCCESS != load_asset<M, R>(id, asset_map)) {
      return STATUS_ERROR;
    }
  }
  asset.load(*(asset_map[id]));
  return STATUS_SUCCESS;
}

template<typename M, typename R>
inline status_t AssetManager::load_asset(asset_id_t id, M& asset_map)
{
  if (asset_map.end() != asset_map.find(id)) { return STATUS_ALREADY; }
  asset_const_iter_t res_iter(m_asset_table.find(id));
  if (m_asset_table.end() == res_iter) { return STATUS_MISS; }
  R* asset(new R);
  if (false == asset->loadFromFile(res_iter->second)) {
    delete asset;
    return STATUS_FAIL;
  }
  asset_map.insert(std::make_pair(id, asset));
  return STATUS_SUCCESS;
}

template<typename M, typename I>
status_t AssetManager::unload_asset(asset_id_t id, M& asset_map)
{
  I asset_iter(asset_map.find(id));
  if (asset_map.end() == asset_iter) { return STATUS_CANCEL; }
  delete asset_iter->second;
  asset_iter->second = 0;
  asset_map.erase(asset_iter);
  return STATUS_SUCCESS;
}

}

#endif
