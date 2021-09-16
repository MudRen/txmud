// path.c
// Modified by Find.

nomask string user_cwd(string name)
{
   return (WIZ_DIR + name);
}

nomask string user_path(string name)
{
   return (user_cwd(name) + "/");
}

nomask string resolve_path(string curr, string new_path)
{
	int i,n;
	string *tmp;
	object who = this_player();

	if(!curr)
		curr = "/";

	if(!new_path || (new_path == "."))
		return curr;

	if((new_path == "here") && who)
	{
		object env;
		if(!env = environment(who))
			return "/";
		return file_name(env) + ".c";
	}

	new_path = replace_string(new_path, "~", who?user_path(geteuid(who)):"");
	if(new_path[0] != '/')
	{
		if( sizeof(curr) && (curr[<1] != '/') )
			new_path = curr + "/" + new_path;
		else if(stringp(curr))
			new_path = curr + new_path;
	}

	tmp = explode(new_path,"/") - ({""});
	if(!sizeof(tmp))
		return "/";

	i = 0;
	while(i<(n = sizeof(tmp)))
	{
		if(tmp[i] == "..")
		{
			if(i < 2)
			{
				if(i+1 < n)
				{
					tmp = tmp[i+1..];
					i=0;
					continue;
				}
				tmp = ({});
				break;
			}
			else if(i+1 <n)
				tmp = tmp[0..i-2] + tmp[i+1..];
			else
				tmp = tmp[0..i-2];
		}
		else
		{
			while(sizeof(tmp[i][<1]) && (tmp[i][<1] == '.'))
			{
				if(tmp[i] == ".")
					tmp[i] = "";
				else
					tmp[i] = tmp[i][0..<2];
			}
		}
		i++;
	}

	tmp -= ({""});
	return "/" + implode(tmp,"/");
}

nomask int in_same_dir(string file1,string file2)
{
	string dir_a = "", dir_b = "", *dirs;
	int i;

	if(!stringp(file1) || !stringp(file2))
		return 0;

	dirs = explode(file1, "/");

	if(sizeof(dirs) < 2)
		dir_a = "/";
	else
	{
		for(i=0;i<sizeof(dirs)-1;i++)
		{
			dir_a += "/";
			dir_a += dirs[i];
		}
	}

	dirs = explode(file2, "/");
	if(sizeof(dirs) < 2)
		dir_b = "/";
	else
	{
		for(i=0;i<sizeof(dirs)-1;i++)
		{
			dir_b += "/";
			dir_b += dirs[i];
		}
	}

	if(dir_a == dir_b)
		return 1;
	else
		return 0;
}
