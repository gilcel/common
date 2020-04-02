/***************************************************************************
 * Copyright (C) gempa GmbH                                                *
 * All rights reserved.                                                    *
 * Contact: gempa GmbH (seiscomp-dev@gempa.de)                             *
 *                                                                         *
 * GNU Affero General Public License Usage                                 *
 * This file may be used under the terms of the GNU Affero                 *
 * Public License version 3.0 as published by the Free Software Foundation *
 * and appearing in the file LICENSE included in the packaging of this     *
 * file. Please review the following information to ensure the GNU Affero  *
 * Public License version 3.0 requirements will be met:                    *
 * https://www.gnu.org/licenses/agpl-3.0.html.                             *
 *                                                                         *
 * Other Usage                                                             *
 * Alternatively, this file may be used in accordance with the terms and   *
 * conditions contained in a signed written agreement between you and      *
 * gempa GmbH.                                                             *
 ***************************************************************************/


#ifndef __SC_LOGGING_SYSLOG_H__
#define __SC_LOGGING_SYSLOG_H__

#ifndef WIN32

#include <seiscomp/logging/output.h>


namespace Seiscomp {
namespace Logging {


class SC_SYSTEM_CORE_API SyslogOutput : public Output {
	public:
		SyslogOutput();
		SyslogOutput(const char *ident, const char *facility = NULL);
		~SyslogOutput();

		int facility() const { return _facility; }

		bool open(const char *ident, const char *facility = NULL);
		bool isOpen() const;
		void close();

	protected:
		/** Callback method for receiving log messages */
		void log(const char* channelName,
		         LogLevel level,
		         const char* msg,
		         time_t time);

	private:
		bool _openFlag;
		int  _facility;
};


}
}

#endif

#endif