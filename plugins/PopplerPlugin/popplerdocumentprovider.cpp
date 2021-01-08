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
#include "popplerdocumentprovider.h"

#include "popplerdocument.h"
#include <poppler-qt5.h>
#include <QUrl>

PopplerDocumentProvider::PopplerDocumentProvider() : DocumentProvider() {

}


Document* PopplerDocumentProvider::documentFor(QUrl filename) {
    Poppler::Document* document = Poppler::Document::load(filename.toLocalFile());
    if (!document) return nullptr;

    return new PopplerDocument(document, filename);
}
