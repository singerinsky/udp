AUX_SOURCE_DIRECTORY(. SRC_LIST)

SET(LIBRARY_OUTPUT_PATH ../lib)
ADD_LIBRARY(common ${SRC_LIST})
