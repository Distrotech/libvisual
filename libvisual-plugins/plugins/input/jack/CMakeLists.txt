LV_BUILD_INPUT_PLUGIN(jack
  SOURCES      input_jack.cpp
  COMPILE_DEFS ${JACK_CFLAGS_OTHER}
  INCLUDE_DIRS ${JACK_INCLUDE_DIRS}
  LINK_DIRS    ${JACK_LIBRARY_DIRS}
  LINK_LIBS    ${JACK_LIBRARIES}
)
