(define (expt2 b n)
	(expt2-iter b n 1))

(define (expt2-iter b n m)
	(cond ((= n 0) m)
		(else (expt2-iter b (- n 1) (* b m)))))

(define (square n)
	(* n n))

(define (expt3 b n)
	(cond ((= n 0) 1)
		((isEven b) (sqaure (expt3 b (/ n 2))))
		(else (* (expt3 b (- n 1)) b))))

(define (expt4 b n)
	(cond ((isEven b) (expt4 (expt4 b (/ n 2)) 2))
		(else (* (expt4 (expt4 b (/ (- n 1) 2)) b)))))

(define (isEven n)
	(cond ((= (remainder n 2) 0) #t)
		(else #f)))

(define (fast-expt b n)
	(cond ((= n 0) 1)
		((isEven n) (square (fast-expt b (/ n 2))))
		(else (* b (fast-expt b (- n 1))))))

(fast-expt 3 150000)
