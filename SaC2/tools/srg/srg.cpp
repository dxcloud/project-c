//////////////////////////////////////////////////////////////////////////////
//! \file srg.cpp
//! \author
//! Chengwu Huang
//! \version
//! 0.2.1 (alpha)
//! \date
//! 2013-06-10
//! \date
//! 2013-08-21
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <ctime>

//#define RAPIDXML_NO_EXCEPTIONS
#include "srg.hpp"

void rapidxml::parse_error_handler(const char* what, void* where)
{
  std::cout << "what: " << what << std::endl;
  std::cout << "where" << reinterpret_cast<char*>(where) << std::endl;
}


namespace srg
{

using std::cout;
using std::endl;
using std::string;

const char* Srg::ATTRIBUTE_DIR = "dir";
const char* Srg::ATTRIBUTE_ID = "id";
const char* Srg::ATTRIBUTE_FILENAME = "filename";
const char* Srg::NODE_RESOURCE = "resource";
const char* Srg::NODE_FONT = "font";
const char* Srg::NODE_IMAGE = "image";
const char* Srg::NODE_MUSIC = "music";
const char* Srg::NODE_SOUND = "sound";
const char* Srg::NODE_ITEM = "item";

const string Srg::RESOURCE_FILENAME = "resource";
const string Srg::HEADER_SUFFIX = "hpp";
const string Srg::SOURCE_SUFFIX = "cpp";

//////////////////////////////////////////////////////////////////////////////
// Srg::Srg
//////////////////////////////////////////////////////////////////////////////
Srg::Srg():
  m_path_map(),
  m_res_map(),
  m_xml_filename(),
  m_res_filename(RESOURCE_FILENAME),
  m_hdr_suffix(HEADER_SUFFIX),
  m_src_suffix(SOURCE_SUFFIX),
  m_verbose(false)
{
  m_path_map[NODE_IMAGE] = "";
  m_path_map[NODE_SOUND] = "";
  m_path_map[NODE_FONT] = "";
  m_path_map[NODE_MUSIC] = "";
}

//////////////////////////////////////////////////////////////////////////////
// Srg::~Srg
//////////////////////////////////////////////////////////////////////////////
Srg::~Srg()
{

}

//////////////////////////////////////////////////////////////////////////////
// unexpected_node
//////////////////////////////////////////////////////////////////////////////
void unexpected_node(const char* node_name)
{
// cout << "Error while parsing <NODE> `" << node_name << "'..." << endl;
  cout << ">> Unexpected <NODE> `" << node_name << "'" << endl;
}

//////////////////////////////////////////////////////////////////////////////
// required_node
//////////////////////////////////////////////////////////////////////////////
void required_node(const char* node_name)
{
   cout << ">> Resources required" << endl;
}

//////////////////////////////////////////////////////////////////////////////
// unexpected_attribute
//////////////////////////////////////////////////////////////////////////////
void unexpected_attribute(const char* node_name, const char* attribute_name)
{
  cout << ">> Unexpected <ATTRIBUTE> `" << attribute_name << "'" << endl;
}

//////////////////////////////////////////////////////////////////////////////
// required_attribute
//////////////////////////////////////////////////////////////////////////////
void required_attribute(const char* node_name, const char* attribute_name)
{
  cout << ">> Expecting <ATTRIBUTE> `" << attribute_name << "'" << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Srg::parse_dir_attribute
//////////////////////////////////////////////////////////////////////////////
bool Srg::parse_dir_attribute(xml_node_ptr node)
{
  for (xml_attribute_ptr attr(node->first_attribute());
       0 != attr;
       attr = attr->next_attribute()) {
    if (0 == strncmp(attr->name(), ATTRIBUTE_DIR, MAX_CHAR_LENGTH)) {
      VERBOSE("Parsing <ATTRIBUTE> `" << ATTRIBUTE_DIR << "="
                << attr->value() << "'")
      return true;
    } // attribute found
    else {
      unexpected_attribute(node->name(), attr->name());
    } // unexpected attribute
  }
  return false;
}

//////////////////////////////////////////////////////////////////////////////
// Srg::parse_item_attribute
//////////////////////////////////////////////////////////////////////////////
bool Srg::parse_item_attribute(xml_node_ptr node)
{
  bool attr_filename(false);
  bool attr_id(false);
  for (xml_attribute_ptr attr(node->first_attribute());
       0 != attr;
       attr = attr->next_attribute()) {
    if (0 == strncmp(attr->name(), ATTRIBUTE_FILENAME, MAX_CHAR_LENGTH)) {
      VERBOSE("Parsing <ATTRIBUTE> `" << ATTRIBUTE_FILENAME << "="
                << attr->value() << "'")
      attr_filename = true;
    } // attribute found
    else if (0 == strncmp(attr->name(), ATTRIBUTE_ID, MAX_CHAR_LENGTH)) {
      VERBOSE("Parsing <ATTRIBUTE> `" << ATTRIBUTE_ID << "="
                << attr->value() << "'")
      attr_id = true;
    } // attribute found
    else {
      unexpected_attribute(node->name(), attr->name());
    } // unexpected attribute
  }
  if (false == attr_filename) {
    required_attribute(node->name(), ATTRIBUTE_FILENAME);
    return false;
  }
  if (false == attr_id) {
    required_attribute(node->name(), ATTRIBUTE_ID);
    return false;
  }
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// Srg::parse_root_node
//////////////////////////////////////////////////////////////////////////////
bool Srg::parse_root_node(xml_node_ptr node)
{
  VERBOSE("Parsing <NODE> `" << node->name() << "'...")
  if (true == parse_dir_attribute(node)) {
    for (filename_map_t::iterator it(m_path_map.begin());
         it != m_path_map.end();
         ++it) {
      it->second.append(node->first_attribute(ATTRIBUTE_DIR)->value());
      it->second.append("/");
    }
  } // attribute found
  if (0 == node->first_node()) {
    required_node(node->name());
    return false;
  } // expected node
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// Srg::parse_type_node
//////////////////////////////////////////////////////////////////////////////
bool Srg::parse_type_node(xml_node_ptr parent)
{
  for (xml_node_ptr node_type(parent->first_node());
       0 != node_type;
       node_type = node_type->next_sibling()) {
    if ((0 != strncmp(node_type->name(), NODE_FONT, MAX_CHAR_LENGTH))
         && (0 != strncmp(node_type->name(), NODE_IMAGE, MAX_CHAR_LENGTH))
         && (0 != strncmp(node_type->name(), NODE_MUSIC, MAX_CHAR_LENGTH))
         && (0 != strncmp(node_type->name(), NODE_SOUND, MAX_CHAR_LENGTH))) {
      unexpected_node(node_type->name());
      return false;
    } // unexpected node

    VERBOSE("Parsing <NODE> `" << node_type->name() << "'...")
    if (true == parse_dir_attribute(node_type)) {
      m_path_map[node_type->name()].append(node_type->first_attribute()->value());
      m_path_map[node_type->name()].append("/");
    }
    if (0 == node_type->first_node()) {
      required_node(node_type->name());
      return false;
    } // expected node
    if (false == parse_item_node(node_type)) { return false; }
  }
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// Srg::parse_item_node
//////////////////////////////////////////////////////////////////////////////
bool Srg::parse_item_node(xml_node_ptr parent)
{
  for (xml_node_ptr node_res(parent->first_node());
       0 != node_res;
       node_res = node_res->next_sibling()) {
    if (0 != strncmp(node_res->name(), NODE_ITEM, MAX_CHAR_LENGTH)) {
      unexpected_node(node_res->name());
      return false;
    } // no item found
    if (0 != node_res->first_node()) {
      unexpected_node(node_res->first_node()->name());
      return false;
    } // unexpected child node
    if (false == parse_item_attribute(node_res)) {
      return false;
    }
    m_res_map[node_res->first_attribute(ATTRIBUTE_ID)->value()] =
      m_path_map[node_res->parent()->name()]
      + node_res->first_attribute(ATTRIBUTE_FILENAME)->value();
  }
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// Srg::parse_xml
//////////////////////////////////////////////////////////////////////////////
bool Srg::parse_xml()
{
  VERBOSE("Reading `" << m_xml_filename << "'...")
  rapidxml::xml_document<> xml_doc;
  rapidxml::file<> file(m_xml_filename.c_str());
  xml_doc.parse<0>(file.data());

  for (xml_node_ptr node(xml_doc.first_node());
       0 != node;
       node = node->next_sibling()) {
    if (0 != strncmp(node->name(), NODE_RESOURCE, MAX_CHAR_LENGTH)) {
      unexpected_node(node->name());
      return false;
    } // unexpected node
  }
  xml_node_ptr node_root(xml_doc.first_node());
  if (false == parse_root_node(node_root)) { return false; }
  if (false == parse_type_node(node_root)) { return false; }
  xml_doc.clear();
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// Srg::generate
//////////////////////////////////////////////////////////////////////////////
void Srg::generate() const
{
  generate_header();
  generate_source();
}

//////////////////////////////////////////////////////////////////////////////
// Srg::generate_header
//////////////////////////////////////////////////////////////////////////////
void Srg::generate_header() const
{
  std::ofstream ofs;
  std::string header(m_res_filename + ".hpp");
  ofs.open(header.c_str());
  if (true == ofs.is_open()) {
    insert_file_header(ofs);
    ofs << "#ifndef SRG_RESOURCE_HPP" << std::endl
        << "#define SRG_RESOURCE_HPP" << std::endl
        << std::endl
        << "enum RESOURCE_TABLE {" << std::endl;
    uint32_t res_counter(0);
    for (filename_map_t::const_iterator it(m_res_map.begin());
         it != m_res_map.end();
         ++it) {
      ofs << " " << it->first << " = " << "0x"
          << std::setw(sizeof(uint32_t))
          << std::setfill('0')
          << std::hex
          << res_counter++
          << "U," << std::endl;
    }
    ofs << " NUM_ASSETS = " << std::resetiosflags(std::ios::hex)
        << res_counter << std::endl
        << "};" << std::endl
        << std::endl
        << "#endif"<< std::endl
        << std::endl;
  }
  ofs.close();
  VERBOSE("Generating `" << m_res_filename << "." << m_hdr_suffix << "'...")
}

//////////////////////////////////////////////////////////////////////////////
// Srg::generate_source
//////////////////////////////////////////////////////////////////////////////
void Srg::generate_source() const
{
  std::ofstream ofs;
  std::string source(m_res_filename + ".cpp");
  ofs.open(source.c_str());
  if (true == ofs.is_open()) {
    ofs << "#include <sac2_asset_manager.hpp>" << std::endl
        << "#include \"" << m_res_filename << ".hpp\"" << std::endl
        << std::endl
        << "namespace sac2" << std::endl
        << "{" << std::endl
        << std::endl
        << "const AssetManager::asset_map_t AssetManager::m_asset_table ="
        << std::endl
        << "{" << std::endl;
    for (filename_map_t::const_iterator it(m_res_map.begin());
         it != m_res_map.end();
         ++it) {
      if (m_res_map.begin() != it) {
        ofs << "," << std::endl;
      }
      ofs << " {(asset_id_t) " << it->first << ", "
          << "\"" << it->second << "\"}";
    }
      ofs << std::endl << "};" << std::endl << std::endl
          << "}" << std::endl << std::endl;
  }
  ofs.close();
  VERBOSE("Generating `" << m_res_filename << "." << m_src_suffix << "'...")
}

//////////////////////////////////////////////////////////////////////////////
// Srg::insert_file_header
//////////////////////////////////////////////////////////////////////////////
void Srg::insert_file_header(std::ofstream& ofs) const
{
  time_t time_info;
  std::time(&time_info);

  ofs << "/*!" << std::endl
      << " * \\file " << m_res_filename << ".hpp" << std::endl
      << " * \\date " << std::ctime(&time_info)
      << " * \\warning This file is automatically generate by `srg''."
      << std::endl
      << " * DO NOT EDIT THIS FILE." << std::endl
      << " */"
      << std::endl << std::endl;
}

} // namespace srg
