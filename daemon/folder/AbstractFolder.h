/* Copyright (C) 2016 Alexander Shishenko <alex@shishenko.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
#pragma once
#include <librevault/util/bitfield_convert.h>
#include "util/blob.h"
#include "util/Loggable.h"

namespace librevault {

class Client;
class FolderGroup;

class AbstractFolder : public Loggable {
public:
	struct error : std::runtime_error {
		error(const char* what) : std::runtime_error(what) {}
		error() : error("Directory error") {}
	};

	struct no_such_meta : public error {
		no_such_meta() : error("Requested Meta not found"){}
	};

	struct no_such_chunk : public error {
		no_such_chunk() : error("Requested Chunk not found"){}
	};

	AbstractFolder(Client& client);
	virtual ~AbstractFolder();

	// AbstractFolder properties
	const std::string& name() const {return name_;}

	// Other functions
	static std::string path_id_readable(const blob& path_id);
	static std::string ct_hash_readable(const blob& ct_hash);

protected:
	Client& client_;
};

} /* namespace librevault */
