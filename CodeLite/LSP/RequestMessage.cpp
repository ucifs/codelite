#include "LSP/RequestMessage.h"
#include <wx/string.h>
#include "JSON.h"
#include "file_logger.h"

LSP::RequestMessage::RequestMessage() { m_id = Message::GetNextID(); }

LSP::RequestMessage::~RequestMessage() {}

JSONItem LSP::RequestMessage::ToJSON(const wxString& name) const
{
    JSONItem json = Message::ToJSON(name);
    json.addProperty("id", GetId());
    json.addProperty("method", GetMethod());
    if(m_params) { json.append(m_params->ToJSON("params")); }
    return json;
}

void LSP::RequestMessage::FromJSON(const JSONItem& json)
{
    // we dont need to un-serialize a request object
    wxUnusedVar(json);
}

wxString LSP::RequestMessage::ToString() const
{
    // Serialize the object and construct a JSON-RPC message
    JSONItem json = ToJSON("");

    wxString data = json.format(false);
    size_t len = data.length();

    // Build the request
    wxString buffer;
    buffer << "Content-Length: " << len << "\r\n";
    buffer << "\r\n";
    buffer << data;
    return buffer;
}

void LSP::RequestMessage::Send(Sender* sender) const
{
    wxString buffer = ToString();
    clDEBUG() << "Sending message to language server:";
    clDEBUG() << buffer;
    sender->Send(buffer);
}
