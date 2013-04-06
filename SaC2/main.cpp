#include "sac2.hpp"

int main(int argc, char* argv[])
{
  sac2::Engine app();
  sac2_status_t status(0);
  status = app.run();
  
  return status;
}