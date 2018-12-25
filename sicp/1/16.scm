(define (fast-expt b n)
  (fast-expt-iter b n 1))

(define (fast-expt-iter b n p)
  (cond ((= n 0) p)
		((even? n) (fast-expt-iter (* b b) (/ n 2) p))
		(else (fast-expt-iter b (- n 1) (* p b)))))

(fast-expt 2 5)
