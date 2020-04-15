#include <QtWidgets>
#include "syntaxl.h"


int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QTextEdit    txt;

    QFont fnt("Lucida Console", 9, QFont::Normal);
    txt.document()->setDefaultFont(fnt);

    new SyntaxHighlighter(txt.document());

    QPalette pal = txt.palette();
    pal.setColor(QPalette::Base, Qt::white);
    pal.setColor(QPalette::Text, Qt::red);
    txt.setPalette(pal);

    txt.show();
    txt.resize(800, 600);

    QFile file(":/SyntaxHighlighter.cpp");
    file.open(QFile::ReadOnly);
    txt.setPlainText(QLatin1String(file.readAll()));

    return app.exec();
}
