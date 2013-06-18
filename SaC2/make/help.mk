###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/sac2.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Print help message
###---------------------------------------------------------------------------

###---------------------------------------------------------------------------
### Syntax error message
###---------------------------------------------------------------------------
define SAC2_HELP_SYNTAX
$(SAC2_HELP_MAKE)

ERROR:
  Syntax error `make $(MAKECMDGOALS)'

$(SAC2_HELP_USAGE)

SEE ALSO:
  For all valid commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### All commands message
###---------------------------------------------------------------------------
define SAC2_HELP_MAIN
$(SAC2_HELP_MAKE)

$(SAC2_HELP_USAGE)

COMMAND:
  all             Compile the entire program.
  archive         Create a tar achive of the source files.
  clean           Remove object and temporary files.
  depend          List dependencies of the sources files.
  distclean       Delete all object and shared object files.
  docs            Generate documentation.
  exec            Build application.
  help [command]  Display help.
  memcheck        Run application for memory leak detection.
  mrproper        Remove all generated files and directories.
  run             Run appliction.

SEE ALSO:
  For more information about a command, type `make help <COMMAND>'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Unknown user command message
###---------------------------------------------------------------------------
define SAC2_HELP_UNKNOWN_CMD
$(SAC2_HELP_MAKE)

ERROR:
  Unknown command `$(MAKECMDGOALS)'

$(SAC2_HELP_USAGE)

SEE ALSO:
  For all valid commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `all' command help
###---------------------------------------------------------------------------
define SAC2_HELP_all
$(SAC2_HELP_MAKE)

COMMAND:
  `make all'

DESCRIPTION:

SEE ALSO:
  For the compilation, type `make help exec'.
  For all valid commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `archive' help
###---------------------------------------------------------------------------
define SAC2_HELP_archive
$(SAC2_HELP_MAKE)

COMMAND:
  `make archive'

DESCRIPTION:

SEE ALSO:
  See all valid commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `clean' help
###---------------------------------------------------------------------------
define SAC2_HELP_clean
$(SAC2_HELP_MAKE)

COMMAND:
  `make clean'

SEE ALSO:
  Dor all valid commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `depend' help
###---------------------------------------------------------------------------
define SAC2_HELP_depend
$(SAC2_HELP_MAKE)

COMMAND:
  `make depend'

SEE ALSO:
  For all valid commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `distclean' help
###---------------------------------------------------------------------------
define SAC2_HELP_distclean
$(SAC2_HELP_MAKE)

COMMAND: `make distclean'

See all commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `docs' help
###---------------------------------------------------------------------------
define SAC2_HELP_docs
$(SAC2_HELP_MAKE)

COMMAND: `make docs'

See all commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `exec' help
###---------------------------------------------------------------------------
define SAC2_HELP_clean
$(SAC2_HELP_MAKE)

COMMAND: `make exec'

See all commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `help' help
###---------------------------------------------------------------------------
define SAC2_HELP_help
$(SAC2_HELP_MAKE)

COMMAND: `make help [command]'

See all commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `memcheck' help
###---------------------------------------------------------------------------
define SAC2_HELP_memcheck
$(SAC2_HELP_MAKE)

COMMAND: `make memcheck'

See all commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `mrproper' help
###---------------------------------------------------------------------------
define SAC2_HELP_mrproper
$(SAC2_HELP_MAKE)

COMMAND: `make mrproper'

See all commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Print `run' help
###---------------------------------------------------------------------------
define SAC2_HELP_run
$(SAC2_HELP_MAKE)

COMMAND: `make run'

See all commands, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Define valid goals
###---------------------------------------------------------------------------
PRINT_UNKNOWN_CMD_HELP=no
USER_CMD_HELP = $(filter $(word 2,$(MAKECMDGOALS)),$(SAC2_GOALS))

define unknown_cmd
PRINT_UNKNOWN_CMD_HELP:=yes
$(1):: .FORCE
	@:
endef

define print_cmd_help
$(info $(SAC2_HELP_$(1)))
endef

$(foreach cmd,$(filter-out $(SAC2_GOALS),$(MAKECMDGOALS)),$(eval $(call unknown_cmd,$(cmd))))

ifneq (, $(word 3,$(MAKECMDGOALS)))
  $(info $(SAC2_HELP_SYNTAX))
else
  ifeq (,$(MAKECMDGOALS))
    $(info $(SAC2_HELP_SYNTAX))
  else ifeq (help,$(MAKECMDGOALS))
    $(info $(SAC2_HELP_MAIN))
  else
   ifeq (yes, $(PRINT_UNKNOWN_CMD_HELP))
     $(info $(SAC2_HELP_UNKNOWN_CMD))
   else
     $(call print_cmd_help,$(word 2,$(MAKECMDGOALS)))
   endif
  endif
endif

help:: .FORCE
	@:

$(USER_CMD_HELP):: .FORCE
	@:

