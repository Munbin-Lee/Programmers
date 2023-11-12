from itertools import product

def solution(users, emoticons):
    def check_user_subscription_and_purchase_amount(user, discount_rates):
        min_discount_rate, max_purchase_amount = user
        purchase_amount = 0
        
        for discount_rate, emoticon in zip(discount_rates, emoticons):
            if discount_rate < min_discount_rate: continue
            purchase_amount += emoticon * (100 - discount_rate) / 100
            if purchase_amount >= max_purchase_amount: return [1, 0]
        
        return [0, purchase_amount]
    
    answer = [0, 0]
    
    for discount_rates in product([10, 20, 30, 40], repeat = len(emoticons)):
        tempAnswer = [0, 0]
        
        for user in users:
            subscription, purchase_amount = check_user_subscription_and_purchase_amount(user, discount_rates)
            tempAnswer[0] += subscription
            tempAnswer[1] += purchase_amount
            answer = max(answer, tempAnswer)
    
    return answer