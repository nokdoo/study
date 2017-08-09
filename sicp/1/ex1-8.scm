(define (get-sqrt guess x)
 (cond ((diff guess x) guess))
  (else (get-sqrt (improve guess x) x)))

(define (avr x y)
 (/ (+ x y) 2))

(define (diff guess x)
	(< (abs (- (sqr guess) x)) 0.01)) 

(define (improve y x)
 (+ (/ x (* 3 (* y y))) (/ (* 2 y) 3)))

(define (sqr x)
	(* x x))

(get-sqrt 1.0 2)
