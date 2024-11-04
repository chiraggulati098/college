import math 

# Define the Tic-Tac-Toe board 
board = [ 
    [' ', ' ', ' '], 
    [' ', ' ', ' '], 
    [' ', ' ', ' '] 
] 

# Function to print the Tic-Tac-Toe board 
def print_board(board): 
    for row in board: 
        print("|".join(row)) 
        print("-" * 5) 

# Check for winner 
def check_winner(board): 
    # Check rows, columns, and diagonals for a winner 
    for row in board: 
        if row[0] == row[1] == row[2] and row[0] != ' ': 
            return row[0] 
    for col in range(3): 
        if board[0][col] == board[1][col] == board[2][col] and board[0][col] != ' ': 
            return board[0][col] 
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] != ' ': 
        return board[0][0] 
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] != ' ': 
        return board[0][2] 
    return None 

# Check if the board is full (draw condition) 
def is_board_full(board): 
    for row in board: 
        if ' ' in row: 
            return False 
    return True 

# Minimax algorithm with Alpha-Beta pruning 
def minimax(board, depth, is_maximizing, alpha, beta): 
    winner = check_winner(board) 
    if winner == 'X':  # AI wins 
        return 1 
    if winner == 'O':  # Human wins 
        return -1 
    if is_board_full(board):  # Draw 
        return 0 
    if is_maximizing: 
        max_eval = -math.inf 
        for i in range(3): 
            for j in range(3): 
                if board[i][j] == ' ': 
                    board[i][j] = 'X' 
                    eval = minimax(board, depth + 1, False, alpha, beta) 
                    board[i][j] = ' ' 
                    max_eval = max(max_eval, eval) 
                    alpha = max(alpha, eval) 
                    if beta <= alpha: 
                        break 
        return max_eval 
    else: 
        min_eval = math.inf 
        for i in range(3): 
            for j in range(3): 
                if board[i][j] == ' ': 
                    board[i][j] = 'O' 
                    eval = minimax(board, depth + 1, True, alpha, beta) 
                    board[i][j] = ' ' 
                    min_eval = min(min_eval, eval) 
                    beta = min(beta, eval) 
                    if beta <= alpha: 
                        break 
        return min_eval 

# Find the best move for the AI (X) 
def find_best_move(board): 
    best_val = -math.inf 
    best_move = None 
    for i in range(3): 
        for j in range(3): 
            if board[i][j] == ' ': 
                board[i][j] = 'X' 
                move_val = minimax(board, 0, False, -math.inf, math.inf) 
                board[i][j] = ' ' 
                if move_val > best_val: 
                    best_move = (i, j) 
                    best_val = move_val 
    return best_move 

# Function to handle player's move 
def player_move(): 
    while True: 
        row = int(input("Enter row (0-2): ")) 
        col = int(input("Enter column (0-2): ")) 
        if 0 <= row <= 2 and 0 <= col <= 2 and board[row][col] == ' ': 
            board[row][col] = 'O' 
            break 
        else: 
            print("Invalid move. Try again.") 

# Main game loop 
def play_game(): 
    print("Welcome to Tic-Tac-Toe!") 
    print_board(board) 
    while True: 
        # Player (O) move 
        player_move() 
        print_board(board) 
        if check_winner(board): 
            print("O wins!") 
            break 
        if is_board_full(board): 
            print("It's a draw!") 
            break 
        # AI (X) move 
        print("AI's turn (X):") 
        best_move = find_best_move(board) 
        board[best_move[0]][best_move[1]] = 'X' 
        print_board(board) 
        if check_winner(board): 
            print("X wins!") 
            break 
        if is_board_full(board): 
            print("It's a draw!") 
            break 

# Start the game 
play_game() 
