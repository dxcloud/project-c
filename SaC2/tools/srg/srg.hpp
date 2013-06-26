/*!
 * \file    srg.hpp
 * \author  Chengwu Huang
 * \version 1.0
 * \date    2013-06-18
 * \brief
 */

#ifndef SAC2_RESOURCE_GENERATOR_HPP
#define SAC2_RESOURCE_GENERATOR_HPP

#include <string>
#include <fstream>
#include <map>

#include <rapidxml.hpp>

namespace sac2
{

namespace srg
{

typedef rapidxml::xml_node<>* xml_node_ptr;
typedef rapidxml::xml_attribute<>* xml_attribute_ptr;
typedef std::map<std::string, std::string> filename_map_t;
typedef filename_map_t::iterator filename_iter_t;
typedef filename_map_t::const_iterator filename_const_iter_t;

enum {
  MAX_CHAR_LENGTH = 10  //!< Maximum length of string for comparison
};

/*!
 * \class Srg
 * \brief SaC2 Resource Generator class
 */
class Srg
{
public:
  /*!
   * \brief Constructor
   * \param xml_filename Input xml filename
   */
  explicit Srg(const std::string& xml_filename);

  /*!
   * \brief Default destructor
   */
  ~Srg();

  /*!
   * \brief Print usage message.
   */
  static void print_usage();

  /*!
   * \brief Use RapidXML to parse xml file.
   */
  void parse_xml();

  /*!
   * \brief Generate the header and source file.
   */
  void generate() const;

private:
  /*!
   * \brief  Compare node names.
   * \param  name1 User node name
   * \param  name2 Valid node name
   * \return Return \b true if user node name is a valid name.
   */
  bool is_srg_node(const char* name1, const char* name2) const;

  /*!
   * \brief  Test if the node is a `resource' node.
   * \param  node_name Name of the node to be tested
   * \return Return \b true if the node is `resource'.
   */
  bool is_resource_node(const char* node_name) const;

  /*!
   * \brief  Test if the node is a asset type node.
   * \param  node_name Name of the node to be tested
   * \return Return \b true if the node is either
   *         `font', `image', `music' or `sound'.
   */
  bool is_asset_type_node(const char* node_name) const;

  /*!
   * \brief  Test if the node is a `item' node.
   * \param  node_name Name of the node to be tested
   * \return Return \b true if the node is `item'
   */
  bool is_item_node(const char* node_name) const;

  /*!
   * \brief  Compare attributes.
   * \param  name1 User attribute name
   * \param  name2 Valid attribute name
   * \return Return \b true if user attribute name is a valid name.
   */
  bool is_srg_attribute(const char* name1, const char* name2) const;

  /*!
   * \brief  Test if the attribute is `dir' attribute.
   * \param  attribute_name Name of the attribute to be tested
   * \return Return \b true if the attribute is `dir'.
   */
  bool is_dir_attribute(const char* attribute_name) const;

  /*!
   * \brief  Test if the node has children.
   * \param  parent The parent node
   * \return Return \b true if the node has children, \b false otherwise.
   */
  bool has_child(xml_node_ptr parent) const;

  /*!
   * \brief  Test whether the node has attributes.
   * \param  node Node to be tested
   * \return Return \b true if the node has attributes.
   */
  bool has_attribute(xml_node_ptr node) const;

  /*!
   * \brief  Test whether the node has `id' attribute.
   * \param  node Node to be tested
   * \return Return \b true if the node has `id' attribute.
   */
  bool has_id_attribute(xml_node_ptr node) const;

  /*!
   * \brief  Test whether the node has `filename' attribute.
   * \param  node Node to be tested
   * \return Return \b true if the node has `id' attribute.
   */
  bool has_filename_attribute(xml_node_ptr node) const;

  /*!
   * \brief  Modify the filename path whether `dir' attribute is found.
   * \param  node Node to be checked
   * \param  all_path if \b true, add the value of `dir' to all children.
   */
  void check_dir_attribute(xml_node_ptr node, bool all_path=false);

  /*!
   * \brief  Insert the value of `id' and `filename' into the filename map.
   * \param  node Node to be checked
   */
  void check_id_and_filename_attribute(xml_node_ptr node);

  /*!
   * \brief  Generate header file
   */
  void generate_header() const;

  /*!
   * \brief  Generate source file
   */
  void generate_source() const;

  /*!
   * \brief  Insert file header including warning
   * \param  ofs Output file stream
   */
  void insert_file_header(std::ofstream& ofs) const;

private:
  static const char* ATTRIBUTE_DIR;
  static const char* ATTRIBUTE_ID;
  static const char* ATTRIBUTE_FILENAME;
  static const char* NODE_RESOURCE;
  static const char* NODE_FONT;
  static const char* NODE_IMAGE;
  static const char* NODE_MUSIC;
  static const char* NODE_SOUND;
  static const char* NODE_ITEM;

  //! Default output filename without extension
  static const std::string RESOURCE_FILENAME;

  std::string m_xml_filename;  //!< Input XML filename
  std::string m_res_filename;  //!< Ouput filename without extension
  filename_map_t m_res_path;
  filename_map_t m_filenames;
};  // class Srg

}  // namespace srg

}  // namespace sac2

#endif  //! SAC2_RESOURCE_GENERATOR_HPP

