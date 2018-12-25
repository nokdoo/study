(define (fast-multi a b)
  (fast-multi-iter a b 0))

(define (fast-multi-iter a b p)
  (cond ((= b 0) p)
		((even? b) (fast-multi-iter (* 2 a) (/ b 2) p))
		(else (fast-multi-iter a (- b 1) (+ p a)))))

(fast-multi 3 9)
