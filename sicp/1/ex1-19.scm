(define (fib n)
	(fib-iter 1 0 0 1 n))

(define (fib-iter a b p q cnt)
	(cond ((= cnt 0) b)
		((even? cnt)
			(fib-iter a b (+ (* p p) (* q q)) (+ (* q q) (* 2 p q)) (/ cnt 2)))
		(else (fib-iter (+ (* b q) (* a q) (* a p)) (+ (* b p) (* a q)) p q (- cnt 1)
		))))

(fib 150000)
