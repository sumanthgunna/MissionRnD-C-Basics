/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int validate(char* dob1, char* dob2);
int daycheck(char *dob1, char *dob2);
int monthcheck(char *dob1, char *dob2);
int yearcheck(char *dob1, char *dob2);
int leapyearcheck(char *dob1, char * dob2);
int compare(char *dob1, char* dob2);
int isOlder(char *dob1, char*dob2);

int isOlder(char *dob1, char*dob2) {
	int q, p;
	q = validate(dob1, dob2);
	if (q == -1)
	{
		return -1;
	}
	else
	{
		p = compare(dob1, dob2);
		return p;
	}
}
int validate(char* dob1, char* dob2)
{
	int p = 0, q, r, s, m = 1;
	if ((dob1[2] != '-') || (dob1[5] != '-') || (dob2[2] != '-') || (dob2[5] != '-'))
	{
		p = -1;

	}
	q = daycheck(dob1, dob2);
	r = monthcheck(dob1, dob2);
	s = yearcheck(dob1, dob2);
	m = leapyearcheck(dob1, dob2);
	if ((p == -1) || (q == -1) || (r == -1) || (s == -1) || (m == -1))
	{
		return -1;
	}
	else
	{
		return 1;
	}

}
int daycheck(char *dob1, char *dob2)
{
	int i, flag = 0, p, q;
	for (i = 0; i < 2; i++)
	{
		p = dob1[i];
		q = dob2[i];
		if (i == 0)
		{
			if (((p >= 48) && (p <= 51)) && ((q >= 48) && (q <= 51)))
			{
				flag++;
			}
		}
		else
		{
			if (((p >= 48) && (p <= 57)) && ((q >= 48) && (q <= 57)))
			{
				flag++;
			}

		}

	}
	if (flag != 2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int monthcheck(char *dob1, char *dob2)
{
	int i, flag = 0, p, q, m1, m2;
	for (i = 3; i < 5; i++)
	{
		p = dob1[i];
		q = dob2[i];
		if (i == 3)
		{
			if (((p >= 48) && (p <= 49)) && ((q >= 48) && (q <= 49)))
			{
				flag++;
			}
		}
		else
		{
			if (((p >= 48) && (p <= 57)) && ((q >= 48) && (q <= 57)))
			{
				flag++;
			}

		}


	}
	m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0') * 1;
	m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0') * 1;
	if (((m1<0) || (m1>12)) || ((m2<0) || (m2>12)))
	{
		flag--;
	}
	if (flag != 2)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}
int yearcheck(char *dob1, char *dob2)
{
	int i, flag = 0, p, q;
	for (i = 6; i < 10; i++)
	{
		p = dob1[i];
		q = dob2[i];
		if (((p >= 48) && (p <= 57)) && ((q >= 48) && (q <= 57)))
		{
			flag++;
		}
	}

	if (flag != 4)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}
int leapyearcheck(char *dob1, char * dob2)
{
	int y1, y2, m1, m2, d1, d2, p = -1;

	y1 = (dob1[9] - '0') * 1 + (dob1[8] - '0') * 10 + (dob1[7] - '0') * 100 + (dob1[6] - '0') * 1000;
	y2 = (dob2[9] - '0') * 1 + (dob2[8] - '0') * 10 + (dob2[7] - '0') * 100 + (dob2[6] - '0') * 1000;
	m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0') * 1;
	m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0') * 1;
	d1 = (dob1[0] - '0') * 10 + (dob1[1] - '0') * 1;
	d2 = (dob2[0] - '0') * 10 + (dob2[1] - '0') * 1;
	if (((y1 % 4 == 0) && (d1 > 29) && (m1 == 2)) || ((y2 % 4 == 0) && (d2 > 29) && (m2 == 2)))
	{
		return -1;
	}
	else
	{
		if (((m1 == 2) && (d1 > 28) && (y1 % 4 != 0)) || ((m2 == 2) && (d2 > 28) && (y1 % 4 != 0)))
		{
			return -1;
		}
		else
		{
			return 1;
		}

	}
}
int compare(char *dob1, char* dob2)
{
	int y1, y2, m1, m2, d1, d2, p = -1;

	y1 = (dob1[9] - '0') * 1 + (dob1[8] - '0') * 10 + (dob1[7] - '0') * 100 + (dob1[6] - '0') * 1000;
	y2 = (dob2[9] - '0') * 1 + (dob2[8] - '0') * 10 + (dob2[7] - '0') * 100 + (dob2[6] - '0') * 1000;
	if (y1 == y2)
	{
		m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0') * 1;
		m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0') * 1;
		if (m1 == m2)
		{
			d1 = (dob1[0] - '0') * 10 + (dob1[1] - '0') * 1;
			d2 = (dob2[0] - '0') * 10 + (dob2[1] - '0') * 1;
			if (d1 == d2)
			{
				p = 0;
			}
			else
			{
				if (d1 < d2)
				{
					return 1;
				}
				else
				{
					return 2;
				}
			}

		}
		else
		{
			if (m1 < m2)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	else
	{
		if (y1 < y2)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (p == 0)
	{
		return 0;
	}
}
