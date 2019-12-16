#pragma once
class Player
{
public:
	Player();
	~Player();

	/// <summary> Ask the user two inputs, one for the row and the other for the colum </summary>
	/// <param="a_Row"> @ref The row </param>
	/// <param="a_Column"> @ref The column </param>
	void AskInput(int& a_Row, int& a_Column);

private:
	char m_token;
};

