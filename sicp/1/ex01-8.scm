(define (sqr x)
  	(* x x))

(define (cube x)
  	(* x x x))

(define (improve x guess)
  	(/ (+ (/ x (sqr guess))
		  (* 2 guess))
	   3))

(define (good-enough? x guess)
  	(< (abs (- (cube guess) x)) 0.00001))



(define (cube-root x guess)
	(if (good-enough? x guess)
	  	guess
		(cube-root x (improve x guess))
	)
)

(cube-root 27 1)
