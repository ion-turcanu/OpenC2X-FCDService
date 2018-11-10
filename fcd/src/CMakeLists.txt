include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/fcd/src/external/
)
set(fcd_SRCS
   fcdservice.cpp
   Timer.cpp
   external/pbjson.cpp
   external/pbjson.hpp
)

add_executable (fcd ${fcd_SRCS} ${pbjson_SRCS})
target_link_libraries (fcd zmq protobuf boost_system boost_thread pthread asn proto messages utility)
