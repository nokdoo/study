(define (fib n)
	(fib-iter 0 1 n))

(define (fib-iter a b count)
	(cond ((= count 0) a)
		(else (fib-iter b (+ a b) (- count 1)))))

(fib 10)
