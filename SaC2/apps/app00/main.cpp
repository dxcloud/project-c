#include <sac2.hpp>

using namespace sac2;

int main(int argc, char* argv[])
{
  sac2::Engine app;
  sac2::sac2_status_t status(sac2::STATUS_SUCCESS);
  app.parse_options(argc, argv);
  status = app.run();

  return 0;
}
