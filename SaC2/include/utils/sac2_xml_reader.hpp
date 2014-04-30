/*!
 * \file sac2_xml_reader.hpp
 */

#ifndef SAC2_XML_READER_HPP
#define SAC2_XML_READER_HPP

#include <string>
#include <vector>

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

namespace sac2
{


typedef rapidxml::xml_node<>*      xml_node_ptr;
typedef rapidxml::xml_attribute<>* xml_attribute_ptr;

class XmlReader
{
public:
  explicit XmlReader(const std::string& filename="");
  ~XmlReader();
  void set_xml_filename(const std::string& filename);
  const std::string& get_xml_filename() const;
  xml_node_ptr get_xml_node(const std::string& node_name) const;
  xml_node_ptr get_xml_next_node(const std::string& node_name) const;
  xml_node_ptr get_xml_node_next(const std::string& node_name) const;
  xml_attribute_ptr get_
  void set_xml_node(rapidxml::xml_node<>* node);
  void parse_xml();
protected:
private:
  std::string m_filename;
  rapidxml::file<> m_xml_file;
  std::vector<rapidxml::xml_node<>*> m_xml_nodes;
};  // class XmlReader

}

#endif  //! SAC2_XML_READER_HPP
