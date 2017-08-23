(define (count amount n) (cc amount n))

(define (cc amount kinds)
	(cond 
		((= amount 0) 1)
		((or (< amount 0) (= kinds 0)) 0)
		(else (+ (cc amount (- kinds 1))
					(cc (- amount (kinds-coin kinds)) kinds)))))

(define (kinds-coin n)
	(cond ((= n 1) 1)
		((= n 2) 5)
		((= n 3) 10)
		((= n 4) 25)
		((= n 5) 50)))

(count 10 5)
