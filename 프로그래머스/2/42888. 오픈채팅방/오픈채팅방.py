def solution(records):
    nicknameDict = {}
    history = []
    
    for record in records:
        record = record.split()
        cmd = record[0]
        id = record[1]
        if cmd == "Enter" or cmd == "Leave":
            history.append([cmd, id])
        if cmd == "Enter" or cmd == "Change":
            nicknameDict[id] = record[2]
    
    answer = []
    cmdDict = {
        "Enter" : "님이 들어왔습니다.",
        "Leave" : "님이 나갔습니다."
    }
    
    for cmd, id in history:
        log = f"{nicknameDict[id]}{cmdDict[cmd]}"
        answer.append(log)
    
    return answer