/*!
 * \file    srg.cpp
 * \date    2013-06-10
 * \author  Chengwu Huang
 * \version 0.1
 */

#include <iostream> 
#include <cassert>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

#include "srg.hpp"

namespace srg
{

const char* Srg::RESOURCE_FILENAME("res.cpp");
const char* Srg::ATTRIBUTE_DIR("dir");
const char* Srg::ATTRIBUTE_ID("id");
const char* Srg::ATTRIBUTE_FILENAME("filename");
const char* Srg::NODE_RESOURCE("resource");
const char* Srg::NODE_IMAGE("image");
const char* Srg::NODE_SOUND("sound");
const char* Srg::NODE_ITEM("item");

enum {
  MAX_CHAR_LENGTH = 10
};

bool Srg::is_srg_node(const char* name1, const char* name2) const
{
  if (0 != strncmp(name1, name2, MAX_CHAR_LENGTH)) {
    std::cout << "\"" << name1 << "\"" << " is NOT a valide Tag" << std::endl;
    return false;
  }
  std::cout << "Reading " << name1 << std::endl;
  return true;
}

bool Srg::is_resource_node(const char* node_name) const
{
  return is_srg_node(node_name, NODE_RESOURCE);
}

bool Srg::has_child(xml_node_ptr parent) const
{
  if (0 == parent->first_node()) { return false; }
  return true;
}

bool Srg::has_attribute(xml_node_ptr node) const
{
  if (0 == node->first_attribute()) { return false; }
  return true;
}

bool Srg::has_id_attribute(xml_node_ptr node) const
{
  if (0 == node->first_attribute(ATTRIBUTE_ID)) { return false; }
  return true;
}

bool Srg::has_filename_attribute(xml_node_ptr node) const
{
  if (0 == node->first_attribute(ATTRIBUTE_FILENAME)) { return false; }
  return true;
}

bool Srg::is_srg_attribute(const char* name1, const char* name2) const
{
  if (0 != strncmp(name1, name2, MAX_CHAR_LENGTH)) {
    std::cout << "\"" << name1 << "\"" << " is NOT a valide Attribut" << std::endl;
    return false;
  }
  return true;
}

bool Srg::is_dir_attribute(const char* attribute_name) const
{
  return is_srg_attribute(attribute_name, ATTRIBUTE_DIR);
}

void Srg::check_dir_attribute(xml_node_ptr node, bool all_path)
{
  if (true == has_attribute(node)) {
    if (false == is_dir_attribute(node->first_attribute()->name())) {
      return;
    }
    if (true == all_path) {
      for (std::map<std::string, std::string>::iterator it(m_res_path.begin());
           it != m_res_path.end(); ++it) {
        it->second.append(node->first_attribute()->value());
        it->second.append("/");
      }
    }
    else {
      std::string res_type(node->name());
      m_res_path[res_type].append(node->first_attribute()->value());
      m_res_path[res_type].append("/");
    }
  }
}

void Srg::check_id_and_filename_attribute(xml_node_ptr node)
{
  std::string id(node->first_attribute("id")->value());
  std::string filename(node->first_attribute("filename")->value());
  std::string res_name(node->parent()->name());
  m_filenames[id] = m_res_path[res_name] + filename;
  std::cout << "Associate " << m_filenames[id] << " with " << id << std::endl;
}


void Srg::parse_xml()
{
  rapidxml::file<> file(m_xml_filename.c_str());
  rapidxml::xml_document<> xml_doc;
  xml_doc.parse<0>(file.data());

  xml_node_ptr node_root(xml_doc.first_node());
  if (false == is_resource_node(node_root->name())) { return; }

  check_dir_attribute(node_root, true);

  if (false == has_child(node_root)) { return; }
  for (xml_node_ptr node_type(node_root->first_node());
       0 != node_type; node_type = node_type->next_sibling()) {
    check_dir_attribute(node_type);

    if (false == has_child(node_type)) { return; }
    for (xml_node_ptr node_res(node_type->first_node());
         0 != node_res;
         node_res = node_res->next_sibling()) {
      std::cout << "Reading " << node_type->name() << std::endl;
      if ((false == has_id_attribute(node_res))
           || (false == has_filename_attribute(node_res))) {
        std::cout << "Attribute \"dir\" and/or \"filename\" is missing" << std::endl;
        return;
      }
      check_id_and_filename_attribute(node_res);
    }
  }
}

}


//---
// print_help
//---
void print_help()
{
  std::cout << "Usage: ./srg <filename>" << std::endl;
}

//---
// main
//--
int main(int argc, char* argv[])
{
  if (2 != argc) {
    print_help();
    exit(0);
  }
  srg::Srg generator(argv[1]);
  generator.parse_xml();

  return 0;
}
