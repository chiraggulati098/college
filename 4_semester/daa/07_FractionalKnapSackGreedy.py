def KnapSack(items, capacity):
    items.sort(key = lambda x : x[0]/x[1], reverse = True)

    total_value = 0

    for item in items:
        if item[1] <= capacity:
            total_value += item[0]
            capacity -= item[1]
        else:
            total_value += (capacity / item[1]) * item[0] # condition for fractionalKnapSack
            break

    return total_value

items = [(60,10),(100,20),(120,30)] # in form of (profit, weight)
capacity = 50

print(KnapSack(items, capacity))