find_package(PkgConfig REQUIRED QUIET)
pkg_check_modules(PC_ARAVIS QUIET aravis-0.8)

find_library(Aravis_LIBRARY
        NAMES aravis-0.8
        HINTS ${PC_ARAVIS_LIBDIR} ${PC_ARAVIS_LIBRARY_DIRS}
)

find_path(Aravis_INCLUDE_DIR
        NAMES arv.h
        HINTS ${PC_ARAVIS_INCLUDEDIR} ${PC_ARAVIS_INCLUDE_DIRS}
        PATH_SUFFIXES aravis-0.8
)

set(Aravis_LIBRARIES ${Aravis_LIBRARY})
set(Aravis_INCLUDE_DIRS ${Aravis_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Aravis
        REQUIRED_VARS Aravis_LIBRARY Aravis_INCLUDE_DIR
        VERSION_VAR Aravis_VERSION
)

mark_as_advanced(Aravis_LIBRARY Aravis_INCLUDE_DIR)
