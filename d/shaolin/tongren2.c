// Room: /d/shaolin/tongren2.c

inherit ROOM;
inherit __DIR__"t_zhen";

int query_stage() { return 1; }
string query_out() { return "west"; }
string query_out_file() { return __DIR__"tongren3"; }

void create()
{
	set("short", "山洞");
	set("long", @LONG
这里是一个昏暗的山洞，山洞壁上有几根熊熊燃烧的火把，
迎面的石板上嵌着一块铜牌映着火光闪闪发亮，上写着

	[1;33m『铜 人 阵』第 一 关[2;37;0m

LONG
	);

	setup();
}

int valid_leave(object who,string dir)
{
	mapping dirs = (["north":"south","south":"north","east":"west","west":"east"]);
	if(dir == dirs[query_out()])
		return notify_fail("\n你只听到一阵“叽噶”乱响，一股强劲的阴风把你推了回来。\n\n");

	return 1;
}
