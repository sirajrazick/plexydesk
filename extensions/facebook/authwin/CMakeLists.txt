INCLUDE(${QT_USE_FILE})

INCLUDE_DIRECTORIES(
	${QT_INCLUDES}
	${QT_QTOPENGL_INCLUDE_DIR}
	${QT_QTNETWORK_INCLUDE_DIR}
	${QT_QTTEST_INCLUDE_DIR}
)

SET (sourceFiles
	authplugin.cpp
	authwidgetinterface.cpp
   authwidget.cpp
)

SET(headerFiles
   authplugin.h
	authwidgetinterface.h
   authwidget.h
)

SET(QTMOC_SRCS
	authplugin.h
	authwidgetinterface.h
   authwidget.h
)

qt4_wrap_cpp(QT_MOC_SRCS ${QTMOC_SRCS})

SET(sourceFiles
	${sourceFiles}
	${headerFiles}
)

SET(libs
	${QT_QTGUI_LIBRARY}
	${OPENGL_LIBRARIES}
	${QT_QTCORE_LIBRARY}
	${QT_QTOPENGL_LIBRARY}
)

ADD_LIBRARY(plexyauth SHARED ${sourceFiles} ${QT_MOC_SRCS})

TARGET_LINK_LIBRARIES(
	plexyauth
	plexydeskcore
   plexyjson
   webqgv
	${libs}
)

INSTALL(TARGETS plexyauth DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/plexyext/)
INSTALL(FILES authwidget.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/ext/groups/)
