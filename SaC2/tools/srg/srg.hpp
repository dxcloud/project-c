#ifndef SAC2_RESOURCE_GENERATOR_HPP
#define SAC2_RESOURCE_GENERATOR_HPP

#include <string>
#include <map>

#include <rapidxml.hpp>

#  ifndef RESOURCE_FILENAME
#  define RESOURCE_FILENAME "resource"
#  endif

namespace srg
{

typedef rapidxml::xml_node<>* xml_node_ptr;
typedef rapidxml::xml_attribute<>* xml_attribute_ptr;
typedef std::map<std::string, std::string>::const_iterator filename_it_t;

typedef enum resource_type_t {
  IMAGE_RESOURCE,
  SOUND_RESOURCE
} resource_type_t;

/*!
 * \class Srg
 * \brief SaC2 Resource Generator class
 */
class Srg
{
public:
  /*!
   * \brief Default constructor
   * \param xml_filename Input xml filename
   */
  explicit Srg(const std::string& xml_filename);

  /*!
   * \brief Default destructor
   */
  ~Srg();

  /*!
   * \brief
   */
  void parse_xml();

  void generate() const;

private:
  bool is_srg_node(const char* name1, const char* name2) const;
  bool is_resource_node(const char* node_name) const;

  bool is_srg_attribute(const char* name1, const char* name2) const;
  bool is_dir_attribute(const char* attribute_name) const;

  bool has_child(xml_node_ptr parent) const;
  bool has_attribute(xml_node_ptr node) const;

  bool has_id_attribute(xml_node_ptr node) const;
  bool has_filename_attribute(xml_node_ptr node) const;

  void check_dir_attribute(xml_node_ptr node, bool all_path=false);
  void check_id_and_filename_attribute(xml_node_ptr node);

  void generate_header() const;
  void generate_source() const;

private:
  static const char* ATTRIBUTE_DIR;
  static const char* ATTRIBUTE_ID;
  static const char* ATTRIBUTE_FILENAME;
  static const char* NODE_RESOURCE;
  static const char* NODE_IMAGE;
  static const char* NODE_SOUND;
  static const char* NODE_ITEM;

  std::string m_xml_filename;
  std::string m_res_filename;
  std::map<std::string, std::string> m_res_path;
  std::map<std::string, std::string> m_filenames;
};  // class Srg


//---
// Srg::Srg
//---
inline Srg::Srg(const std::string& xml_filename):
  m_xml_filename(xml_filename),
  m_res_filename(RESOURCE_FILENAME),
  m_res_path()
{
  m_res_path["image"] = "";
  m_res_path["sound"] = "";
}

//---
// Srg::~Srg
//---
inline Srg::~Srg()
{

}

}

/*!
 * \fn    void print_help()
 * \brief Print help message.
 */
void print_help();

#endif  //! SAC2_RESOURCE_GENERQTOR_HPP
