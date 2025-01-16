#pragma once

enum class KEY
{
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,

	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,

	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	LEFT,
	RIGHT,
	UP,
	DOWN,

	_0,
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,

	NUM0,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	NUM9,

	LSHFT,
	LALT,
	LCTRL,
	SPACE,
	ENTER,
	BACK,
	ESC,
	TAB,

	LBTN,
	RBTN,

	KEY_END,
};

enum class KEY_STATE
{
	TAP,		// �� ����
	PRESSED,	// TAP ���Ŀ��� ��� ��������
	AWAY,		// �� �� ��Ȳ
	NONE,		// �ȴ��� ����
};


struct tKeyInfo
{	
	KEY_STATE	eState;		// ���� Ű ����
	bool		bPrevCheck;	// ���� �����ӿ��� Ű�� ���ȴ��� üũ
};

class CKeyMgr : public Singleton<CKeyMgr>
{
public:
	CKeyMgr(){}
public:
	virtual ~CKeyMgr() override{}
private:
	std::vector<tKeyInfo>	m_vecKey;
public:
	bool Init();
	void update(HANDLE Handle);

public:
	KEY_STATE GetKeyState(KEY _eKey)
	{
		return m_vecKey[(UINT)_eKey].eState;
	}
};

