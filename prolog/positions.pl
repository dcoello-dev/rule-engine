:- dynamic
      position/3.

range(1, 1).

is_close_to(X, Y, P) :-
    position(P, K, J),
    range(R1, R2),
    K >= X - R1,
    J >= Y - R2,
    K =< X + R1,
    J =< Y + R2.

collision_alert(T1, T2) :-
    position(T1, X, Y),
    is_close_to(X, Y, T2),
    not(T1=@=T2).

add_POI(T, X, Y) :-
    retractall(position(T, _, _)),
    assertz(position(T, X, Y)).