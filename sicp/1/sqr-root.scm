(define (sqr x)
  	(* x x))

(define (avg x y)
  	(/ (+ x y) 2))

(define (good-enough? guess x)
  	(< (abs (- (sqr guess) x)) 0.000000001))



(define (sqr-root x guess)
	(if (good-enough? guess x)
	  	guess
		(sqr-root x (
					 avg guess (
								/ 
								x 
								guess
							   )
					)
		)
	)
)

(sqr-root 0.00001 0.00000001)
