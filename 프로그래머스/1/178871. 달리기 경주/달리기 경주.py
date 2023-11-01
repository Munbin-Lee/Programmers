def solution(players, callings):
    ranks = {player : rank for rank, player in enumerate(players)}
    for calling in callings:
        rank = ranks[calling]
        players[rank - 1], players[rank] = players[rank], players[rank - 1]
        ranks[players[rank]] = rank
        ranks[players[rank - 1]] = rank - 1
    return players