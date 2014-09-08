#include "CombatSituationEditor.h"
#include <QMenuBar>
#include <QMenu>

CombatSituationEditor::CombatSituationEditor(QWidget *parent) :
    QMainWindow(parent)
{
    createMenus();
}

void CombatSituationEditor::createMenus()
{
    QMenu* mainMenu = new QMenu("Файл");

    QAction* createAction = mainMenu->addAction("Новая боевая обстановка");
    QAction* openAction = mainMenu->addAction("Открыть...");
    QAction* saveAction = mainMenu->addAction("Сохранить");
    QAction* saveAsAction = mainMenu->addAction("Сохранить как...");
    QAction* exitAction = mainMenu->addAction("Выход");

    QMenu* editMenu = new QMenu("Правка");
    QAction* addTargetAction = editMenu->addAction("Добавить цель в центр");
    QAction* clearTargetsAction = editMenu->addAction("Очистить все цели");

    QMenu* helpMenu = new QMenu("Помощь");

    QAction* aboutAction = helpMenu->addAction("О программе");
    QAction* aboutAuthorsAction = helpMenu->addAction("Об авторах");
    QAction* aboutQtAction = helpMenu->addAction("О Qt");

    QObject::connect(createAction, SIGNAL(triggered()), this, SLOT(onNewCombatSituation()));
    QObject::connect(openAction, SIGNAL(triggered()), this, SLOT(onOpenCombatSituation()));
    QObject::connect(saveAction, SIGNAL(triggered()), this, SLOT(onSaveCombatSituation()));
    QObject::connect(saveAsAction, SIGNAL(triggered()), this, SLOT(onSaveAsCombatSituation()));
    QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(onExit()));

    QObject::connect(addTargetAction, SIGNAL(triggered()), this, SLOT(onAddNewTarget()));
    QObject::connect(clearTargetsAction, SIGNAL(triggered()), this, SLOT(onClearTargets()));

    QObject::connect(aboutAction, SIGNAL(triggered()), this, SLOT(onAbout()));
    QObject::connect(aboutAuthorsAction, SIGNAL(triggered()), this, SLOT(onAboutAuthors()));
    QObject::connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(onAboutQt()));

    QMenuBar* bar = menuBar();

    bar->addMenu(mainMenu);
    bar->addMenu(editMenu);
    bar->addMenu(helpMenu);
}

void CombatSituationEditor::onNewCombatSituation()
{

}

void CombatSituationEditor::onOpenCombatSituation()
{

}

void CombatSituationEditor::onSaveCombatSituation()
{

}

void CombatSituationEditor::onSaveAsCombatSituation()
{

}

void CombatSituationEditor::onExit()
{

}

void CombatSituationEditor::onAddNewTarget()
{

}

void CombatSituationEditor::onClearTargets()
{

}

void CombatSituationEditor::onAbout()
{

}

void CombatSituationEditor::onAboutAuthors()
{

}

void CombatSituationEditor::onAboutQt()
{

}
