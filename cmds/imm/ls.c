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
			return notify_fail(sprintf("目录 \"%s\" 是空的。\n",dir));
		else
			return notify_fail("没有这个目录。\n");
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

	out = sprintf("目录：%s \n", dir);

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
		write("    没有任何档案。\n");

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
指令格式: ls [-l] [<路径名>]
 
列出目录下所有的子目录及档案, 如果没有指定目录, 则列出所在目录
的内容，所列出的档案中前面标示 * 号的是已经载入的物件。

-l 参数可获得档案的一些详细情况。

例:
'ls /' 会列出所有位于根目录下的档案及子目录.

HELP
	);
	return 1;
}
