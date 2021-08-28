/* getbits: получает п бит, начиная с р-й позиции */
unsigned getbits (unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
