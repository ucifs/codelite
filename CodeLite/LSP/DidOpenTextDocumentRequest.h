#ifndef DIDOPENTEXTDOCUMENTREQUEST_H
#define DIDOPENTEXTDOCUMENTREQUEST_H

#include "RequestMessage.h"
#include <wx/filename.h>

namespace LSP
{

class WXDLLIMPEXP_CL DidOpenTextDocumentRequest : public LSP::RequestMessage
{
public:
    DidOpenTextDocumentRequest(const wxFileName& filename, const wxString& text, const wxString& langugage);
    virtual ~DidOpenTextDocumentRequest();
};

} // namespace LSP

#endif // DIDOPENTEXTDOCUMENTREQUEST_H
