%from canakkale
schedule(canakkale, erzincan, 6).
schedule(canakkale, tekirdag, 3).

%from erzincan
schedule(erzincan, canakkale, 6).
schedule(erzincan, antalya, 3).

%from antalya
schedule(antalya, erzincan, 3).
schedule(antalya, izmir, 2).
schedule(antalya, diyarbakir, 4).

%from diyarbakir
schedule(diyarbakir, ankara, 8).
schedule(diyarbakir, antalya, 4).

%from ankara
schedule(ankara, istanbul, 1).
schedule(ankara, izmir, 6).
schedule(ankara, diyarbakir, 8).
schedule(ankara, van, 4).
schedule(ankara, rize, 5).

%from izmir
schedule(izmir, istanbul, 2).
schedule(izmir, ankara, 6).
schedule(izmir, antalya, 2).

%from istanbul
schedule(istanbul, izmir, 2).
schedule(istanbul, ankara, 1).
schedule(istanbul, rize, 4).
schedule(istanbul, tekirdag, 2).
schedule(istanbul, bursa, 3).

%from tekirdag
schedule(tekirdag, istanbul, 2).
schedule(tekirdag, canakkale, 3).

%from rize
schedule(rize, ankara, 5).
schedule(rize, istanbul, 4).

%from van
schedule(van, gaziantep, 3).

%from bursa
schedule(bursa, istanbul, 3).

%from gaziantep
schedule(gaziantep, van, 3).

% Base case: Directly scheduled.
connection(X, Y, C) :- schedule(X, Y, C).   %% there is connection if scheduled.

% Recursive: There is some non-visited city between x and y.
connection(X, Y, C) :-
    connection(X, Z, C1, [X]),      %% x is visited, check if there is a connection when x is visited.
    connection(Z, Y, C2, [X]),
    C is C1 + C2.                   %% cost is the sum.

% Keep track of the visited cities
connection(X, Y, C, Visited) :-
    schedule(X, Y, C),
    \+ member(Y, Visited).      %% base case and y is not visited so there is a connection.
connection(X, Y, C, Visited) :- 
    schedule(X, Z, C1),
    \+ member(Z, Visited),
    connection(Z, Y, C2, [Z|Visited]),  
    C is C1 + C2.   %%  recursive case, z hadn't visited, 
                    %%  there is a connection if there is a connection when z is visited.
                    %%  cost is the sum.