(prog
START
(setq n (readL "1.sum\n2.sub\n3.mul\n4.exit\nEnter n:"))
(setq a (readL "Enter a:"))
(setq b (readL "Enter b:"))
(if (= n 1) (setq result (+ a b)))
(if (= n 2) (setq result (- a b)))
(if (= n 3) (setq result (* a b)))
(if (= n 4) (return 1))
(print result)
(goto START)
)
