;(define (sum term a next b)
;	(if (> a b) 0
;	(+ (term a) (sum term (next a) next b))))


;ex1-30
(define (sum term a next b)
	(define (iter a result)
		(cond ((> a b) result)
			(else (iter (next a) (+ result (term a))))))
	(iter a 0))


(define (cube a)
	(* a a a))
(define (inc a)
	(+ a 1))

(define (simpson-integral f a b n)
	(define h (/ (- b a) n))
	(define (y k) (f (+ a (* k h))))
	(define (simpson-term k)
		(* (cond 
			( (or (= k 0) (= k n)) 1)
			((even? k) 2)
			(else 4))
			(y k)))
	(* (/ h 3) (sum simpson-term 0 inc n)))

(simpson-integral cube 0 1 100)

(simpson-integral cube 0 1 1000)
