#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class	Sample {

public:

	Sample(void);
	~Sample(void);

	int	getFoo(void)	const;
	void	setFoo(int v);

public:

	int	_foo;

};

#endif
