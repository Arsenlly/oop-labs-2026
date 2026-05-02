cmake_minimum_required(VERSION 3.5)

project(lab_03 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab_03
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET lab_03 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(lab_03 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(lab_03
            ${PROJECT_SOURCES}
            Facade/scenefacade.h Facade/scenefacade.cpp
            Command/basecommand.h
            DrawManager/drawmanager.h
            LoadManager/loadmanager.h
            TransformManager/transformmanager.h
            Command/basecommand.cpp
            Command/ModelCommand/basemodelcommand.h Command/ModelCommand/basemodelcommand.cpp
            Command/ModelCommand/movemodelcommand.h Command/ModelCommand/movemodelcommand.cpp
            Command/ModelCommand/scalemodelcommand.h Command/ModelCommand/scalemodelcommand.cpp
            Command/ModelCommand/rotatemodelcommand.h Command/ModelCommand/rotatemodelcommand.cpp
            Object/object.h Object/object.cpp
            Object/VisibleObject/visibleobject.h
            Object/InvisibleObject/invisibleobject.h Object/InvisibleObject/invisibleobject.cpp
            Object/Model/basemodel.h Object/Model/basemodel.cpp
            Object/Model/SkeletonModel/skeletonmodel.h Object/Model/SkeletonModel/skeletonmodel.cpp
            Object/Model/SkeletonModel/Structure/modelstructure.h Object/Model/SkeletonModel/Structure/modelstructure.cpp
            Object/Point/point.h Object/Point/point.cpp
            Object/Edge/edge.h Object/Edge/edge.cpp
            Object/Model/SkeletonModel/Structure/ListStructure/listmodelstructure.h Object/Model/SkeletonModel/Structure/ListStructure/listmodelstructure.cpp
            Object/Model/SkeletonModel/Structure/MatrixStructure/matrixmodelstructure.h Object/Model/SkeletonModel/Structure/MatrixStructure/matrixmodelstructure.cpp
            SceneManager/scenemanager.h SceneManager/scenemanager.cpp
            TransformManager/transformmanager.cpp
            Object/VisibleObject/visibleobject.cpp
            Scene/scene.h Scene/scene.cpp
            LoadManager/loadmanager.cpp
            Reader/ReaderSolution/readersolution.h Reader/ReaderSolution/readersolution.cpp
            Reader/ReaderCreator/basereadercreator.h Reader/ReaderCreator/basereadercreator.cpp


            Reader/basereader.h Reader/basereader.cpp
            Reader/ModelReader/modelreader.h Reader/ModelReader/modelreader.cpp
            Reader/ModelReader/TxtModelReader/txtmodelreader.h Reader/ModelReader/TxtModelReader/txtmodelreader.cpp
            Reader/ModelReader/CsvModelReader/csvmodelreader.h Reader/ModelReader/CsvModelReader/csvmodelreader.cpp
            Reader/ReaderCreator/concretereadercreator.h Reader/ReaderCreator/concretereadercreator.hpp

        )
    endif()
endif()

target_include_directories(lab_03 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Facade
    ${CMAKE_CURRENT_SOURCE_DIR}/Command
    ${CMAKE_CURRENT_SOURCE_DIR}/DrawManager
    ${CMAKE_CURRENT_SOURCE_DIR}/LoadManager
    ${CMAKE_CURRENT_SOURCE_DIR}/TransformManager
    ${CMAKE_CURRENT_SOURCE_DIR}/Object
    ${CMAKE_CURRENT_SOURCE_DIR}/Object/Point
    ${CMAKE_CURRENT_SOURCE_DIR}/Object/Edge
    ${CMAKE_CURRENT_SOURCE_DIR}/SceneManager
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene
    ${CMAKE_CURRENT_SOURCE_DIR}/Reader
    ${CMAKE_CURRENT_SOURCE_DIR}/Reader/ReaderCreator

)

target_link_libraries(lab_03 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab_03)
endif()
set_target_properties(lab_03 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab_03
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab_03)
endif()
