int i, sum = 0, n = 100;
for�]i = 1; i <= n; i++�^
{
	sum = sum + i;
}
printf�]"%d", sum�^;	


int sum = 0, n = 100;
sum = �]1 + n�^ * n / 2;
printf�]"%d", sum�^;



int i, sum = 0, n = 100;	/* ����1�� */
for�]i = 1; i <= n; i++�^	/* ����Fn+1�� */
{
	sum = sum + i;			/* ����n�� */
}
printf�]"%d", sum�^;			/* ����1�� */


int sum = 0,n = 100;		/* ����@�� */
sum = (1 + n) * n / 2;		/* ����@�� */
printf�]"%d", sum�^;		/* ����@�� */


int i, j, x = 0, sum = 0, n = 100;	/* ����@�� */
for�]i = 1; i <= n; i++�^
{
	for �]j = 1; j <= n; j++�^
	{
		x++;						/* ����n��n�� */
		sum = sum + x;
	}
}
printf�]"%d", sum�^;				/* ����@�� */


int sum = 0,n = 100;		/* ����@�� */
sum = (1 + n) * n / 2;		/* ����@�� */
printf�]"%d", sum�^;		/* ����@�� */


int sum = 0, n = 100;		/* ����1�� */
sum = �]1+n�^*n/2;			/* �����1�� */
sum = �]1+n�^*n/2;			/* �����2�� */
sum = �]1+n�^*n/2;			/* �����3�� */
sum = �]1+n�^*n/2;			/* �����4�� */
sum = �]1+n�^*n/2;			/* �����5�� */
sum = �]1+n�^*n/2;			/* �����6�� */
sum = �]1+n�^*n/2;			/* �����7�� */
sum = �]1+n�^*n/2;			/* �����8�� */
sum = �]1+n�^*n/2;			/* �����9�� */
sum = �]1+n�^*n/2;			/* �����10�� */
printf�]"%d",sum�^;		    /* ����1�� */


int i;
for�]i = 0; i < n; i++�^
{
	/* �ɶ��_���׬�O(1)���{���B�J�ǦC */
}


int count = 1;
while count < n�^
{
	count = count * 2;
	/* �ɶ��_���׬�O(1)���{���B�J�ǦC */
}


int i,j;
for�]i = 0; i < n; i++�^
{
	for�]j = 0; j < n; j++�^                       
	{                                      
		/* �ɶ��_���׬�O(1)���{���B�J�ǦC */
	}                                      
}

int i,j;
for�]i = 0; i < m; i++�^
{
	for�]j = 0; j < n; j++�^                
	{                                      
		/* �ɶ��_���׬�O(1)���{���B�J�ǦC */
	}                                      
}

int i,j;
for�]i = 0; i < n; i++�^
{
	for�]j = i; j < n; j++�^  /* �`�Nj = i�Ӥ��O0 */
	{                                      
		/* �ɶ��_���׬�O(1)���{���B�J�ǦC */
	}                                      
}


int i,j;
for�]i = 0; i < n; i++�^
{
	function�]i�^;
}


void function�]int count�^
{
	print�]count�^;
}


void function�]int count�^
{
	int j;
	for�]j = count; j < n; j++�^                       
	{                                      
		/* �ɶ��_���׬�O(1)���{���B�J�ǦC */
	}    
} 

n++;  						/* ���榸�Ƭ�1 */
function�]n�^;	 			/* ���榸�Ƭ�n */
int i,j;					
for�]i = 0; i < n; i++�^		/* ���榸�Ƭ�n��n */
{
	function�]i�^;
}
for�]i = 0; i < n; i++�^		/* ���榸�Ƭ�n�]n + 1�^/2 */
{
	for �]j = i; j < n; j++�^                       
	{                                      
		/* �ɶ��_���׬�O(1)���{���B�J�ǦC */
	}                                      
}


