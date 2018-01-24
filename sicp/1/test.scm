(lambda (x) (+ x 4))

(lambda (x) (/ 1.0 (* x (+ x 2))))

(define (pi-sum a b)
	(sum (lambda (x) (/ 1.0 (* x (+ x 2))))
		a
		(lambda (x) (+ x 4))
		b))

(pi-sum 2 4)
