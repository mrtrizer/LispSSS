defun test_fun (a b)
{
	return (+ a b);
};

defun funfun (a b) (+ a b);

defun main ()
{
	while (T)
	{
		setq n (readL "1.sum\n2.sub\n3.mul\n4.exit\nEnter n:");
		setq a (readL "Enter a:");
		setq b (readL "Enter b:");
		if (= n 1)
		{
			setq result (test_fun a b);
			print "Hello, Sum!";
		};
		if (= n 2) (setq result (- a b));
		if (= n 3) (setq result (* a b));
		if (= n 4) (return 1);
		print result;
	}
};
