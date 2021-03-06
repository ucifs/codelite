#ifndef LANGUAG_ESERVER_PROTOCOL_H
#define LANGUAG_ESERVER_PROTOCOL_H

#include "codelite_exports.h"
#include "asyncprocess.h"
#include "cl_command_event.h"
#include "LSP/clJSONRPC.h"
#include <wxStringHash.h>
#include <wx/sharedptr.h>
#include "macros.h"
#include <map>
#include "LSP/RequestMessage.h"

class WXDLLIMPEXP_SDK LanguageServerProtocol : public LSP::Sender
{
    IProcess* m_process = NULL;
    wxString m_command;
    wxString m_workingDirectory;
    bool m_goingDown = false;
    wxStringSet_t m_filesSent;
    wxStringSet_t m_languages;
    std::unordered_map<int, LSP::RequestMessage::Ptr_t> m_requestsSent;
    wxString m_outputBuffer;

public:
    typedef wxSharedPtr<LanguageServerProtocol> Ptr_t;

protected:
    void OnProcessTerminated(clProcessEvent& event);
    void OnProcessOutput(clProcessEvent& event);
    void OnProcessStderr(clProcessEvent& event);
    void OnFileLoaded(clCommandEvent& event);
    void OnFileClosed(clCommandEvent& event);
    void OnFileSaved(clCommandEvent& event);

protected:
    void DoClear();

    static wxString GetLanguageId(const wxFileName& fn) { return GetLanguageId(fn.GetFullName()); }
    static wxString GetLanguageId(const wxString& fn);

protected:
    /**
     * @brief notify about file open
     */
    void FileOpened(const wxFileName& filename, const wxString& fileContent, const wxString& languageId);

    /**
     * @brief report a file-close notification
     */
    void FileClosed(const wxFileName& filename);

    /**
     * @brief report a file-changed notification
     */
    void FileChanged(const wxFileName& filename, const wxString& fileContent);

    /**
     * @brief report a file-save notification
     */
    void FileSaved(const wxFileName& filename, const wxString& fileContent);

    void DoStart();

public:
    LanguageServerProtocol();
    virtual ~LanguageServerProtocol();

    /**
     * @brief return list of all supported languages by LSP. The list contains the abbreviation entry and a description
     */
    static const std::set<wxString>& GetSupportedLanguages();
    bool CanHandle(const wxFileName& filename) const;

    /**
     * @brief pure method
     */
    virtual void Send(const wxString& message);

    /**
     * @brief start a server for an executable
     */
    void Start(const wxString& command, const wxString& workingDirectory, const wxArrayString& languages);

    /**
     * @brief is the LSP running?
     */
    bool IsRunning() const;

    /**
     * @brief stop the language server
     */
    void Stop(bool goingDown);

    /**
     * @brief restart the server. If the server is not running, start it
     */
    void Restart();

    /**
     * @brief find definition of a word.
     * @param filename the filename
     * @param line the current caret line (0 based)
     * @param column the current caret column (0 based)
     */
    void FindDefinition(const wxFileName& filename, size_t line, size_t column);
};

#endif // CLLANGUAGESERVER_H
