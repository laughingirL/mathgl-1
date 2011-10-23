/***************************************************************************
 *   Copyright (C) 2008 by Alexey Balakin                                  *
 *   mathgl.abalakin@gmail.com                                             *
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
#ifndef UDAV_WND_H
#define UDAV_WND_H
//-----------------------------------------------------------------------------
#include <QMainWindow>
//-----------------------------------------------------------------------------
#ifndef MGL_DOC_DIR
#ifdef WIN32
#define MGL_DOC_DIR ""
#else
#define MGL_DOC_DIR "/usr/local/share/doc/mathgl/"
#endif
#endif
//-----------------------------------------------------------------------------
class QSplitter;
class QTabWidget;
class QMenu;
class QDockWidget;
class DataOpenDialog;
class QTextEdit;
//-----------------------------------------------------------------------------
extern int MaxRecentFiles;
extern int animDelay;
//-----------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *wp=0);
	void load(const QString &fileName, bool noNewWnd=false);

protected:
	void closeEvent ( QCloseEvent* );
	void dropEvent ( QDropEvent* );
	void dragEnterEvent( QDragEnterEvent* );

private slots:
	void newDoc();
	void choose();
	void save();
	void saveAs();
	void addPanel(QWidget *);

	void about();
	void aboutQt();
	void openRecentFile();
	void setAsterix();
	void setCurrentFile(const QString &);
	void setStatus(const QString &txt);

private:
/*	static int num_wnd;
	QTabWidget *ltab, *rtab;
	QSplitter *split;
	QTextEdit *mess;	///< messages and warnings
	QString filename;
	QMenu *fileMenu;
	QDockWidget *messWnd, *calcWnd;
	CalcDialog *calc;	///< Calculator dock window

	void makeMenu();
	void makeDataMenu();
	void readSettings();
	QWidget *setupInfo(QWidget *par);*/
	void updateRecentFileItems();
	void updateRecent();
};
//-----------------------------------------------------------------------------
MainWindow *findMain(QWidget *w);
void raisePanel(QWidget *w);
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
