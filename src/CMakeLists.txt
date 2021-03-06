# Configuration
add_definitions(-Wall)

add_cirkit_library(
  NAME lscli
  AUTO_DIRS lscli
  USE
    ${Boost_REGEX_LIBRARIES}
    ${Boost_SYSTEM_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARIES}
    ${Boost_PROGRAM_OPTIONS_LIBRARIES}
    ${READLINE_LIBRARY}
)

add_cirkit_library(
  NAME cirkit_core
  AUTO_DIRS core
  USE
    ${Boost_REGEX_LIBRARIES}
    ${Boost_TIMER_LIBRARIES}
    ${Boost_SYSTEM_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARIES}
    ${Boost_PROGRAM_OPTIONS_LIBRARIES}
    ${CUDD_LIBRARIES}
    lscli
)

add_cirkit_library(
  NAME cirkit_classical
  AUTO_DIRS classical
  USE
    cirkit_core
    ${Boost_FILESYSTEM_LIBRARIES}
    ${abc_LIBRARIES}
    ${MINISAT_LIBRARIES}
  INCLUDE
    PUBLIC ${CMAKE_SOURCE_DIR}/ext/include/abc
)
