/**
 * @file libobjgen/src/Generator.h
 * @ingroup libobjgen
 *
 * @author COMP Omega <compomega@tutanota.com>
 *
 * @brief Base class for a generator to write source code for an object.
 *
 * This file is part of the COMP_hack Object Generator Library (libobjgen).
 *
 * Copyright (C) 2012-2016 COMP_hack Team <compomega@tutanota.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOBJGEN_SRC_GENERATOR_H
#define LIBOBJGEN_SRC_GENERATOR_H

// Standard C++11 Includes
#include <memory>
#include <string>

namespace libobjgen
{

class MetaObject;
class MetaVariable;

class Generator
{
public:
    virtual std::string Generate(const MetaObject& obj) = 0;

    virtual std::string Tab(size_t count = 1) const;

    virtual std::string GetMemberName(
        const MetaVariable& var) const;
    virtual std::string GetMemberName(
        const std::shared_ptr<MetaVariable>& var) const;

    virtual std::string GetCapitalName(
        const MetaVariable& var) const;
    virtual std::string GetCapitalName(
        const std::shared_ptr<MetaVariable>& var) const;

    static std::string Escape(const std::string& str);
};

} // namespace libobjgen

#endif // LIBOBJGEN_SRC_GENERATOR_H
