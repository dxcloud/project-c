#ifndef _ASSET_MANAGER_HPP_
#define _ASSET_MANAGER_HPP_

/*!
 * \file    sac2_asset_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides AssetManager class
 */

#include "sac2_type.hpp"
#include "sac2_asset.hpp"
#include "sac2_asset_image.hpp"

namespace sac2
{

//! \class AssetManager
/*!
 * \brief   Asset management
 * \warning Make sure the class is instanciated only once
 */
class AssetManager
{
 public:

  AssetManager() {}

  ~AssetManager()
  {
    delete_asset(ASSET_IMAGE);
  }

  /*!
   * \brief  Get the asset specified by \a type and \a id
   * \param  type The type of desired asset
   * \param  id   Identifier of the asset
   * \return Pointer of the asset
   *         Return 0 if the asset is missing
   */
  Asset* get_asset(sac2_asset_type_t type, sac2_asset_id_t id) const;

  /*!
   * \brief  Load the asset specified by \a type
   * \param  type Type of asset to be loaded
   * \return SaC2 status
   */
  sac2_status_t load_asset(sac2_asset_type_t type);

  /*!
   * \brief  Delete the asset specified by \a type
   * \param  type Type of asset to be deleted
   * \return SaC2 status
   */
  sac2_status_t delete_asset(sac2_asset_type_t type);

 protected:

 private:

  /*!
   * \brief Private copy Constructor
   * \details Copy is NOT allowed
   */
  AssetManager(const AssetManager&);

  /*!
   * \brief Private assignment operator
   * \details Copy is NOT allowed
   */
  AssetManager& operator=(const AssetManager&);

  //! Store all Image assets
  std::map<asset_id_t, AssetImage*> m_images;

  //! \TODO Add Map asset for musics, sprites, background...
};  // class AssetManager

}

#endif