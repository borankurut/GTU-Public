%% A room has an ID, capacity (how many people it can hold), and operations hours given in
%% one-hour increments from 8am until 5pm. Occupancy information for a room includes the
%% hour and the name of the course taking that hour. A room can also have special equipment
%% such as a projector, a smart board and access for the handicapped.

room(r1, 100, [8, 9, 10, 11, 12, 13, 14, 15, 16, 17], [projector, smart_board], [handicapped]).
room(r2, 30, [8, 9, 10, 11, 12, 13, 14, 15, 16, 17], [projector], []).
room(r3, 40, [8, 9, 10, 11, 12, 13, 14, 15, 16, 17], [], [handicapped]).

%% A course has an ID, an instructor, capacity, and one or more hours and the room information
%% if they are assigned to a room. A course can have several students enrolled in it. A course can
%% also have special needs such as a projector or a smart board. Of course, if there is a special
%% needs student enrolled, it should be assigned to a room with proper access for the special
%% needs.

course(c1, i1, 40, [[9, 10], [11, 12]], r1, [projector]).
course(c2, i2, 30, [[9, 10], [11, 12]], r2, []).
course(c3, i3, 20, [[13, 14], [15, 16]], r3, [smart_board]).

%% An instructor has an ID and several courses taught. The instructor may have preferences for
%% rooms with a projector or smartboard.

instructor(i1, [c1], [projector]).
instructor(i2, [c2], []).
instructor(i3, [c3], [smart_board]).

%% A student has an ID, and list of courses she/he attends. A student can also be handicapped.

student(s1, [c1], false).
student(s2, [c1, c2], false).
student(s3, [c2], true).
student(s4, [c3], false).
student(s5, [c3], true).

% Check for scheduling conflict
conflict(C1, C2) :-
	course(C1, _, _, Times1, _, _),
	course(C2, _, _, Times2, _, _),
	member(Time, Times1),
	member(Time, Times2).

% Check if all members of a list are in another list
all_members_in_list([Head|Tail], List) :-
    member(Head, List),
    all_members_in_list(Tail, List).

% Check which room can be assigned to a given class
assignable_room(Course, Room) :-
    course(Course, _, CourseCapacity, [Times, Times2], _, Needs),
    room(Room, RoomCapacity, Hours, RoomEquipment, _),
    RoomCapacity >= CourseCapacity,
    all_members_in_list(Times, Hours),
    all_members_in_list(Times2, Hours),
    all_members_in_list(Needs, RoomEquipment).

% Check which rooms can be assigned to given course
assignable_rooms(Course) :-
    findall(Room, assignable_room(Course, Room), Rooms),
    write(Rooms).

% Check whether a student can be enrolled in a given class
enrollable(Student, Course) :-
	student(Student, _, Handicapped),
	course(Course, _, _, _, Room, _),
	room(Room, _, _, _, Access),
	(Handicapped = false; member(handicapped, Access)).

% Check which classes a student can be assigned
assignable_classes(Student, Classes) :-
	findall(Course, enrollable(Student, Course), Classes).

%% Helpers

% Check if all members of a list are in another list
all_members_in_list([H|T], L) :-
    member(H, L),
    all_members_in_list(T, L).

% New student
add_student(ID, Courses, Handicapped) :-
	assert(student(ID, Courses, Handicapped)).

% New course
add_course(ID, Instructor, Capacity, Times, Room, Needs) :-
	assert(course(ID, Instructor, Capacity, Times, Room, Needs)).

% New room
add_room(ID, Capacity, Hours, Equipment, Access) :-
	assert(room(ID, Capacity, Hours, Equipment, Access)).