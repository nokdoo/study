(define (multi a n)
	(multi-iter a n 0))

(define (multi-iter a n p)
	(cond ((= n 0) p)
		((even? n) (multi-iter (+ a a) (/ n 2) p))
		(else (multi-iter a (- n 1) (+ a p)))))

(multi 3 150000)
