; recursive
(define (f-recur n)
  (cond ((< n 3) n)
		(else (+ 
				(f-recur (- n 1)) 
				(* 2 (f-recur (- n 2))) 
				(* 3 (f-recur (- n 3)))))))

(f-recur 7);


; iterative
(define (f-iter n)
  
  (define (iter a b c i)
	(cond ((> i n) a)
		  (else (iter (+ a (* 2 b) (* 3 c)) a b (+ i 1)))))
  
  (cond ((< n 3) n)
		(else (iter 2 1 0 3))))

(f-iter 7);
