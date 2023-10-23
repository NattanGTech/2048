class Case
{
public:
	
	int m_iValeur;
	int m_iPosition;
	char m_iSymbole;

	Case();

	vector<bool> array gridCollision();

	void caseCollision(int direction);
};