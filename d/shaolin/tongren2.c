// Room: /d/shaolin/tongren2.c

inherit ROOM;
inherit __DIR__"t_zhen";

int query_stage() { return 1; }
string query_out() { return "west"; }
string query_out_file() { return __DIR__"tongren3"; }

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ���谵��ɽ����ɽ�������м�������ȼ�յĻ�ѣ�
ӭ���ʯ����Ƕ��һ��ͭ��ӳ�Ż��������������д��

	[1;33m��ͭ �� �󡻵� һ ��[2;37;0m

LONG
	);

	setup();
}

int valid_leave(object who,string dir)
{
	mapping dirs = (["north":"south","south":"north","east":"west","west":"east"]);
	if(dir == dirs[query_out()])
		return notify_fail("\n��ֻ����һ��ߴ�������죬һ��ǿ��������������˻�����\n\n");

	return 1;
}
