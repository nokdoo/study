
(define (sum term a next b)
	(if (> a b) 0
	(+ (term a) (sum term (next a) next b))))

(define (inc n) (+ n 1))
(define (sum-cubes a b)
	(sum cube a inc b))

(define (cube a)
	(* a a a))

(sum-cubes 1 10)

(define (integral f a b dx)
	(define (add-dx x)
		(+ x dx))
	(* (sum f (+ a (/ dx 2.0)) add-dx b)
		dx))

(integral cube 0 1 0.01)
