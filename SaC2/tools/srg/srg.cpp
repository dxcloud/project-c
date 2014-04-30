//////////////////////////////////////////////////////////////////////////////
//! \file    srg.cpp
//! \date    2013-06-10
//! \author  Chengwu Huang
//! \version 0.1
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

#include "srg.hpp"

namespace sac2
{

namespace srg
{

const char* Srg::ATTRIBUTE_DIR("dir");
const char* Srg::ATTRIBUTE_ID("id");
const char* Srg::ATTRIBUTE_FILENAME("filename");
const char* Srg::NODE_RESOURCE("resource");
const char* Srg::NODE_FONT("font");
const char* Srg::NODE_IMAGE("image");
const char* Srg::NODE_MUSIC("music");
const char* Srg::NODE_SOUND("sound");
const char* Srg::NODE_ITEM("item");

const std::string Srg::RESOURCE_FILENAME("resource");

//----------------------------------------------------------------------------
//  Srg::constructor
//----------------------------------------------------------------------------
Srg::Srg(const std::string& xml_filename):
  m_xml_filename(xml_filename),
  m_res_filename(RESOURCE_FILENAME),
  m_res_path()
{
  m_res_path["image"] = "";
  m_res_path["sound"] = "";
  m_res_path["font"]  = "";
  m_res_path["music"] = "";
}

//----------------------------------------------------------------------------
//  Srg::destructor
//----------------------------------------------------------------------------
Srg::~Srg()
{

}

//----------------------------------------------------------------------------
//  Srg::is_srg_node
//----------------------------------------------------------------------------
bool Srg::is_srg_node(const char* name1, const char* name2) const
{
  if (0 != strncmp(name1, name2, MAX_CHAR_LENGTH)) {
    return false;
  }
  return true;
}

//----------------------------------------------------------------------------
//  Srg::is_resource_node
//----------------------------------------------------------------------------
bool Srg::is_resource_node(const char* node_name) const
{
  if (false == is_srg_node(node_name, NODE_RESOURCE)) {
    std::cout << "Error: `" << node_name << "'"
              << " is NOT a valid Tag" << std::endl;
    return false;
  }
  return true;
}

//----------------------------------------------------------------------------
//  Srg::is_asset_node
//----------------------------------------------------------------------------
bool Srg::is_asset_node(const char* node_name) const
{
  if (false == is_srg_node(node_name, NODE_FONT)
      && false == is_srg_node(node_name, NODE_IMAGE)
      && false == is_srg_node(node_name, NODE_MUSIC)
      && false == is_srg_node(node_name, NODE_SOUND)) {
    std::cout << "Error: `" << node_name << "'"
              << " is NOT a valid asset type" << std::endl;
    return false;
  }  // if input node is valid
  return true;
}

//----------------------------------------------------------------------------
//  Srg::is_item_node
//----------------------------------------------------------------------------
bool Srg::is_item_node(const char* node_name) const
{
  if (false == is_srg_node(node_name, NODE_ITEM)) {
    std::cout << "Error: `" << node_name << "'"
              << " is NOT a valid Tag" << std::endl;
    return false;
  }
  return true;
}

//----------------------------------------------------------------------------
//  Srg::has_child
//----------------------------------------------------------------------------
bool Srg::has_child(xml_node_ptr parent) const
{
  if (0 == parent->first_node()) { return false; }
  return true;
}

//----------------------------------------------------------------------------
//  Srg::has_attribute
//----------------------------------------------------------------------------
bool Srg::has_attribute(xml_node_ptr node) const
{
  if (0 == node->first_attribute()) { return false; }
  return true;
}

//----------------------------------------------------------------------------
//  Srg:has_id_attribute
//----------------------------------------------------------------------------
bool Srg::has_id_attribute(xml_node_ptr node) const
{
  if (0 == node->first_attribute(ATTRIBUTE_ID)) { return false; }
  return true;
}

//----------------------------------------------------------------------------
//  Srg::has_filename_attribute
//----------------------------------------------------------------------------
bool Srg::has_filename_attribute(xml_node_ptr node) const
{
  if (0 == node->first_attribute(ATTRIBUTE_FILENAME)) { return false; }
  return true;
}

//----------------------------------------------------------------------------
//  Srg::is_srg_attribute
//----------------------------------------------------------------------------
bool Srg::is_srg_attribute(const char* name1, const char* name2) const
{
  if (0 != strncmp(name1, name2, MAX_CHAR_LENGTH)) {
    std::cout << "`" << name1 << "'"
              << "is NOT a valide Attribut" << std::endl;
    return false;
  }
  return true;
}

//----------------------------------------------------------------------------
//  Srg::is_dir_attribute
//----------------------------------------------------------------------------
bool Srg::is_dir_attribute(const char* attribute_name) const
{
  return is_srg_attribute(attribute_name, ATTRIBUTE_DIR);
}

//----------------------------------------------------------------------------
//  Srg::check_dir_attribute
//----------------------------------------------------------------------------
void Srg::check_dir_attribute(xml_node_ptr node, bool all_path)
{
  if (true == has_attribute(node)) {
    if (false == is_dir_attribute(node->first_attribute()->name())) {
      return;
    }  // if the node does NOT have `dir' attribute
    if (true == all_path) {
      for (filename_iter_t it(m_res_path.begin());
           it != m_res_path.end(); ++it) {
        it->second.append(node->first_attribute()->value());
        it->second.append("/");
      }
    }  // if all_path is true
    else {
      std::string res_type(node->name());
      m_res_path[res_type].append(node->first_attribute()->value());
      m_res_path[res_type].append("/");
    }
  }  // if the node has an attribute
}

//----------------------------------------------------------------------------
//  Srg::check_id_and_filename_attribute
//----------------------------------------------------------------------------
void Srg::check_id_and_filename_attribute(xml_node_ptr node)
{
  std::string id(node->first_attribute("id")->value());
  std::string filename(node->first_attribute("filename")->value());
  std::string res_name(node->parent()->name());
  m_filenames[id] = m_res_path[res_name] + filename;
  std::cout << "Creating ID `" << id << "'..."<< std::endl;
}

//----------------------------------------------------------------------------
//  Srg::parse_xml
//----------------------------------------------------------------------------
statut_t Srg::parse_xml()
{
  rapidxml::file<> file(m_xml_filename.c_str());
  rapidxml::xml_document<> xml_doc;
  xml_doc.parse<0>(file.data());

  xml_node_ptr node_root(xml_doc.first_node());
  if (false == is_resource_node(node_root->name())) { return FAIL; }

  check_dir_attribute(node_root, true);

  if (false == has_child(node_root)) { return FAIL; }
  for (xml_node_ptr node_type(node_root->first_node());
       0 != node_type; node_type = node_type->next_sibling()) {
    if (false == is_asset_node(node_type->name())) { return FAIL; }
    check_dir_attribute(node_type);

    if (false == has_child(node_type)) { return FAIL; }
    std::cout << "Reading node `" << node_type->name() << "' ..."<< std::endl;
    for (xml_node_ptr node_res(node_type->first_node());
         0 != node_res;
         node_res = node_res->next_sibling()) {
      if (false == is_item_node(node_res->name())) { return FAIL; }
      if ((false == has_id_attribute(node_res))
           || (false == has_filename_attribute(node_res))) {
        std::cout << "Error: attribute `id' and/or `filename' is missing"
                  << std::endl;
        return FAIL;
      }
      check_id_and_filename_attribute(node_res);
    }
  }
  return SUCCESS;
}

//----------------------------------------------------------------------------
//  Srg::generate
//----------------------------------------------------------------------------
void Srg::generate() const
{
  generate_header();
  generate_source();
}

//----------------------------------------------------------------------------
//  Srg::generate_header
//----------------------------------------------------------------------------
void Srg::generate_header() const
{
  std::ofstream ofs;
  std::string f_header(m_res_filename + ".hpp");
  ofs.open(f_header.c_str());
  if (true == ofs.is_open()) {
    insert_file_header(ofs, f_header);
    ofs << "#ifndef SRG_RESOURCE_HPP" << std::endl
        << "#define SRG_RESOURCE_HPP" << std::endl
        << std::endl
        << "enum RESOURCE_TABLE {" << std::endl;
    uint32_t res_counter(0);
    for (filename_const_iter_t it(m_filenames.begin());
         it != m_filenames.end();
         ++it) {
      ofs << "  " << it->first << " = " << "0x"
          << std::setw(sizeof(uint32_t))
          << std::setfill('0')
          << std::hex
          << res_counter++
          << "U," << std::endl;
    }
    ofs << "  NUM_ASSETS = " << std::resetiosflags(std::ios::hex)
        << res_counter << std::endl
        << "};" << std::endl
        << std::endl
        << "#endif"<< std::endl
        << std::endl;
  }
  ofs.close();
  std::cout << SRGNAME << "`" << m_res_filename << ".hpp' generated." << std::endl;
}

//----------------------------------------------------------------------------
//  Srg::generate_source
//----------------------------------------------------------------------------
void Srg::generate_source() const
{
  std::ofstream ofs;
  std::string f_source(m_res_filename + ".cpp");
  ofs.open(f_source.c_str());
  if (true == ofs.is_open()) {
    insert_file_header(ofs, f_source);
    ofs << "#include <sac2_asset_manager.hpp>" << std::endl
        << "#include \"" << m_res_filename << ".hpp\"" << std::endl
        << std::endl
        << "namespace sac2" << std::endl
        << "{" << std::endl
        << std::endl
        << "const asset_map_t AssetManager::m_asset_table =" << std::endl
        << "{" << std::endl;
    for (filename_const_iter_t it(m_filenames.begin());
         it != m_filenames.end();
         ++it) {
      if (m_filenames.begin() != it) {
        ofs << "," << std::endl;
      }
      ofs << "  {(asset_id_t) " << it->first << ", "
          << "\"" << it->second << "\"}";
    }
      ofs << std::endl << "};" << std::endl << std::endl
          << "}" << std::endl << std::endl;
  }
  ofs.close();
  std::cout << SRGNAME << "`" << m_res_filename << ".cpp' generated." << std::endl;
}

//----------------------------------------------------------------------------
//  Srg::insert_file_header
//----------------------------------------------------------------------------
void Srg::insert_file_header(std::ofstream& ofs, const std::string filename) const
{
  time_t time_info;
  std::time(&time_info);

  ofs << "/*!" << std::endl
      << " * \\file    " << filename << std::endl
      << " * \\date    " << std::ctime(&time_info)
      << " * \\warning This file is automatically generate by "
      << SRGNAME << "."
      << std::endl
      << " *          DO NOT EDIT THIS FILE." << std::endl
      << " */"
      << std::endl << std::endl;
}

//----------------------------------------------------------------------------
//  print_usage
//----------------------------------------------------------------------------
void Srg::print_usage()
{
  std::cout << "Usage: " << SRGNAME <<" <filename>" << std::endl;
}

}

}


//----------------------------------------------------------------------------
//  main
//----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  if (2 != argc) {
    sac2::srg::Srg::print_usage();
    return 1;
  }
  sac2::srg::Srg generator(argv[1]);
  if (sac2::srg::SUCCESS == generator.parse_xml()) {
    generator.generate();
  }

  return 0;
}

