import math

def distance(point1, point2):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)

def min_sensors_to_cover(sensors):
    sensors.sort(key=lambda sensor: sensor[0])

    return min_sensors_to_cover_helper(sensors)

def min_sensors_to_cover_helper(sensors):
    n = len(sensors)

    if n == 0:
        return 0
    elif n == 1:
        return 1

    mid = n // 2
    left_half = sensors[:mid]
    right_half = sensors[mid:]

    left_min_sensors = min_sensors_to_cover_helper(left_half)
    right_min_sensors = min_sensors_to_cover_helper(right_half)

    min_sensors = min(left_min_sensors, right_min_sensors)

    dividing_line_x = (left_half[-1][0] + right_half[0][0]) / 2
    boundary_sensors = [sensor for sensor in sensors if dividing_line_x - min_sensors <= sensor[0] <= dividing_line_x + min_sensors]

    boundary_sensors.sort(key=lambda sensor: sensor[1])

    for i in range(len(boundary_sensors)):
        for j in range(i + 1, min(i + 7, len(boundary_sensors))):
            if distance(boundary_sensors[i], boundary_sensors[j]) < min_sensors:
                min_sensors = min(min_sensors, 2)

    return min_sensors

