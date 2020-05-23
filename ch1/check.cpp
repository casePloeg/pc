#include <iostream>
#include <vector>
#include <array>

using namespace std;

enum players
{
    WHITE,
    BLACK
};

vector<array<int, 2>> get_moves(players p, char piece, array<int, 2> loc, char board[8][8])
{
    int i;
    int j;
    int hit;
    vector<array<int, 2>> moves;

    // rook
    if (tolower(piece) == 'r')
    {
        // go up as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && i > 0)
        {
            if (i - 1 > -1)
            {
                moves.push_back({i - 1, j});
            }
            if (board[i - 1][j] != '.')
            {
                hit = 1;
            }
            i--;
        }
        // go down as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && i < 8)
        {
            if (i + 1 < 9)
            {
                moves.push_back({i + 1, j});
            }
            if (board[i + 1][j] != '.')
            {
                hit = 1;
            }
            i++;
        }
        // go left as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && j > 0)
        {
            if (j - 1 > -1)
            {
                moves.push_back({i, j - 1});
            }
            if (board[i][j - 1] != '.')
            {
                hit = 1;
            }
            j--;
        }
        // go right as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && j < 8)
        {
            if (j + 1 < 9)
            {
                moves.push_back({i, j + 1});
            }
            if (board[i][j + 1] != '.')
            {
                hit = 1;
            }
            j++;
        }
    }
    else if (tolower(piece) == 'b') // bishop
    {
        // go up-left as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && i > 0 && j > 0)
        {
            if (i - 1 > -1 && j - 1 > -1)
            {
                moves.push_back({i - 1, j - 1});
            }
            if (board[i - 1][j - 1] != '.')
            {
                hit = 1;
            }
            i--;
            j--;
        }
        // go down-right as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && i < 8 && j < 8)
        {
            if (i + 1 < 9 && j + 1 < 9)
            {
                moves.push_back({i + 1, j + 1});
            }
            if (board[i + 1][j + 1] != '.')
            {
                hit = 1;
            }
            i++;
            j++;
        }
        // go down-left as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && j > 0 && i < 8)
        {
            if (j - 1 > -1 && i + 1 < 9)
            {
                moves.push_back({i + 1, j - 1});
            }
            if (board[i + 1][j - 1] != '.')
            {
                hit = 1;
            }
            j--;
            i++;
        }
        // go up-right as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && j < 8 && i > 0)
        {
            if (j + 1 < 9 && i - 1 > -1)
            {
                moves.push_back({i - 1, j + 1});
            }
            if (board[i - 1][j + 1] != '.')
            {
                hit = 1;
            }
            j++;
            i--;
        }
    }
    else if (tolower(piece) == 'q') // queen
    {
        // do rook + bishop
        // go up as far as possible
        //r
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && i > 0)
        {
            if (i - 1 > -1)
            {
                moves.push_back({i - 1, j});
            }
            if (board[i - 1][j] != '.')
            {
                hit = 1;
            }
            i--;
        }
        // go down as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && i < 8)
        {
            if (i + 1 < 9)
            {
                moves.push_back({i + 1, j});
            }
            if (board[i + 1][j] != '.')
            {
                hit = 1;
            }
            i++;
        }
        // go left as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && j > 0)
        {
            if (j - 1 > -1)
            {
                moves.push_back({i, j - 1});
            }
            if (board[i][j - 1] != '.')
            {
                hit = 1;
            }
            j--;
        }
        // go right as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && j < 8)
        {
            if (j + 1 < 9)
            {
                moves.push_back({i, j + 1});
            }
            if (board[i][j + 1] != '.')
            {
                hit = 1;
            }
            j++;
        }
        //b

        // go up-left as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && i > 0 && j > 0)
        {
            if (i - 1 > -1 && j - 1 > -1)
            {
                moves.push_back({i - 1, j - 1});
            }
            if (board[i - 1][j - 1] != '.')
            {
                hit = 1;
            }
            i--;
            j--;
        }
        // go down-right as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && i < 8 && j < 8)
        {
            if (i + 1 < 9 && j + 1 < 9)
            {
                moves.push_back({i + 1, j + 1});
            }
            if (board[i + 1][j + 1] != '.')
            {
                hit = 1;
            }
            i++;
            j++;
        }
        // go down-left as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && j > 0 && i < 8)
        {
            if (j - 1 > -1 && i + 1 < 9)
            {
                moves.push_back({i + 1, j - 1});
            }
            if (board[i + 1][j - 1] != '.')
            {
                hit = 1;
            }
            j--;
            i++;
        }
        // go up-right as far as possible
        hit = 0;
        i = loc[0];
        j = loc[1];
        while (hit != 1 && j < 8 && i > 0)
        {
            if (j + 1 < 9 && i - 1 > -1)
            {
                moves.push_back({i - 1, j + 1});
            }
            if (board[i - 1][j + 1] != '.')
            {
                hit = 1;
            }
            j++;
            i--;
        }
    }
    else if (tolower(piece) == 'p') // pawn
    {
        i = loc[0];
        j = loc[1];
        if (p == WHITE && i > 0 && j > 0)
        {
            moves.push_back({i - 1, j - 1});
        }

        if (p == WHITE && i > 0 && j < 8)
        {
            moves.push_back({i - 1, j + 1});
        }

        if (p == BLACK && i < 8 && j > 0)
        {
            moves.push_back({i + 1, j - 1});
        }

        if (p == BLACK && i < 8 && j < 8)
        {
            moves.push_back({i + 1, j + 1});
        }
    }
    else if (tolower(piece) == 'n') // knight
    {
        i = loc[0];
        j = loc[1];
        if (i < 8 && j < 7)
        {
            moves.push_back({i + 1, j + 2});
        }
        if (i < 8 && j > 1)
        {
            moves.push_back({i + 1, j - 2});
        }
        if (i > 0 && j < 7)
        {
            moves.push_back({i - 1, j + 2});
        }
        if (i > 0 && j > 1)
        {
            moves.push_back({i - 1, j - 2});
        }
        if (j < 8 && i < 7)
        {
            moves.push_back({i + 2, j + 1});
        }
        if (j < 8 && i > 1)
        {
            moves.push_back({i - 2, j + 1});
        }
        if (j > 0 && i < 7)
        {
            moves.push_back({i + 2, j - 1});
        }
        if (j > 0 && i > 1)
        {
            moves.push_back({i - 2, j - 1});
        }
    }

    return moves;
}

int main()
{
    int flag = 0;
    // loop until invalid board

    int n = 1;
    while (flag != 1)
    {
        char board[8][8];
        vector<char> w_pieces;
        vector<char> b_pieces;
        vector<array<int, 2>> w_piece_locs;
        vector<array<int, 2>> b_piece_locs;
        array<int, 2> w_king = {-1, -1};
        array<int, 2> b_king = {-1, -1};

        // UPPER CASE : white
        // lower case : black

        string row;
        for (int i = 0; i < 8; i++)
        {
            cin >> row;
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = row[j];
                if (row[j] == 'k')
                {
                    b_king = {i, j};
                }
                else if (row[j] == 'K')
                {
                    w_king = {i, j};
                }
                else if (islower(row[j]))
                {
                    b_pieces.push_back(row[j]);
                    b_piece_locs.push_back({i, j});
                }
                else if (isupper(row[j]))
                {
                    w_pieces.push_back(row[j]);
                    w_piece_locs.push_back({i, j});
                }
            }
        }

        // didn't find a king, break out of loop
        if (b_king[0] == -1)
        {
            flag = 1;
            break;
        }
        // otherwise find checks
        int in_check = -1;

        // check if black in check
        for (int i = 0; i < w_pieces.size(); i++)
        {
            vector<array<int, 2>> moves = get_moves(WHITE, w_pieces[i], w_piece_locs[i], board);
            for (int j = 0; j < moves.size(); j++)
            {
                //cout << "(" << moves[j][0] << ", " << moves[j][1] << ")";
                if (moves[j][0] == b_king[0] && moves[j][1] == b_king[1])
                {
                    in_check = BLACK;
                }
            }
        }
        // check if white in check
        for (int i = 0; i < b_pieces.size(); i++)
        {
            vector<array<int, 2>> moves = get_moves(BLACK, b_pieces[i], b_piece_locs[i], board);
            for (int j = 0; j < moves.size(); j++)
            {
                //cout << "(" << moves[j][0] << ", " << moves[j][1] << ")";
                if (moves[j][0] == w_king[0] && moves[j][1] == w_king[1])
                {
                    in_check = WHITE;
                }
            }
        }

        cout << "Game #" << n << ": ";
        if (in_check == WHITE)
        {
            cout << "white king is in check.";
        }
        else if (in_check == BLACK)
        {
            cout << "black king is in check.";
        }
        else
        {
            cout << "no king is in check.";
        }

        cout << "\n";
        n++;
    }
}