// set.c
// Modified by Find.

#define MAX_ENV_VARS	20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
	int i;
	string term, *terms, *w_set,*p_set;
	mixed data;
	mapping env;

	w_set = ({"msg_home","msg_min","msg_mout","msg_clone","msg_dest","invisibility", "immortal"});
	p_set = ({ "brief","wimpy","no_teach","no_accept","no_tell","no_emote","mute" });

	if( me != this_player(1) ) return 0;
 
	env = me->query("env");
 
	if( !arg || arg=="" )
	{
		if( !mapp(env) || !sizeof(env) )
			write("你目前没有设定任何环境变量。\n");
		else
		{
			write("你目前设定的环境变量有：\n");
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}

	if( sscanf(arg, "%s %s", term, data)!=2 )
	{
		term = arg;
		data = "YES";
	}

	if(term[<1] == '/')
		term = term[0..<2];
 
	if( term && term!="" )
	{
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("你设的环境变量太多了，请先用 unset 删掉几个吧。\n");
		if( member_array(term, w_set) == -1 && member_array(term, p_set) == -1)
			return notify_fail("目前没有定义 "+term+" 这个环境变量，\n请查阅 help settings"+
			((wiz_level(me))?" & wiz_settings ":" ")+"后重新设定。\n");
		sscanf(data, "%d", data);
		if(!wizardp(me) && (member_array(term, w_set) != -1))
			return notify_fail("只有巫师能设定这个环境变量。\n");
		me->set("env/" + term, data);
		printf("设定环境变量：%s = %O\n", term, data);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
指令格式：set <变数名> [<变数值>]
 
这个指令让你设定一些环境变数，不加参数时会显示你目前设定的环境变数，不指定
变数值，则内定值为 "YES"。
 
取消变数设定请用 unset 指令。
 
至於有哪些环境变数可以设定，请见 help settings。
TEXT
	);
	return 1;
}
