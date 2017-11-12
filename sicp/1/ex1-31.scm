;ex1.31
;pi / 4 = 2/3 * 4/3 * 4/5 * 6/5 * ...
;fibonacci


(define (sum term a next b)
	(define (iter a result)
		(cond ((> a b) result)
			(else (iter (next a) (+ result (term a))))))
	(iter a 0.0))

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

;recursive
;? 구현 방식이 iter밖에 떠오르지 않음...
;공식이 있는거도 아니고...


;iterative
;(define (pi/4 b)
;	(multiply formula 2.0 inc b))



;recursive
;(define (fib b)
;	(cond ((= 0 b) 0)
;		((= 1 b) 1)
;		(else (sum fib (- b 2) inc (- b 1)))))

;iterative
(define (fibonacci b)
	(define (fibo pre_res1 pre_res2 res a b)
		(cond ((= b 0) 0)
			((= b 1) 1)
			((> a b) res)
			(else (fibo pre_res2 res (+ res pre_res2) (inc a) b))))
	(fibo 0 0 1 2 b))

(pi/4 100000)

(fibonacci 150000)
