#ifndef QVIS_SUBSET_WINDOW_H
#define QVIS_SUBSET_WINDOW_H
#include <gui_exports.h>
#include <QvisPostableWindowObserver.h>
#include <vector>

// Forward declarations.
class QComboBox;
class QFrame;
class QGridLayout;
class QLabel;
class QListView;
class QListViewItem;
class QPushButton;
class QPopupMenu;
class QScrollView;
class QSplitter;
class QvisSubsetListView;
class QvisSubsetListViewItem;
class FileServerList;
class avtSIL;

struct SubsetPanel
{
    QFrame             *frame;
    QGridLayout        *layout;
    QvisSubsetListView *lv;
    QLabel             *allSetsLabel;
    QPushButton        *allSetsButton;
    QPushButton        *allSetsActionButton;
    QPopupMenu         *allSetsPopupMenu;
    QLabel             *selectedSetsLabel;
    QPushButton        *selectedSetsButton;
    QPushButton        *selectedSetsActionButton;
    QPopupMenu         *selectedSetsPopupMenu;
};

typedef std::vector<SubsetPanel> SubsetPanelVector;

// ****************************************************************************
// Class: QvisSubsetWindow
//
// Purpose:
//   This class contains the code for the subset window.
//
// Notes:      
//
// Programmer: Brad Whitlock
// Creation:   Thu Jul 5 09:06:29 PDT 2001
//
// Modifications:
//   Brad Whitlock, Tue Aug 21 16:00:21 PST 2001
//   Made the window postable.
//
//   Brad Whitlock, Tue Sep 25 14:30:35 PST 2001
//   Added post(), unpost(), specialResize().
//
//   Brad Whitlock, Fri Feb 8 15:52:11 PST 2002
//   Modified to use a splitter.
//
//   Brad Whitlock, Mon Mar 4 15:12:38 PST 2002
//   Added autoUpdate support.
//
//   Brad Whitlock, Wed Apr 23 14:14:33 PST 2003
//   I changed the interface of ItemClicked.
//
//   Brad Whitlock, Fri Aug 6 13:56:01 PST 2004
//   Made changes that allow multiple sets to be selected.
//
// ****************************************************************************

class GUI_API QvisSubsetWindow : public QvisPostableWindowObserver
{
    Q_OBJECT
public:
    QvisSubsetWindow(Subject *subj,
                     const char *caption = 0,
                     const char *shortName = 0,
                     QvisNotepadArea *notepad = 0);
    virtual ~QvisSubsetWindow();
    virtual void CreateWindowContents();
    virtual void show();
protected:
    virtual void resizeEvent( QResizeEvent *e );
    virtual void UpdateWindow(bool doAll);
    void Apply(bool ignore = false);
    int  AddListView(bool visible = true);
    int  GetNextListViewIndex(QListView *lv);
    int  GetListViewIndex(const QObject *) const;
    void ItemClicked(QvisSubsetListViewItem *item, int nextIndex);
    void ClearListViewsToTheRight(int index);
    void UpdateColumnWidths();
    void UpdateCheckMarks(int lvIndex);
    void TurnOnOff(int, bool, bool);
    void TurnReverse(int, bool);
    void SetButtonEnabledState(int lvIndex, bool val);
    void ChangeSetSelection(int lvIndex, bool checkSelection);
protected slots:
    virtual void post();
    virtual void unpost();
private slots:
    void apply();
    void listviewClicked(QListViewItem *item);
    void listviewChecked(QvisSubsetListViewItem *item);
    void listviewSelectionChanged();
    void specialResize();
    void allSetsClicked();
    void selectedSetsClicked();
    void setAllSetsButtonAction(int);
    void setSelectedSetsButtonAction(int);
private:
    int                  activePane;
    QScrollView         *scrollView;
    SubsetPanelVector    listViews;
    QSplitter           *lvSplitter;

    // A few attributes of the current SIL restriction that we use to
    // determine how the window must be redrawn.
    int                  sil_TopSet;
    int                  sil_NumSets;
    int                  sil_NumCollections;
};

#endif
