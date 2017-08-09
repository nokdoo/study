(define (sqr x) (* x x))

(define (max1 x y z) 
	(cond 
		((and (> x y) (> x z)) x)
		((and (> y z) (> y z)) y)
		(else z)))

(define (max2 x y z)
	(cond 
		((> x y) (cond 
					((> x z) (cond
								((> y z) y)
								(else z)))
					(else x)))
		((< x y) (cond
					((> y z) (cond
								((> x z) x)
								(else z)))
					(else y)))))

(max1 4 7 9)
(max2 4 7 9)

(define (sum-of-sqr x y z)
	(+ (sqr (max1 x y z)) (sqr (max2 x y z))))

(sum-of-sqr 4 7 9)
