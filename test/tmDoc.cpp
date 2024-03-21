#include "tmDoc.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "./tmModel/tmPath.h"
#include "./tmModel/tmNode.h"

tmDoc::tmDoc(QObject* parent)
    : QObject(parent), mTree(nullptr)
{
    mTree = tmTree::MakeTreeBlank();
    mTree->PutSelf(mCleanState);
}

tmDoc::~tmDoc()
{
    if (mTree) delete mTree;
}

tmNode* tmDoc::ExactlyOneNodeSelected()
{
    if (mSelection.GetNumAllParts() != 1) return nullptr;
    if (mSelection.GetNumParts<tmNode>() != 1) return nullptr;
    return mSelection.GetNodes().front();
}

void tmDoc::ClearSelection()
{
    mSelection.ClearAllParts();
    UpdateAllViews();
}

void tmDoc::GetLeafPathsFromSelection(tmArray<tmPath*>& leafPaths)
{
    leafPaths.clear();
    tmPath::FilterLeafPaths(leafPaths, mSelection.GetPaths());
    if (leafPaths.empty()) {
        tmArray<tmNode*> leafNodes;
        tmNode::FilterLeafNodes(leafNodes, mSelection.GetNodes());
        if (leafNodes.size() == 2)
            leafPaths.push_back(mTree->GetLeafPath(leafNodes[0], leafNodes[1]));
    }
}

void tmDoc::SubmitCommand(const QString& /*name*/)
{
    // Implement command submission logic
    UpdateAllViews();
}

bool tmDoc::OnNewDocument()
{
    // Implement new document creation logic
    return true;
}

bool tmDoc::ReadTreeFromFile(const QString& file)
{
    QFile fin(file);
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "File Read Error", "Could not open file " + file);
        return false;
    }
    QTextStream stream(&fin);
    try {
        LoadObject(stream);
    }
    catch (const tmTree::EX_IO_BAD_TREE_TAG& exc) {
        QMessageBox::critical(nullptr, "File Read Error", "This file doesn't look like a TreeMaker file: (initial tag = " + QString::fromStdString(exc.mToken) + ")");
        return false;
    }
    catch (const tmTree::EX_IO_BAD_TREE_VERSION& exc) {
        QMessageBox::critical(nullptr, "File Read Error", "This file has an unrecognized (possibly newer) version than this program can read: (version = " + QString::fromStdString(exc.mToken) + ")");
        return false;
    }
    catch (const tmTree::EX_IO_BAD_REF_INDEX& exc) {
        QMessageBox::critical(nullptr, "File Read Error", "This file appears to be corrupted (bad reference index = " + QString::fromStdString(exc.mToken) + ")");
        return false;
    }
    catch (const tmTree::EX_IO_BAD_TAG& exc) {
        QMessageBox::critical(nullptr, "File Read Error", "This file appears to be corrupted (bad object tag size: tag = " + QString::fromStdString(exc.mToken) + ")");
        return false;
    }
    catch (const tmTree::EX_IO_UNRECOGNIZED_TAG& exc) {
        QMessageBox::critical(nullptr, "File Read Error", "This file appears to be corrupted (unrecognized object tag: tag = " + QString::fromStdString(exc.mToken) + ")");
        return false;
    }
    catch (const tmTree::EX_IO_TOO_LONG_STRING& exc) {
        QMessageBox::critical(nullptr, "File Read Error", "Text label " + QString::fromStdString(exc.mToken) + " in this file was too long");
        return false;
    }
    catch (const tmTree::EX_IO_BAD_ESCAPE& exc) {
        QMessageBox::critical(nullptr, "File Read Error", "A text label contained a bad escape sequence: (" + QString::fromStdString(exc.mToken) + ")");
        return false;
    }
    catch (const tmTree::EX_IO_BAD_TOKEN& exc) {
        QMessageBox::critical(nullptr, "File Read Error", "A bad token (" + QString::fromStdString(exc.mToken) + ") was found. File corrupted.");
        return false;
    }
    catch (...) {
        QMessageBox::critical(nullptr, "File Read Error", "An unhandled exception was thrown. Please report this bug to the TreeMaker development team.");
        return false;
    }
    return true;
}

bool tmDoc::OnOpenDocument(const QString& file)
{
    if (!ReadTreeFromFile(file)) return false;
    // Implement additional logic for opening a document
    UpdateAllViews();
    return true;
}

bool tmDoc::OnCloseDocument()
{
    // Implement logic for closing a document
    return true;
}

bool tmDoc::Revert()
{
    // Implement logic for reverting to the last saved version
    return true;
}

std::ostream& tmDoc::SaveObject(std::ostream& stream)
{
    mTree->PutSelf(stream);
    return stream;
}

void tmDoc::LoadObject(QTextStream& stream)
{
    tmTree* theTree = new tmTree();
    try {
        QString qString = stream.readAll();
        std::string stdString = qString.toStdString();
        std::istringstream stdStream(stdString);
        theTree->GetSelf(stdStream);
    }
    catch (const tmTree::EX_IO_UNRECOGNIZED_CONDITION& exc) {
        QMessageBox::information(nullptr, "Unrecognized Conditions", "There were " + QString::number(exc.mNumMissed) + " unrecognized conditions. They will be ignored.");
    }
    delete mTree;
    mTree = theTree;
    mCleanState.str("");
    mTree->PutSelf(mCleanState);
}


void tmDoc::UpdateAllViews()
{
    // Implement logic for updating all views
}

void tmDoc::UpdateDocViews()
{
    // Implement logic for updating only document views
}
