(define (sqr x) (* x x))

(define (sum-of-sqr x y) (+ (sqr x) (sqr y)))

(define (example x y z)
  	(if 
	  	(and (> x z) (> y z)) 
		(sum-of-sqr x y)
	    (if (and (> x y) (> z y)) 
		    (sum-of-sqr x z)
		    (else 
				(sum-of-sqr y z)))))

(example 12 2 3)
