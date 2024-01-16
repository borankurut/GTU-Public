import math

def euclidean_distance(point1, point2):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)

def brute_force_closest_pair(points):
    n = len(points)
    min_distance = float('inf')
    for i in range(n - 1):
        for j in range(i + 1, n):
            distance = euclidean_distance(points[i], points[j])
            min_distance = min(min_distance, distance)
    return min_distance

def closest_pair_helper(sorted_points_by_x, sorted_points_by_y):
    n = len(sorted_points_by_x)

    if n <= 3:
        return brute_force_closest_pair(sorted_points_by_x)

    mid = n // 2
    left_half_x = sorted_points_by_x[:mid]
    right_half_x = sorted_points_by_x[mid:]

    left_half_y = [point for point in sorted_points_by_y if point in left_half_x]
    right_half_y = [point for point in sorted_points_by_y if point in right_half_x]

    left_min_distance = closest_pair_helper(left_half_x, left_half_y)
    right_min_distance = closest_pair_helper(right_half_x, right_half_y)

    delta = min(left_min_distance, right_min_distance)

    mid_x = sorted_points_by_x[mid][0]
    strip = [point for point in sorted_points_by_y if mid_x - delta <= point[0] <= mid_x + delta]

    strip_min_distance = min_strip_distance(strip, delta)

    return min(delta, strip_min_distance)

def min_strip_distance(strip, delta):
    min_distance = delta
    n = len(strip)

    strip.sort(key=lambda point: point[1])

    for i in range(n):
        for j in range(i + 1, min(i + 7, n)):
            distance = euclidean_distance(strip[i], strip[j])
            min_distance = min(min_distance, distance)

    return min_distance

def closest_pair_of_points(points):
    sorted_points_by_x = sorted(points, key=lambda point: point[0])
    sorted_points_by_y = sorted(points, key=lambda point: point[1])

    return closest_pair_helper(sorted_points_by_x, sorted_points_by_y)

