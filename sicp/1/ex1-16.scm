(define (fast-expt2 b n)
	(fast-expt2-iter b n 1 ))

(define (fast-expt2-iter b n ex)
	(cond ((= n 0) ex)
		((even? n) (fast-expt2-iter (* b b) (/ n 2) ex))
		(else (fast-expt2-iter b (- n 1) (* ex b)))))

(fast-expt2 3 5)
