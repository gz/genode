TARGET       = core
REQUIRES     = pistachio
LIBS         = base-common

GEN_CORE_DIR = $(BASE_DIR)/src/core

SRC_CC       = main.cc \
               multiboot_info.cc \
               ram_session_component.cc \
               ram_session_support.cc \
               rom_session_component.cc \
               cpu_session_component.cc \
               cpu_session_platform.cc \
               pd_session_component.cc \
               io_mem_session_component.cc \
               io_mem_session_support.cc \
               thread_start.cc \
               platform_thread.cc \
               platform_pd.cc \
               platform.cc \
               platform_services.cc \
               dataspace_component.cc \
               rm_session_component.cc \
               rm_session_support.cc \
               irq_session_component.cc \
               signal_session_component.cc \
               signal_source_component.cc \
               dump_alloc.cc \
               context_area.cc \
               core_printf.cc \
               kip.cc

INC_DIR     += $(REP_DIR)/src/core/include \
               $(REP_DIR)/src/base/console \
               $(GEN_CORE_DIR)/include

vpath main.cc                     $(GEN_CORE_DIR)
vpath ram_session_component.cc    $(GEN_CORE_DIR)
vpath rom_session_component.cc    $(GEN_CORE_DIR)
vpath cpu_session_component.cc    $(GEN_CORE_DIR)
vpath pd_session_component.cc     $(GEN_CORE_DIR)
vpath rm_session_component.cc     $(GEN_CORE_DIR)
vpath io_mem_session_component.cc $(GEN_CORE_DIR)
vpath io_mem_session_support.cc   $(GEN_CORE_DIR)
vpath signal_session_component.cc $(GEN_CORE_DIR)
vpath signal_source_component.cc  $(GEN_CORE_DIR)
vpath dataspace_component.cc      $(GEN_CORE_DIR)
vpath dump_alloc.cc               $(GEN_CORE_DIR)
vpath context_area.cc             $(GEN_CORE_DIR)
vpath core_printf.cc              $(BASE_DIR)/src/base/console
vpath kip.cc                      $(REP_DIR)/src/base/kip
vpath %.cc                        $(REP_DIR)/src/core
