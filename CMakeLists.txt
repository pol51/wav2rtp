# cmake settings
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
set(CMAKE_VERBOSE_MAKEFILE OFF)

# project
project(wav2rtp)

# config
set(CONFDIR "/etc/wav2rtp")
set(VERSION "0.9.3")

# add defines
add_definitions(-DCONFDIR=\"${CONFDIR}\" -DVERSION=\"${VERSION}\")

# sources
file(GLOB_RECURSE WAV2RTP_SOURCES src/*.h src/*.c)
file(GLOB_RECURSE IGNORED_SOURCES src/*_test.c src/*_test.h)

# find required libs
find_library(PCAP_LIB pcap)
find_library(MATH_LIB m)
find_library(SNDFILE_LIB sndfile)
find_library(GSM_LIB gsm)
find_library(SPEEX_LIB speex)
set(LIBRARIES ${LIBRARIES} ${PCAP_LIB} ${MATH_LIB} ${SNDFILE_LIB} ${GSM_LIB} ${SPEEX_LIB})

# hide internal values
mark_as_advanced(PCAP_LIB)

# remove unused sources
list(REMOVE_ITEM WAV2RTP_SOURCES ${IGNORED_SOURCES})

# project target
add_executable(wav2rtp ${WAV2RTP_SOURCES})
target_link_libraries(wav2rtp ${LIBRARIES})
