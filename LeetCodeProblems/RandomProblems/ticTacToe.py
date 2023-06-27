'''
    algorithm: 
        check if all rows or all columns are of the same char. 
        if yes, detect who wins. 
            if 'x' then A else then B
        if no, see if the size == 9 -> then draw
            else then the game is still in progress. 
'''
import numpy as np
moves = [[0, 0], [1, 1], [0, 1], [0, 2], [1, 0], [2, 0]]
gameBoard = np.full((3, 3), '.')
xTurn = True
xCounter = 0
oCounter = 0
# build the board
for move in moves:
    if xTurn:
        gameBoard[move[0]][move[1]] = 'X'
        xCounter += 1
    else:
        gameBoard[move[0]][move[1]] = 'O'
        oCounter += 1
    xTurn = not xTurn


# check diagonals
if (gameBoard[0][0] == 'O') and (gameBoard[1][1] == 'O') and (gameBoard[2][2] == 'O'):
    print('B')
elif (gameBoard[0][0] == 'X') and (gameBoard[1][1] == 'X') and (gameBoard[2][2] == 'X'):
    print('A')
elif (gameBoard[0][2] == 'X') and (gameBoard[1][1] == 'X') and (gameBoard[2][0] == 'X'):
    print('A')
elif (gameBoard[0][2] == 'O') and (gameBoard[1][1] == 'O') and (gameBoard[2][0] == 'O'):
    print('B')


# check on all rows and all columns
for i in range(3):
    # check on each row
    if all(gameBoard[i, :] == 'X') or all(gameBoard[:, i] == 'X'):
        print('A')
    elif all(gameBoard[i, :] == 'O') or all(gameBoard[:, i] == 'O'):
        print('B')

# if we reached here, then either draw, or the game in progress
if(xCounter + oCounter == 9):
    print('Draw')
else:
    print('Pending')
