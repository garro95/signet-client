#ifndef ACCOUNTACTIONBAR_H
#define ACCOUNTACTIONBAR_H

#include "esdbactionbar.h"

class LoggedInWidget;
class QPushButton;
struct account;
class EditAccount;

#include <QVector>

extern "C" {
#include "signetdev/host/signetdev.h"
}

class LoggedInWidget;

class AccountActionBar : public EsdbActionBar
{
	Q_OBJECT
	EditAccount *m_newAccountDlg;
    void entrySelected(esdbEntry *entry) override;
    void defaultAction(esdbEntry *entry) override;
	QPushButton *m_DeleteButton;
	QPushButton *m_openButton;
	QPushButton *m_loginButton;
	QPushButton *m_browseUrlButton;
	QPushButton *m_typeUsernameButton;
	QPushButton *m_typePasswordButton;
	LoggedInWidget *m_loggedInWidget;

    int esdbType() override;

	bool m_accessUsername;
	bool m_accessPassword;
	bool m_accessPending;

    void newInstanceUI(int id, const QString &name) override;
    bool typeAccountData(account *acct);
    bool copyAccountData(account *acct, bool username, bool password);
	void openAccount(account *acct);

	int m_id;
	int m_signetdevCmdToken;
	enum quickTypeState {
		QUICKTYPE_STATE_INITIAL,
		QUICKTYPE_STATE_BROWSE,
		QUICKTYPE_STATE_LOGIN,
		QUICKTYPE_STATE_USERNAME,
		QUICKTYPE_STATE_PASSWORD
	} m_quickTypeState;

    bool accessEntryComplete(esdbEntry *entry, int intent) override;
	void accessAccountUI(bool typeData, bool username, bool password);
	void accessAccount(account *acct, bool typeData, bool username, bool password);
private slots:
	void entryCreated(esdbEntry *entry);
public:
	AccountActionBar(LoggedInWidget *parent, bool writeEnabled = true, bool typeEnabled = true);
public slots:
	void retryTypeData();
	void newAccountFinished(int);
	void openAccountUI();
	void deleteAccountUI();
	void typeAccountUserUI();
	void typeAccountUserPassUI();
	void typeAccountPassUI();
	void browseUrlUI();
	void copyUsername();
	void copyPassword();
};

#endif // ACCOUNTACTIONBAR_H
