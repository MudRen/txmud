// ls.c
// Modified by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j, w, col, ll;
	string dir,out;
	mixed *file;
        mixed *exclude;

	if(arg)
	{
		if(arg == "-l")
		{
			ll = 1;
			arg = 0;
		}
		else
			if(sscanf(arg,"-l %s",arg))
				ll = 1;
	}

	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )
		dir += "/";

	file = get_dir(dir, -1);

	if( !sizeof(file) )
	{
		if(file_size(dir) == -2)
			return notify_fail(sprintf("Ŀ¼ \"%s\" �ǿյġ�\n",dir));
		else
			return notify_fail("û�����Ŀ¼��\n");
	}

        exclude = filter_array( file, "filter_hide", this_object(), this_player(1) );
        file = exclude;

	if(!ll)
	{
		i = sizeof(file);
		w = 0;
	
		while(i--)
		{
			if (file[i][1]==-2)
				file[i][0] += "/";
			if (strlen(file[i][0])>w)
				w = strlen(file[i][0]) + 1;
		}
	}

	out = sprintf("Ŀ¼��%s \n", dir);

	col = 70 / (w+6);

	if(j = sizeof(file))
	{
		if(ll)
			for(i=0; i<j; i++)
				out += sprintf("%-25s%s    %s\n",
					file[i][1]==-2?
						file[i][0]+"/":
						file[i][0]+(
							find_object(dir + file[i][0])? "*":""
						),
					file[i][1]==-2?
						sprintf("%|13s","<DIR>"):
						sprintf("%7d bytes",file[i][1]),
					ctime(file[i][2])
					);

		else
			for(i=0; i<j; i++)
				out += sprintf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
					file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
					((i+1)%col)?"  ":"\n");
	}

	else
		write("    û���κε�����\n");

	out += "\n";
	me->start_more(out);
	
	return 1;	
}

int filter_hide(mixed *lll,object me)
{
        if( (lll[0] == "syslog") && (lll[1] == -2) )
        {
                if(wiz_level(me) < wiz_level("(arch)") )
                        return 0;
        }
        return 1;
}


int help(object me)
{
	write(@HELP
ָ���ʽ: ls [-l] [<·����>]
 
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ�����ǰ���ʾ * �ŵ����Ѿ�����������

-l �����ɻ�õ�����һЩ��ϸ�����

��:
'ls /' ���г�����λ�ڸ�Ŀ¼�µĵ�������Ŀ¼.

HELP
	);
	return 1;
}
