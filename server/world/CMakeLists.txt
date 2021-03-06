# This file is part of COMP_hack.
#
# Copyright (C) 2010-2016 COMP_hack Team <compomega@tutanota.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(comp_world)

MESSAGE("** Configuring ${PROJECT_NAME} **")

# Add a directory to put the objgen output into.
FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/objgen)

INCLUDE_DIRECTORIES(${LIBCOMP_INCLUDES})
INCLUDE_DIRECTORIES(${ASIO_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${TTVFS_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${OPENSSL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${TINYXML2_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/objgen)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)


# Database includes.
INCLUDE_DIRECTORIES(${SQLITE3_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${LIBUV_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CASSANDRA_INCLUDE_DIRS})

SET(${PROJECT_NAME}_SRCS
    src/WorldServer.cpp
    src/main.cpp
)

SET(${PROJECT_NAME}_HDRS
    src/WorldServer.h
)

SET(${PROJECT_NAME}_SCHEMA
    schema/worldconfig.xml
)

OBJGEN_XML(${PROJECT_NAME}_STRUCTS
    # Main schema
    schema/master.xml

    # Included schemas
    ${${PROJECT_NAME}_SCHEMA}

    # Include paths
    schema

    # Output files
    WorldConfig.h
    WorldConfig.cpp
)

SET(${PROJECT_NAME}_PACKETS
)

ADD_EXECUTABLE(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS}
    ${${PROJECT_NAME}_HDRS} ${${PROJECT_NAME}_PACKETS}
    ${${PROJECT_NAME}_STRUCTS})

ADD_DEPENDENCIES(${PROJECT_NAME} asio)

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES FOLDER "Server")

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} comp tinyxml2
    civetweb-cxx civetweb)

UPX_WRAP(${PROJECT_NAME})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)
