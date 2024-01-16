def max_antennas(antennas):
    antennas.sort(key=lambda x: x[1])
    
    count = 0
    last_activated_point = float('-inf')
    
    for antenna in antennas:
        start, end = antenna
        
        if start > last_activated_point:
            count += 1
            last_activated_point = end
    
    return count

