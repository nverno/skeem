(define (assert x) (if (not x)
		       (exit 1)))
(assert (equal? 1 1))
(assert (equal? 2 (+ 1 1)))
(assert (equal? 0 (- 1 1)))
(assert (equal? 4 (* 2 2)))
