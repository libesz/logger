/*
 * Copyright 2014 Gergo Huszty.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *  Logger.h
 *
 *  Created on: Sep 6, 2014
 *      Author: Gergo Huszty
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <Log.h>
namespace Logger {
  Log &getGlobalLog();
}

#include <string.h>

#define FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOGLEVEL(newLevel) Logger::getGlobalLog().setLogLevel(newLevel)
#define EXPANDABLE(v) Logger::getGlobalLog().setAllowExpandIfTooLong(v)
#define TRACE(text,...) Logger::getGlobalLog().write(Logger::Severity::TRACE,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define DEBUG(text,...) Logger::getGlobalLog().write(Logger::Severity::DEBUG,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define LOG(text,...) Logger::getGlobalLog().write(Logger::Severity::INFO,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define WARN(text,...) Logger::getGlobalLog().write(Logger::Severity::WARN,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define ERR(text,...) Logger::getGlobalLog().write(Logger::Severity::ERR,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)
#define CRIT(text,...) Logger::getGlobalLog().write(Logger::Severity::CRIT,std::string(FILENAME),__LINE__,std::string(text),##__VA_ARGS__)

#endif /* LOGGER_H_ */
