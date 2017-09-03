(define (pascal r c)
	(cond ((< r c) #f)
		((= r 1) 1)
		((= r 2) 1)
		((or (= c 1) (= c r)) 1)
		(else (+ (pascal (- r 1) (- c 1)) (pascal (- r 1) c)))))

(pascal 14 7)
