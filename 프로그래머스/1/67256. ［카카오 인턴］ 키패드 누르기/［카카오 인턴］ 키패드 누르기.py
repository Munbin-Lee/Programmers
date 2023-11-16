def solution(numbers, main_hand):
    # 키패드의 위치
    keypad_position_dic = {0 : [3, 1]}
    
    for i in range(9):
        keypad_position_dic[i + 1] = [i // 3, i % 3]
    
    # 각 손의 위치
    hand_position_dic = {
        'L' : [3, 0],
        'R' : [3, 2]
    }
    
    # 숫자별로 눌러야 하는 손
    target_hand_dic = {}
    
    for i in (1, 4, 7):
        target_hand_dic[i] = 'L'
    
    for i in (3, 6, 9):
        target_hand_dic[i] = 'R'
    
    # hand 파싱
    main_hand_dic = {
        "left" : 'L',
        "right" : 'R'
    }
    
    main_hand = main_hand_dic[main_hand]
    other_hand = chr(ord(main_hand) ^ ord('L') ^ ord('R')) 
    
    answer = ""
    
    for number in numbers:
        keypad_position = keypad_position_dic[number]
        
        if number in target_hand_dic:
            hand = target_hand_dic[number]
            hand_position_dic[hand] = keypad_position
            answer += hand
            continue
        
        min_dist = 987654321
        target_hand = ''
        
        for hand in (main_hand, other_hand):
            dy = hand_position_dic[hand][0] - keypad_position[0]
            dx = hand_position_dic[hand][1] - keypad_position[1]
            dist = abs(dy) + abs(dx)
            if dist >= min_dist: continue
            min_dist = dist
            target_hand = hand
        
        hand_position_dic[target_hand] = keypad_position
        answer += target_hand
    
    return answer