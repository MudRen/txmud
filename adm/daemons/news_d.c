//	/adm/daemons/news_d.c
// ������Դ�� TMI-2
// by Find.

#include <login.h> 
#include <ansi.h>
#include <origin.h>

#define	HEADER	1

// ���� news ��������.
#define ALIVE   86400
#define W_ALIVE	86400*5
#define G_ALIVE	86400*7

inherit F_NATURE;

private int load_news_list();
private int sweep_save(object user);
private string add_message(string file);
private string make_header(string date);
private int check_read_num(string file, int view, object user);
private string make_content(string type, object user);

private mapping w_list, p_list, g_list;
private string *files;
 
void create()
{
	seteuid(getuid());
	load_news_list();
}

private int load_news_list()
{
	string type,date,*dir;
	int view, loop,n;

	if( origin() != ORIGIN_LOCAL )
		return 0;

	w_list = ([ ]);
	p_list = ([ ]);
	g_list = ([ ]);
	files = ({ });

	dir = get_dir(NEWS_DIR);

	if(!dir || !(n = sizeof(dir)))	// no news files
		return 0;

	for(loop=0; loop<n; loop++)
	{
		if(!dir || sscanf(dir[loop],"%s.%s.%d", date, type, view) != 3)
			continue;

		if(type == "w")		// wizards news
			w_list[ dir[loop] ] = ([ "date" : date, "type" : type, "view" : view ]);
		else if(type == "p")	// player news
			p_list[ dir[loop] ] = ([ "date" : date, "type" : type, "view" : view ]);
		else			// general news
			g_list[ dir[loop] ] = ([ "date" : date, "type" : type, "view" : view ]);
		files += ({ dir[loop] });
	}

	return 1;
}

// Display the news to user when called during login.
void
display_news(object user)
{
	if(!objectp(user) || !userp(user))
		return ;
	if(user->query("new_begin"))
		return;
	if(user->query("hushlogin"))
		return;
	else
		call_out("display_news_to_user",2,user);
}

private void
display_news_to_user(object user)
{
	string output = "";
 
	if(!objectp(user) || !userp(user))
		return;

	if(wizardp(user))
		output += make_content("w",user);

	output += make_content("g",user);
	output += make_content("p",user);

	sweep_save(user);

	user->start_more(output);
	return;
}
 
// Check to see how many times the news item has been
// read by this user and save updated count.
private int check_read_num(string file, int view, object user)
{
	mapping store;

	store = user->query("news_save");
	if(!store)
		store = ([ ]);

	if(store[file])
	{
		if(store[file] == view)
			return 0;	// Viewed required times

		store[file]++;
		user->set("news_save", store);
		return 1;
	}

	store[file] = 1;
	user->set("news_save", store);

	return  1;
}
 
private int sweep_save(object user)
{
	mapping save;
	string *tmp;
	int loop,n;

	save = (mapping)user->query("news_save");
	if(!save || !sizeof(save))
		return 0;

	tmp = keys( save );
	if(!tmp || !sizeof(tmp))
		return 0;

	n = sizeof(tmp);
	for(loop=0; loop<n; loop++)
		if(member_array(tmp[loop], files) == -1)
			map_delete(save, tmp[loop]);

	user->set("news_save", save);

	return 1;
}

private int sort_file_name(string file1,string file2)
{
	int y1,m1,d1,s1, y2,m2,d2,s2;

	if(!stringp(file1) || !stringp(file2))
		return 0;

	if(sscanf(file1,"y%dm%dd%ds%d.%*s",y1,m1,d1,s1) != 5)
		return 0;
	if(sscanf(file2,"y%dm%dd%ds%d.%*s",y2,m2,d2,s2) != 5)
		return 0;

	if(y1 < y2)
		return -1;
	else if(y1 > y2)
		return 1;

	if(m1 < m2)
		return -1;
	else if(m1 > m2)
		return 1;

	if(d1 < d2)
		return -1;
	else if(d1 > d2)
		return 1;

	if(s1 < s2)
		return -1;
	else if(s1 > s2)
		return 1;
	else
		return 0;
}

private string make_content(string type, object user)
{
	string output = "", title, no_news_msg, *temp_files;
	int loop, flag, n;
	mapping temp_list;

	if(type == "w")
	{
		title = "\n" + REV + "�� ��綯̬ ��" + NOR + "\n\n";
		no_news_msg = sprintf("�� %s���̫ƽ���� ��\n\n",MUD_NAME);
		temp_list = w_list;
	}

	else if(type == "p")
	{
		title = "\n" + REV + "�� ������̬ ��" + NOR + "\n\n";
		no_news_msg = sprintf("�� %s������ƽ�˾� ��\n\n",MUD_NAME);
		temp_list = p_list;
	}

	else
	{
		title = "\n" + REV + "�� ����ͨ�� ��" + NOR + "\n\n";
		no_news_msg = "";
		temp_list = g_list;
	}

	flag = 0;
	temp_files = sort_array(keys(temp_list),"sort_file_name",this_object());
	n = sizeof(temp_files);

	for(loop=0; loop<n; loop++)
	{
		if(temp_list[temp_files[loop]]["view"] == 0)
		{
			if(HEADER)  
			output += make_header(temp_list[temp_files[loop]]["date"]);
			output += sprintf("%s%s%s",type=="g"?HIY:"",add_message(temp_files[loop]),type=="g"?NOR:"");
			flag++;
			continue;
		}

		if(check_read_num(temp_files[loop], temp_list[temp_files[loop]]["view"], user))
		{
			if(HEADER)
			output += make_header(temp_list[temp_files[loop]]["date"]);
			output += sprintf("%s%s%s",type=="g"?HIY:"",add_message(temp_files[loop]),type=="g"?NOR:"");
			flag++;
			continue;
		}
	}

	if(!flag)
		return no_news_msg;
	else
		return title + output;

}

// Add news file contents to displaying output
private string add_message(string file)
{
	return (file_size(NEWS_DIR + file)>0)?read_file( NEWS_DIR + file) + "\n":"\n";
}
 
private string make_header(string date)
{
	string header;
	int year,month,day;

	sscanf(date,"y%dm%dd%ds%*d",year,month,day);

	// Add time stamp as header
	header = sprintf("%s����%s��%s��%s�գ�\n",MUD_NAME,chinese_number(year),
		chinese_number(month),chinese_number(day));

	return header;
}
 
void fresh_news_dir()
{
	int time = time(),i,n,news_alive;
	mixed dirs;
	string type;

	dirs = get_dir(NEWS_DIR,-1);

	if( !(n = sizeof(dirs)) )
		return;

	for(i=0;i<n;i++)
	{
		sscanf(dirs[i][0],"%*s.%s.%*d", type);
		switch (type)
		{
			case "w":
				news_alive = W_ALIVE;
				break;
			case "g":
				news_alive = G_ALIVE;
				break;
			default:
				news_alive = ALIVE;
		}

		if( (time - (int)dirs[i][2]) >= news_alive )
			rm( NEWS_DIR + dirs[i][0] );
	}

	load_news_list();
	return;
}

int add_news_item(string content,string type, int n)
{
	int year,month,day,second;
	string fname;

        if(previous_object()
        && (geteuid(previous_object()) != ROOT_UID)
        && !sscanf(base_name(previous_object()), NPC_DIR"%*s") )
		return 0;

	if(!stringp(content) || content == "")
		return 0;

	if(!stringp(type) || member_array(type,({"w","p","g"})) == -1 )
		return 0;

	if(!intp(n))
		return 0;

	year = query_year();
	month = query_month();
	day = query_day_in_month();
	second = query_time();

	fname = sprintf("y%dm%dd%ds%d.%s.%d",year,month,day,second,type,n);

	if(!write_file(NEWS_DIR+fname,content))
		return 0;

	else
	{
		load_news_list();
		return 1;
	}
}
