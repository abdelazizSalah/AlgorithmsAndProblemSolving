money = [5, 5, 5, 10, 20]
money2 = [5, 5, 10, 10, 20]
mp = {5: 0, 10: 0}
'''
    algorithm :
    ana fl awl hshof hwa hydf3 kam :
        5-> increment # of 5 el m3aya w continue
        10 -> hal ana m3aya 5-at? lw ahh,
             yeb2a hzwd 3dd el 10 w an2s el 5 w cont
        20 -> hena 3ndna multiple cases: 
            mehtag yekon m3aya ema 1 -> 10 && 1 -> 5 
            aw ykon m3aya 3 -> 5
'''
for coin in money2:
    if coin == 5:
        mp[coin] += 1
    elif coin == 10:
        if mp[5] >= 1:
            mp[5] -= 1
            mp[10] += 1
        else:
            exit(-1)
    else:
        if (mp[10] >= 1):
            if(mp[5] >= 1):
                mp[5] -= 1
                mp[10] -= 1
            else:
                exit(-1)
        elif (mp[5] >= 3):
            mp[5] -= 3
        else:
            exit(-1)
print(True)
