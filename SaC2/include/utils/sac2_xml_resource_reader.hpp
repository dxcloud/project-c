#ifndef SAC2_XML_RESOURCE_READER_HPP
#define SAC2_XML_RESOURCE_READER_HPP

#include <string>

#include <sac2_xml_reader.hpp>

namespace sac2
{

class XmlResourceReader:
  XmlReader
{
public:
  XmlResourceReader(const std::string& filename="");
  ~XmlResourceReader();
public:
  static const std::string ATTRIBUTE_DIR;
  static const std::string ATTRIBUTE_ID;
  static const std::string ATTRIBUTE_FILENAME;
  static const std::string NODE_RESOURCE;
  static const std::string NODE_IMAGE;
  static const std::string NODE_SOUND;
  static const std::string NODE_ITEM;
};  // class XmlResourceReader

#define XML_ATTRIBUTE_DIR XmlResourceReader::ATTRIBUTE_DIR.c_str()

}  // namespace sac2


#endif  //! SAC2_XML_RESOURCE_READER_HPP
