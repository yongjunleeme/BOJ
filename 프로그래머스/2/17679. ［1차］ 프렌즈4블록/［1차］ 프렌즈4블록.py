def solution(m, n, board):
    board = [list(i) for i in board]    
    # 1) 일치여부판별
    # 2) 일치 위치 삭제
    # 3) 빈공간 블럭 처리
    matched = True
    while matched:
        matched = []
        for i in range(m-1):
            for j in range(n-1):
                if board[i][j] == board[i][j+1] == board[i+1][j] == board[i+1][j+1] != '#':
                    matched.append([i, j])
        
        for i, j in matched:
            board[i][j] = board[i][j+1] = board[i+1][j] = board[i+1][j+1] = '#'
            
        for _ in range(m):
            for i in range(m-1):
                for j in range(n):
                    if board[i+1][j] == '#':
                        board[i+1][j], board[i][j] = board[i][j], '#'
                        
    return sum(i.count('#') for i in board)
    
                
            