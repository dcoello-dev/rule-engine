position("casa", 3, 3).
position("curro", 1, 1).

range(1, 1).

is_close_to(X, Y, P) :-
    position(P, K, J),
    range(R1, R2),
    K >= X - R1,
    J >= Y - R2,
    K =< X + R1,
    J =< Y + R2.