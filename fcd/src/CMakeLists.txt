set(fcd_SRCS
   fcdservice.cpp
   Timer.cpp
)

add_executable (fcd ${fcd_SRCS})
target_link_libraries (fcd zmq protobuf boost_system boost_thread asn proto messages utility)
