int i, sum = 0, n = 100;
for（i = 1; i <= n; i++）
{
	sum = sum + i;
}
printf（"%d", sum）;	


int sum = 0, n = 100;
sum = （1 + n） * n / 2;
printf（"%d", sum）;



int i, sum = 0, n = 100;	/* 執行1次 */
for（i = 1; i <= n; i++）	/* 執行了n+1次 */
{
	sum = sum + i;			/* 執行n次 */
}
printf（"%d", sum）;			/* 執行1次 */


int sum = 0,n = 100;		/* 執行一次 */
sum = (1 + n) * n / 2;		/* 執行一次 */
printf（"%d", sum）;		/* 執行一次 */


int i, j, x = 0, sum = 0, n = 100;	/* 執行一次 */
for（i = 1; i <= n; i++）
{
	for （j = 1; j <= n; j++）
	{
		x++;						/* 執行n×n次 */
		sum = sum + x;
	}
}
printf（"%d", sum）;				/* 執行一次 */


int sum = 0,n = 100;		/* 執行一次 */
sum = (1 + n) * n / 2;		/* 執行一次 */
printf（"%d", sum）;		/* 執行一次 */


int sum = 0, n = 100;		/* 執行1次 */
sum = （1+n）*n/2;			/* 執行第1次 */
sum = （1+n）*n/2;			/* 執行第2次 */
sum = （1+n）*n/2;			/* 執行第3次 */
sum = （1+n）*n/2;			/* 執行第4次 */
sum = （1+n）*n/2;			/* 執行第5次 */
sum = （1+n）*n/2;			/* 執行第6次 */
sum = （1+n）*n/2;			/* 執行第7次 */
sum = （1+n）*n/2;			/* 執行第8次 */
sum = （1+n）*n/2;			/* 執行第9次 */
sum = （1+n）*n/2;			/* 執行第10次 */
printf（"%d",sum）;		    /* 執行1次 */


int i;
for（i = 0; i < n; i++）
{
	/* 時間復雜度為O(1)的程式步驟序列 */
}


int count = 1;
while count < n）
{
	count = count * 2;
	/* 時間復雜度為O(1)的程式步驟序列 */
}


int i,j;
for（i = 0; i < n; i++）
{
	for（j = 0; j < n; j++）                       
	{                                      
		/* 時間復雜度為O(1)的程式步驟序列 */
	}                                      
}

int i,j;
for（i = 0; i < m; i++）
{
	for（j = 0; j < n; j++）                
	{                                      
		/* 時間復雜度為O(1)的程式步驟序列 */
	}                                      
}

int i,j;
for（i = 0; i < n; i++）
{
	for（j = i; j < n; j++）  /* 注意j = i而不是0 */
	{                                      
		/* 時間復雜度為O(1)的程式步驟序列 */
	}                                      
}


int i,j;
for（i = 0; i < n; i++）
{
	function（i）;
}


void function（int count）
{
	print（count）;
}


void function（int count）
{
	int j;
	for（j = count; j < n; j++）                       
	{                                      
		/* 時間復雜度為O(1)的程式步驟序列 */
	}    
} 

n++;  						/* 執行次數為1 */
function（n）;	 			/* 執行次數為n */
int i,j;					
for（i = 0; i < n; i++）		/* 執行次數為n×n */
{
	function（i）;
}
for（i = 0; i < n; i++）		/* 執行次數為n（n + 1）/2 */
{
	for （j = i; j < n; j++）                       
	{                                      
		/* 時間復雜度為O(1)的程式步驟序列 */
	}                                      
}


