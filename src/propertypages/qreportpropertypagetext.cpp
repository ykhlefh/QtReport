/***************************************************************************
 *   QtReport                                                              *
 *   Qt Report Builder Soultion                                            *
 *                                                                         * 
 *   Copyright (C) 2010 by Hamed Masafi                                    *
 *   Hamed.Masafi@GMail.COM                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "qreportdocumentdesigner.h"
#include "propertypages/qreportpropertypagetext.h"
#include "widgets/qreporttextbox.h"

LEAF_BEGIN_NAMESPACE

LReportPropertyPageText::LReportPropertyPageText(QWidget *parent) :
    LReportPropertyPageBase(parent)
{
    setupUi(this);
    _title = tr( "Text" );
}

void LReportPropertyPageText::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void LReportPropertyPageText::load()
{
   textEdit->setPlainText(_designer->widgetProperty("text").toString());
}

void LReportPropertyPageText::save()
{
   _designer->setWidgetProperty("text", textEdit->toPlainText());
}

LEAF_END_NAMESPACE
