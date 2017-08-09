 (define (exercise1.3 x y z) 
      (sum (sqr (first x y z)) 
	            (sqr (second x y z)))) 
   
    (define (>= x y) 
	     (not (< x y))) 
	  
	   (define (<= x y) 
	        (not (> x y))) 
	     
		  (define (first x y z) 
		       (cond ((and (>= x y) (>= x z)) x) 
			              ((and (>= y x) (>= y z)) y) 
						             (else z))) 
		    
			 (define (second x y z) 
			      (cond ((or (and (<= x y) (>= x z)) 
				                  (and (>= x y) (<= x z))) x) 
				             ((or (and (<= y x) (>= y z)) 
							                 (and (>= y x) (<= y z))) y) 
							            (else z))) 
			   
			    (define (sqr x) 
				     (* x x)) 
				  
				   (define (sum x y) 
				        (+ x y))

				   (exercise1.3 4 7 9)

