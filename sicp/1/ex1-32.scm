;ex1.32

;(define (sum term a next b)
;	(define (iter a result)
;		(cond ((> a b) result)
;			(else (iter (next a) (+ result (term a))))))
;	(iter a 0.0))

;요기
(define (sum term a next b)
	(accumulate + 0 term a next b))

(define (multiply func a next b)
	(define (iter a result)
		(cond ((> a b) result)
			(else (iter (next a) (* result (func a))))))
	(iter a 1.0))

(define (inc a)
	(+ a 1))

(define (formula a)
	(cond ((even? a) (/ a (+ a 1.0)))
		(else (/ (+ a 1.0) a))))

(define (pi/4 b)
	(multiply formula 2.0 inc b))

(define (fibonacci b)
	(define (fibo pre_res1 pre_res2 res a b)
		(cond ((= b 0) 0)
			((= b 1) 1)
			((> a b) res)
			(else (fibo pre_res2 res (+ res pre_res2) (inc a) b))))
	(fibo 0 0 1 2 b))

;;요기
;;recursive
;(define (accumulate combiner null-value term a next b)
;	(cond ((> a b) null-value)
;		(else (combiner (term a) (accumulate combiner null-value term (next a) next b)))))

;iterative
(define (accumulate combiner null-value term a next b)
	(define (iter a result)
		(cond ((> a b) result)
			(else (iter (next a) (combiner result (term a))))))
	(iter a null-value))


(pi/4 100000)

(fibonacci 150000)
