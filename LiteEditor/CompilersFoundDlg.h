//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: CompilersFoundDlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef COMPILERSFOUNDDLG_BASE_CLASSES_H
#define COMPILERSFOUNDDLG_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/bannerwindow.h>
#include <wx/dataview.h>
#include "compilersfoundmodel.h"
#include <wx/button.h>

class CompilersFoundDlgBase : public wxDialog
{
protected:
    wxBannerWindow* m_banner10;
    wxDataViewCtrl* m_dataview;
    wxObjectDataPtr<CompilersFoundModel> m_dataviewModel;

    wxStdDialogButtonSizer* m_stdBtnSizer4;
    wxButton* m_buttonCancel;
    wxButton* m_buttonOK;

protected:

public:
    CompilersFoundDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Compilers Found"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~CompilersFoundDlgBase();
};

#endif
