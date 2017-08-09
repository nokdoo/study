(define (get-sqrt guess pre-guess x)
 (cond ((diff guess pre-guess) guess))
  (else (get-sqrt (improve guess x) guess x)))

(define (avr x y)
 (/ (+ x y) 2))

(define (diff guess pre-guess)
	(< (abs (- guess pre-guess)) 0.001)) 

(define (improve guess x)
 (avr guess (/ x guess)))

(define (sqr x)
	(* x x))

(get-sqrt 1.0 0 2)
