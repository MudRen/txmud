// alias.c
// bye Find.

inherit F_CLEAN_UP;

private string show_global_alias();

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace, *vrbs,out;

	seteuid(getuid());

	if( !arg )
	{
		out = "\n        你目前能使用的替换简写如下：\n\n系统已提供的 alias：\n";
		out += show_global_alias();

		alias = me->query_all_alias();
		if( !sizeof(alias) )
		{
			out += "你目前没有自己设定 alias。\n";
			me->start_more(out);
			return 1;
		}

		else
		{
			out += "\n你目前自己设定的 alias 有：\n";
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				out += sprintf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
			me->start_more(out);
			return 1;
		}
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
		me->set_alias(arg, 0);
	else if( verb[0..4] == "alias" )
		return notify_fail("你不能将 \"alias\" 指令设定其他用途。\n");
	else if( verb=="" )
		return notify_fail("你要设什么 alias？\n");
	else
		return me->set_alias(verb, replace);

	write("Ok.\n");
	return 1;
}

private string show_global_alias()
{
	mapping g_alias;
	string *key,out = "";
	int i,n;

	if( !mapp(g_alias = ALIAS_D->query_global_alias()) )
		return "";

	if(!(n = sizeof(key = sort_array(keys(g_alias),1))))
		return "";

	for(i=0;i<n;i++)
		out += sprintf("%-9s = %-14s%s",
			key[i],
			g_alias[key[i]],
			!((i+1)%3)?"\n":""
			);
	return out[<1]=='\n'?out:(out+"\n");
}

int help (object me)
{
	write(@HELP
指令格式 : alias <欲设定之指令> <系统提供之指令>
 
有时系统所提供之指令需要输入很长的字串, 在使用
时(尤其是经常用到的)或许会感觉不方便, 此时你即
可用此一指令设定并替代原有之指令。
 
例如:
  'alias sc score' 会以 sc 取代 score 指令。

  'alias sc' 会消除 sc 这个替代指令。
             (如果你有设的话)

  'alias' 后面不加参数则列出你可以使用的所有的
          替代指令。格式为等号左侧为简写，右侧
          为系统命令。

 
其中可以用 $1, $2, $3 .... 来取代第一、第二、
第三个参数，或是 $* 取代所有的参数，

例如：
	'alias pb put $1 in $2'

则每当你打：
	pb bandage bag

就会取代成：
	put bandage in bag
	
HELP
);
        return 1;
}
