#ifndef TMDOC_H
#define TMDOC_H

#include <QObject>
#include "./tmModel/tmTree.h"
#include "./tmModel/tmCluster.h"
#include <sstream>

class QTextStream;

class tmDoc : public QObject
{
    Q_OBJECT

public:
    tmDoc(QObject* parent = nullptr);
    ~tmDoc();

    tmCluster mSelection;
    tmTree* mTree;
    std::stringstream mCleanState;  // unmodified tree state, serialized

    // Getters
    tmTree* GetTree() const { return mTree; }

    // Selection routines
    template <class P>
    void SetSelection(P* p);
    template <class P>
    void ExtendSelection(P* p, bool wasShiftClick);
    tmNode* ExactlyOneNodeSelected();
    void ClearSelection();
    void GetLeafPathsFromSelection(tmArray<tmPath*>& leafPaths);

    // Command submission
    void SubmitCommand(const QString& name);

    // Save/Load
    bool OnNewDocument();
    bool ReadTreeFromFile(const QString& file);
    bool OnOpenDocument(const QString& file);
    bool OnCloseDocument();
    bool Revert();

    std::ostream& SaveObject(std::ostream& stream);
    void LoadObject(QTextStream& stream);

    // view updating
    void UpdateAllViews();
    void UpdateDocViews();

private:
         // Add any necessary private member variables and functions
};

// Template function definitions
template <class P>
void tmDoc::SetSelection(P* p)
{
    mSelection.ChangeToPart(p);
    UpdateAllViews();
}

template <class P>
void tmDoc::ExtendSelection(P* p, bool wasShiftClick)
{
    if (wasShiftClick) {
        if (!mSelection.Contains(p)) {
            mSelection.AddPart(p);
        }
        else {
            mSelection.RemovePart(p);
        }
    }
    else {
        if (!mSelection.Contains(p)) {
            mSelection.ClearAllParts();
            mSelection.AddPart(p);
        }
    }
    UpdateAllViews();
}

#endif // TMDOC_H
