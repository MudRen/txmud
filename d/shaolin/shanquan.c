// Room: /d/shaolin/shanquan.c

inherit ROOM;

void create()
{
	set("short", "ɽȪ");
	set("long", @LONG
����վ��һ�����ɵ�С�ٲ�ǰ�棬�峺��ɽȪ��ɽ����һк
���£���������γ�һ���丵�СϪ��������ɽ�����ʡ���˵��
���µĺ���ÿ�춼�������ˮ(dashui)��
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"shandao5",
]));

	setup();
}

void init()
{
	add_action("do_dashui","dashui");
}

int do_dashui()
{
	object ob;

	ob = present("shui tong",this_player());
	if(!ob)
		return 0;

	message_vision("$N����ˮͰ��ɽȪ�����һͰȪˮ��\n",this_player());
	ob->delete("no_water");
	return 1;
}