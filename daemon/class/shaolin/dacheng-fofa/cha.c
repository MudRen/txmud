// cha.c
// by Find.

string time_string(int time)
{
	int day,hour,min;
	string retn = "";

	if(!intp(time) || !time)
		return retn;

	min = time%60;
	time /= 60;
	hour = time%24;
	time /= 24;
	day = time;

	if(day)
		retn += sprintf("%s��",chinese_number(day));
	if(hour)
	{
		retn += sprintf("%sСʱ",chinese_number(hour));
		if(day)
			return retn;
	}
	if(min)
		retn += sprintf("%s��",chinese_number(min));

	return retn;
}

int conjure(object me)
{
	mapping where;
	int time;
	string out = "";

	if(!objectp(me || (me->query("class") != "shaolin")))
		return 0;

	if(!mapp(where = me->query("family/fofa")) || !sizeof(where))
		return notify_fail("��ġ��������ۡ�Ŀǰû���κη���\n");

	time = time();

	foreach(string fname,int t in where)
	{
		object room;
		string f;

		if( (t - time) <= 0 )
		{
			me->delete("family/fofa/"+fname);
			continue;
		}

		f = replace_string(fname,"&","/");
		room = find_object(f);
		if(!room)
			room = load_object(f);
		if(!room)
		{
			me->delete("family/fofa/"+fname);
			continue;
		}

		out += sprintf("%-20s�ɳ���ʱ�䣺%s\n","��"+room->query("short")+"��",time_string(t-time));
	}

	if(out == "")
		return notify_fail("��ġ��������ۡ�Ŀǰû���κη���\n");

	write(sprintf("��Ŀǰ���������ĵط��У�\n%s\n",out));
	return 1;
}
