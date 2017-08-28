(define (f n)
	(cond ((< n 3) n)
		(else (+ (f (- n 1)) (* 2 (f (- n 2))) (* 3 (f (- n 3)))))))

(f 0)
(f 1)
(f 2)
(f 3)
(f 4)
(f 5)

(define (f2 n)
	(cond ((= n 0) 0)
		((= n 1) 1)
		((= n 2) 2)
		(else (f2-iter (f2 2) (f2 1) (f2 0) 3 n))))

(define (f2-iter c b a cnt n)
	(cond ((= cnt n) (f2-val c b a))
		(else (f2-iter (f2-val c b a) c b (+ cnt 1) n))))

(define (f2-val c b a)
	(+ c (* 2 b) (* 3 a)))






(f2 0)
(f2 1)
(f2 2)
(f2 3)
(f2 4)
(f2 5)
