/*
   Copyright (C) 2009 by Andrey Borzenkov <arvidjaar at mail.ru>


   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

 */

#ifndef KSYNDAEMON_H
#define KSYNDAEMON_H

#include <KUniqueApplication>
#include <KProcess>

class KSyndaemon : public QObject
{
	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "org.kde.KSyndaemon")

	public:
		KSyndaemon(QObject *parent = NULL);
		~KSyndaemon();

	public Q_SLOTS:
		void setInterval(unsigned i);
		void startMonitoring(void);
		void stopMonitoring(void);

	private:
		unsigned m_interval;
		QString m_cmd;
		KProcess daemon;
};

#endif

