// Room: /d/shaolin/rroad3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µĹ�����������ȥ��Ϣ�ҵıؾ�֮�أ�����ÿ
����ν���������������ɮ�˴������߹������������Ƕ���
Ժ�������Ƕ��㳡����������ͨ����ʯ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"yongdao1",
  "south" : __DIR__"e_square",
  "east" : __DIR__"e_court",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
}

int valid_leave(object ob,string dir)
{
	if(!ob || !stringp(dir))
		return 1;

	if( (dir == "east" || dir == "e")
	&& ob->query("class") != "shaolin"
	&& !wizardp(ob) )
		return notify_fail("�������µ��Ӳ������ڣ���\n");

	else
		return ::valid_leave(ob,dir);
}