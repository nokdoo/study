(define (get-sqrt guess x)
 (cond ((diff guess x) guess))
  (else (get-sqrt (improve guess x) x)))

(define (avr x y)
 (/ (+ x y) 2))

(define (diff guess x)
	(< (abs (- (sqr guess) x)) 0.01)) 

(define (improve guess x)
 (avr guess (/ x guess)))

(define (sqr x)
	(* x x))

(get-sqrt 1.0 2)
