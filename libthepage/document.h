/****************************************
 *
 *   INSERT-PROJECT-NAME-HERE - INSERT-GENERIC-NAME-HERE
 *   Copyright (C) 2021 Victor Tran
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * *************************************/
#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>

class Page;
class QIODevice;
class Document : public QObject {
        Q_OBJECT
    public:
        explicit Document();

        enum DRMLimitation {
            Copy,
            Print,
            Edit,
            FillForm
        };

        virtual QUrl fileName() = 0;

        virtual Page* page(int pageNumber) = 0;
        virtual int pageCount() = 0;

        virtual QString title() = 0;

        virtual bool requiresPassword() = 0;
        virtual bool providePassword(QString password) = 0;

        virtual bool save(QIODevice* device) = 0;

        virtual bool isDrmEnforced(DRMLimitation limitation) = 0;

    signals:

};

#endif // DOCUMENT_H
