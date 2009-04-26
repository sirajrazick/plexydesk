
include(${QT_USE_FILE})

INCLUDE_DIRECTORIES(
	${QT_INCLUDES}
)

SET(sourceFiles
	qplexyiconprovider.cpp
)

set(headerFiles
	qplexyiconprovider.h
)

set(QTMOC_SRCS
	qplexyiconprovider.h
)

qt4_wrap_cpp(QT_MOC_SRCS ${QTMOC_SRCS})

set(sourceFiles
	${sourceFiles}
	${headerFiles}
)

set(libs
	${QT_QTGUI_LIBRARY}
)

add_library (plexyiconprovider SHARED ${sourceFiles} ${QT_MOC_SRCS})

TARGET_LINK_LIBRARIES(
	plexyiconprovider
	${libs}
)

INSTALL(TARGETS plexyiconprovider DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

add_subdirectory(tests)
