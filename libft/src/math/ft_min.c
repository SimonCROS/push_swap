int	fmini(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	fmini3(int x, int y, int z)
{
	return (fmini(x, fmini(y, z)));
}
