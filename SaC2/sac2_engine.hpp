#ifndef _SAC2_ENGINE_HPP_
#define _SAC2_ENGINE_HPP_

#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_state_manager.hpp"

//! \todo load from a configuration file

//class GameState;
//class StateManager;

namespace sac2
{

class Engine
{
 public:
  Engine(const std::string& title=defaultApplicationName):
    m_title(title),
    m_video_mode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, DEFAULT_VIDEO_BPP),
    m_window(),
    m_window_settings(),
//    m_window_style(sf::Style::Close | sf::Style::Resize),
    m_window_style(DEFAULT_STYLE),
    m_input(m_window.GetInput()),
//    m_asset_manager(),
//    m_stat_manager(),

//    m_exit_code(STATUS_SUCCESS),
    m_running(false),
    m_state_manager()
    //    m_update_rate(1.0F / 100)
  {
#ifdef LOG_ENABLED
    m_log_file.assign(defaultLogFile);
    m_log.open(m_log_file.c_str());
    m_log << "Log File: " m_log_file << std::endl;
    m_log << "Engine started" << std::endl;
#endif
  }

  ~Engine()
  {
#ifdef LOG_ENABLED
    m_running = false;
    m_log << "Engine stopped" << std::endl;
#endif
  }

  void process_arguments(int argc, char* argv[]);

  sac2_status_t run(void);
  
  bool is_running(void) const;
  
//  float get_update_rate(void) const;
  
  sac2_status_t quit();
  
//  sac2_status_t pre_init();
  
  sac2_status_t init();
  
  void loop();

  sac2_status_t update();

  sac2_status_t draw();


  sac2_status_t cleanup();
//  static const engine_conf_t& load_config(const std::string& filename);

//  protected:

 private:
  std::string         m_title;            //!< Title for Window
  sf::VideoMode       m_video_mode;       //!< Video Mode (width, height, bpp)
  sf::RenderWindow    m_window;           //!< Render window
  sf::WindowSettings  m_window_settings;  //!< Window settings
  unsigned long       m_window_style;     //!< Window style
  const sf::Input&    m_input;            //!< Input manager for Tender window above
  
//  int                 m_exit_code;        //!< The exit code value that will be returned by the program
  bool                m_running;          //!< True if the application is currently running
//  float               m_update_rate;      //!< Looger output path and filename

//  AssetManager        m_asset_mng;
//  StatManager         m_stat_mng;
  StateManager        m_state_manager;

#ifdef LOG_ENABLED
  std::ofstream       m_log;
  std::string         m_log_filename;
#endif

};  // class Engine

}

#endif