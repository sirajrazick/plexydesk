include(${QT_USE_FILE})

INCLUDE_DIRECTORIES(
	${QT_INCLUDES}
)

SET(sourceFiles
	test.cpp
)

set(sourceFiles
	${sourceFiles}
)

set(libs
	${QT_QTCORE_LIBRARY}
)

ADD_EXECUTABLE(plexyiconprovidertest ${sourceFiles})

TARGET_LINK_LIBRARIES(
	plexyiconprovidertest
	plexyiconprovider
	${libs}
)

INSTALL(TARGETS plexyiconprovidertest DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
