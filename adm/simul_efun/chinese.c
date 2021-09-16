
nomask string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

nomask int is_chinese(string str)
{
	if( strlen(str)>=2 && str[0] > 160 && str[0] < 255 ) return 1;
	return 0;
}

nomask string chinese_season(int i)
{
        return CHINESE_D->chinese_season(i);
}

nomask string chinese_value(int amount)
{
	return CHINESE_D->chinese_value(amount);
}

nomask string valid_chinese(string str)
{
	int i;
	string tmp;

	if( !stringp(str) || !strlen(str) )
		return 0;

	tmp = clr_ansi(str);
	i = strlen(tmp);

	while(i--)
	{
		int section;

                if( tmp[i]<128 )
			return 0;	// 非汉字

		if( i%2==0 )
		{
			section = tmp[i] - 160;

			if( (section < 16)
			|| (section > 87) )
				return 0;	// 非常用汉字
		}
	}

	return tmp;
}
