// baiyu.c

inherit ITEM;

protected string master;

string query_master() { return master; }
void set_master(string id){
	if(!master)
		master = id;
}
void create()
{
	set_name("白壁玲珑玉", ({ "bai yu" }) );
	set_weight(100);
	set("value", 1);
	set("unit", "块");
	set("long", "这是一颗小指甲盖大的棕色果子。\n");
}
