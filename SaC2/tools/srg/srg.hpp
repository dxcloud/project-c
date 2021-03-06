//////////////////////////////////////////////////////////////////////////////
//! \file srg.hpp
//! \author
//! Chengwu HUANG
//! \version
//! 0.2.1 (develpment version)
//! \date
//! 2013-06-18
//! \date
//! 2013-08-21
//! \brief
//! Resource files generator.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_RESOURCE_GENERATOR_HPP
#define SAC2_RESOURCE_GENERATOR_HPP

#include <cstring>
#include <fstream>
#include <map>

#define RAPIDXML_NO_EXCEPTIONS
#include <rapidxml.hpp> // XML Parser
#include <rapidxml_utils.hpp>
#include <rapidxml_print.hpp>

#define VERBOSE(X) if (true == m_verbose) { std::cout << X << std::endl; }

//////////////////////////////////////////////////////////////////////////////
//! \namespace sac2::srg
//! \brief
//! Defines resource generator functionalities.
//////////////////////////////////////////////////////////////////////////////
namespace srg
{

enum {
  MAX_CHAR_LENGTH = 10 //!< Maximum length of string for comparison
};



//////////////////////////////////////////////////////////////////////////////
//! \class Srg
//! \brief
//! SaC2 Resource Generator class.
//////////////////////////////////////////////////////////////////////////////
class Srg
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Equivalent to \b rapidxml::xml_node<>*.
  ////////////////////////////////////////////////////////////////////////////
  typedef rapidxml::xml_node<>* xml_node_ptr;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Equivalent to \b rapidxml::xml_attribute<>*.
  ////////////////////////////////////////////////////////////////////////////
  typedef rapidxml::xml_attribute<>* xml_attribute_ptr;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Collection of filenames.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::map<std::string, std::string> filename_map_t;

public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Public default constructor.
  //! \param[in] xml_filename
  //! Input XML filename.
  ////////////////////////////////////////////////////////////////////////////
// explicit Srg(const std::string& xml_filename);
  Srg();

  void set_verbose(bool verbose)
  {
    m_verbose = verbose;
  }
  void set_input_file(const std::string& filename)
  {
    m_xml_filename = filename;
  }

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Public destructor.
  ////////////////////////////////////////////////////////////////////////////
  ~Srg();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Use RapidXML to parse xml file.
  ////////////////////////////////////////////////////////////////////////////
  bool parse_xml();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Generate the header and source file.
  ////////////////////////////////////////////////////////////////////////////
  void generate() const;

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Print unexpected attribute message.
  //! \param[in] node_name
  //! Unexpected node name.
  //! \param[in] attribute_name
  //! Unexpected
  ////////////////////////////////////////////////////////////////////////////
  bool parse_root_node(xml_node_ptr node);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Print unexpected attribute message.
  //! \param[in] node_name
  //! Unexpected node name.
  //! \param[in] attribute_name
  //! Unexpected
  ////////////////////////////////////////////////////////////////////////////
  bool parse_type_node(xml_node_ptr parent);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Print unexpected attribute message.
  //! \param[in] node_name
  //! Unexpected node name.
  //! \param[in] attribute_name
  //! Unexpected
  ////////////////////////////////////////////////////////////////////////////
  bool parse_item_node(xml_node_ptr parent);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Print unexpected attribute message.
  //! \param[in] node_name
  //! Unexpected node name.
  //! \param[in] attribute_name
  //! Unexpected
  ////////////////////////////////////////////////////////////////////////////
  bool parse_dir_attribute(xml_node_ptr attr);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Print unexpected attribute message.
  //! \param[in] node_name
  //! Unexpected node name.
  //! \param[in] attribute_name
  //! Unexpected
  ////////////////////////////////////////////////////////////////////////////
  bool parse_item_attribute(xml_node_ptr node);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Generate header file.
  ////////////////////////////////////////////////////////////////////////////
  void generate_header() const;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Generate source file.
  ////////////////////////////////////////////////////////////////////////////
  void generate_source() const;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Insert file header including warning.
  //! \param[in] ofs
  //! Output file stream.
  ////////////////////////////////////////////////////////////////////////////
  void insert_file_header(std::ofstream& ofs) const;

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Attribute \b dir name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* ATTRIBUTE_DIR;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Attribute \b id name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* ATTRIBUTE_ID;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Attribute \b filename name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* ATTRIBUTE_FILENAME;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Node \b resource name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* NODE_RESOURCE;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Node \b font name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* NODE_FONT;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Node \b image name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* NODE_IMAGE;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Node \b music name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* NODE_MUSIC;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Node \b sound name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* NODE_SOUND;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Node \b item name.
  ////////////////////////////////////////////////////////////////////////////
  static const char* NODE_ITEM;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Default output filename without extension.
  ////////////////////////////////////////////////////////////////////////////
  static const std::string RESOURCE_FILENAME;
  static const std::string HEADER_SUFFIX;
  static const std::string SOURCE_SUFFIX;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Collection of resource paths.
  ////////////////////////////////////////////////////////////////////////////
  filename_map_t m_path_map;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Collection of resource filenames
  ////////////////////////////////////////////////////////////////////////////
  filename_map_t m_res_map;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Input XML filename.
  ////////////////////////////////////////////////////////////////////////////
  std::string m_xml_filename;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //! Output resource filename without extension.
  ////////////////////////////////////////////////////////////////////////////
  std::string m_res_filename;

  std::string m_hdr_suffix;
  std::string m_src_suffix;
  bool m_verbose;
}; // class Srg

} // namespace srg

//////////////////////////////////////////////////////////////////////////////
//! \page misc Tools
//! \tableofcontents
//! This page describes the use of SRG (SaC2 Resource Generator).
//! \section misc1-1 Resource Generator
//! The program \b srg is able to generate both C++ source and header
//! files from XML. The generates files are required in order to use
//! correctly \b sac2::AssetManager.
//!
//! The program is written by using an extern library \b rapidxml to
//! parse XML.
//! \subsection misc1-1-1 Compilation and Installation
//! The directory \b SaC2/tools/srg should provide Makefile which the
//! command \b make may be used to compile and install this program.
//!
//! The default installation path is \b SaC2/tools/bin.
//! Use also the script \b sac2.sh at the root directory of \b SaC2 to
//! set environment variables.
//! \subsection misc1-1-2 Usage
//! With all SaC2 environment variables defined, the following command
//! invokes \b srg program.
//! The argument \b FILENAME is required. The default generated filenames
//! are \b resource.hpp and \b resource.cpp
//! \code
//! $ srg FILENAME
//! \endcode
//! \subsection misc1-1-3 XML structure
//! The XML file must have 3 levels of hierarchy.
//! - Type of XML file, in this case: \b <resource> and \b </resource>.
//! - Type of resource: image, sound, font, etc.
//! - Resource items
//! \subsection misc1-1-4 Example
//! \code
//! <resource dir="samples">
//! <image dir="images">
//! <item id="IMAGE1" filename="image1.png" />
//! </image>
//! </resource>
//! \endcode
//! \todo
//! Elements may be included (options):
//! - Specify output filename (non extension): '--output=FILE'
//! - Verbose: '--verbose', '-v'
//! - Source/Header file suffix: '--src-suffix=SUFF', '--hdr-suffix=SUFF'
//! - Help: '--help', '-h'
//! - Version: '--version', '-V'
//! - Warning: '--warning', '-w'
//! - Disable documentation comment: '--no-comment', '-n'
//! - Preserve order: '--same-order', '-s'
//! - To stdout: '--to-stdout', '-O'
//! - Ignore resource: '--ignore-image', '--ignore-sound', etc.
//! - Add files: '--add-file=FILE'
//!
//! Valid HDR suffixes: hh, H, hpp (default), hxx, HPP, h++
//! Valid SRC suffixes: cc, C, cpp (default), cxx, CPP, c++
//////////////////////////////////////////////////////////////////////////////

#endif //! SAC2_RESOURCE_GENERATOR_HPP
