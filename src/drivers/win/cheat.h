//--
//mbg merge 7/18/06 had to make these extern
#ifndef WIN_CHEAT_H
#define WIN_CHEAT_H
extern int CheatWindow,CheatStyle; //bbit edited: this line added
extern HWND hCheat;

HWND InitializeCheatList(HWND hwndDlg);
void RedoCheatsLB(HWND hwndDlg);

typedef unsigned int HWAddressType;


void ConfigCheats(HWND hParent);
void DoGGConv();
void SetGGConvFocus(int address,int compare);
void UpdateCheatList();
void UpdateCheatListGroupBoxUI();
void UpdateCheatsAdded();
void ToggleCheatInputMode(HWND hwndDlg, int modeId);
void GetUICheatInfo(HWND hwndDlg, char* name, uint32* a, uint8* v, int* c);
inline void GetCheatStr(char* buf, int a, int v, int c);

extern unsigned int FrozenAddressCount;
extern std::vector<uint16> FrozenAddresses;
//void ConfigAddCheat(HWND wnd); //bbit edited:commented out this line
extern struct CHEATF* cheats;

void DisableAllCheats();
bool ShowCheatFileBox(HWND hwnd, char* buf, bool save = false);
void AskSaveCheat();
void SaveCheatAs(HWND hwnd, bool flush = false);

void UpdateCheatRelatedWindow();
extern POINT CalcSubWindowPos(HWND hDlg, POINT* conf);

extern BOOL CALLBACK GGConvCallB(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
extern WNDPROC DefaultGGConvWndProc;
extern LRESULT APIENTRY GGConvCustomWndProc(HWND hDlg, UINT msg, WPARAM wP, LPARAM lP);


// deselect the old one and select the new one
#define ListView_MoveSelectionMark(hwnd, prevIndex, newIndex) \
LVITEM lvi; \
SendMessage(hwnd, LVM_SETITEMSTATE, prevIndex, (LPARAM)&(lvi.mask = LVIF_STATE, lvi.stateMask = LVIS_SELECTED, lvi.state = 0, lvi)), \
SendMessage(hwnd, LVM_SETITEMSTATE, newIndex, (LPARAM)&(lvi.state = LVIS_SELECTED, lvi)), \
SendMessage(hwnd, LVM_SETSELECTIONMARK, 0, newIndex)

#define ClearCheatListText(hwnd) \
(SetDlgItemText(hwnd, IDC_CHEAT_ADDR, (LPTSTR)"") & \
SetDlgItemText(hwnd, IDC_CHEAT_VAL, (LPTSTR)"") & \
SetDlgItemText(hwnd, IDC_CHEAT_COM, (LPTSTR)"") & \
SetDlgItemText(hwnd, IDC_CHEAT_NAME, (LPTSTR)"") & \
SetDlgItemText(hwnd, IDC_CHEAT_TEXT, (LPTSTR)""))

#endif