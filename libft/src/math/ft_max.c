int	fmaxi(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	fmaxi3(int x, int y, int z)
{
	return (fmaxi(x, fmaxi(y, z)));
}
