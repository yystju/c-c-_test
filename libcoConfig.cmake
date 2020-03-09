# get_filename_component(LIBCO_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(LIBCO_DIR "${PROJECT_SOURCE_DIR}/dependencies/libco")
message("LIBCO_DIR : ${LIBCO_DIR}")

set(LIBCO_INCLUDE_DIRS "${LIBCO_DIR}/include/libco")
message("LIBCO_INCLUDE_DIRS : (${LIBCO_INCLUDE_DIRS}")

set(LIBCO_LIBRARIES_DIRS "${LIBCO_DIR}/lib")
message("LIBCO_LIBRARIES_DIRS : ${LIBCO_LIBRARIES_DIRS}")

FIND_LIBRARY(LIBCO_LIBRARIES "libcolib.a" ${LIBCO_LIBRARIES_DIRS})
message("LIBCO_LIBRARIES : ${LIBCO_LIBRARIES}")

set(LIBCO_EXECUTABLE "${LIBCO_DIR}/bin")
message("LIBCO_EXECUTABLE : ${LIBCO_EXECUTABLE}")