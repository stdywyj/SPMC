#pragma once
/*
 *      Copyright (C) 2011-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include <string>

#include "network/httprequesthandler/HTTPFileHandler.h"

class CHTTPLogHandler : public CHTTPFileHandler
{
public:
  CHTTPLogHandler() { }
  virtual ~CHTTPLogHandler() { }
  
  virtual IHTTPRequestHandler* Create(const HTTPRequest &request) { return new CHTTPLogHandler(request); }
  virtual bool CanHandleRequest(const HTTPRequest &request);

  virtual int GetPriority() const { return 5; }

protected:
  explicit CHTTPLogHandler(const HTTPRequest &request);
};
