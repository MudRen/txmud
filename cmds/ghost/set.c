// set.c
// Modified by Find.
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	return "/cmds/usr/set"->main(me,arg);
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