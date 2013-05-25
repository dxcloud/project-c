#include <sac2.hpp>

int main(int argc, char* argv[])
{
  sac2::Engine app;
  app.parse_options(argc, argv);
  app.run();

  return 0;
}
